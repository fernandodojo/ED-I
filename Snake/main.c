#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include "snake.h"


int main(void) {
	Snake *snk = criarcobra(10); 		//criação da struck cobra
	Fruta *fruta = criarfruta();		//criacao da struct fruta
	int altura=26; 									//dimensao da tela
	int largura=52;									//dimensao da tela
	char input;											//entrada de tecla
	int i, j;   
	char mat[altura][largura];			//mapa do jogo	
	bool gameover=false;						//estado do jogo		
	int topoX = snk->t->x;
	int topoY = snk->t->y;
	int aux = snk->qtd;
	
	 

	//DESENHO DO MAPA
	for(int i =0; i<altura; i++){
		for(int j=0; j<largura; j++){
			mat[i][j]='.';			
		}
	}	
			
	do{
		srand(time(NULL));
		input = getchar();

		
		//DEFINIÇÃO DE TIPO
		mat[fruta->y][fruta->x] = 'O';	
		

		//MUDANÇA DE DIREÇÃO SE A NOVA DIREÇÃO FOR DIFERENTE DA ATUAL
		if (snk->direcao != 'a' && input == 'a'){			
			while(snk->qtd>1){    //realiza o encolhimento 
				desempilhar(snk);
			}
			snk->direcao='a';			//define a nova direção
			for(int i=0; i<=aux; i++){ // apaga traços da antiga direção da cobra
					mat[topoY+i][topoX]='.';	
					mat[topoY-i][topoX]='.';													
			}					
		}
		else if (snk->direcao!='d' && input == 'd'){
			while(snk->qtd>1){		//realiza o encolhimento 
				desempilhar(snk);
			}			
			snk->direcao='d';			//define a nova direção
			for(int i=0; i<=aux; i++){	// apaga traços da antiga direção da cobra
				mat[topoY+i][topoX]='.';	
				mat[topoY-i][topoX]='.';					
			}
		}
		else if (snk->direcao != 'w' && input == 'w'){
			while(snk->qtd>1){		//realiza o encolhimento 
				desempilhar(snk);
			}
			snk->direcao='w';     //define a nova direção
			for(int i=0; i<=aux; i++){	// apaga traços da antiga direção da cobra
				mat[topoY][topoX-i]='.';	
				mat[topoY][topoX+i]='.';					
			}
		}
		else if (snk->direcao!='s' && input == 's'){
			while(snk->qtd>1){		//realiza o encolhimento 
				desempilhar(snk);
			}						
			snk->direcao='s';			//define a nova direção
			for(int i=0; i<=aux; i++){	// apaga traços da antiga direção da cobra
				mat[topoY][topoX-i]='.';	
				mat[topoY][topoX+i]='.';					
			}
		}		
		

		if(snk->direcao == 'd'){	//permite o continuo movimento da cobra e empilhamento nos casos de mudança de direção
			topoX++;
			if(snk->qtd<aux){
				empilhar(snk);
			}			
		}else if(snk->direcao == 'a'){	//permite o continuo movimento da cobra e empilhamento nos casos de mudança de direção
			topoX--;
			if(snk->qtd<aux){
				empilhar(snk);
			}		
		}else if(snk->direcao == 'w'){	//permite o continuo movimento da cobra e empilhamento nos casos de mudança de direção	
			topoY--;
			if(snk->qtd<aux){
				empilhar(snk);
			}					
		}else if(snk->direcao == 's'){	//permite o continuo movimento da cobra e empilhamento nos casos de mudança de direção
			topoY++;
			if(snk->qtd<aux){
				empilhar(snk);
			}
		}

		//MOVIMENTAÇÃO DA COBRA		
		if (snk->direcao == 'a'){
			for(int i=0; i<snk->qtd; i++){			
				mat[topoY][topoX+i]= '@';	
				mat[topoY][topoX+i+1]='.'; //apaga as coordenadas apos a ultima posicao da cobra
			}
		}
		if (snk->direcao == 'd'){							
			for(int i=0; i<snk->qtd; i++){
				mat[topoY][topoX-i]= '@';
				mat[topoY][topoX-i-1]='.';	//apaga as coordenadas apos a ultima posicao da cobra
			}										
		}		
		if (snk->direcao == 'w'){				
			for(int i=0; i<snk->qtd; i++){						
				mat[topoY+i][topoX]= '@';
				mat[topoY+i+1][topoX]='.';	//apaga as coordenadas apos a ultima posicao da cobra
			}													
		}
		if (snk->direcao == 's'){				
			for(int i=0; i<snk->qtd; i++){
				mat[topoY-i][topoX]= '@';
				mat[topoY-i-1][topoX]='.';	//apaga as coordenadas apos a ultima posicao da cobra
			}				
		}		
		

		//COLISAO COBRA E FRUTA
		if(topoX==fruta->x && topoY==fruta->y ){
			empilhar(snk);	//crescimento no caso de mesma coordenada da comida
			snk->score++;		//soma de pontos
			aux = snk->qtd;	//salva o tamanho da cobra
			fruta->x = 5 +(rand() % (largura-5)); //gera nova coordenada de fruta
			fruta->y = 5 +(rand() % (altura-5));	//gera nova coordenada de fruta
					
		}


		//COLISÃO COM PAREDE
		if(topoX <= 0 || topoY <=0 || topoX>=largura || topoY>=altura){		
			int k=0;
			while(k<5){
				desempilhar(snk);
				k++;
			}
			aux = snk->qtd;	
		}

		if(snk->qtd<=0){
			gameover=true;
		}
		
		
		//IMPRESSAO DO JOGO
		for(i =0; i<altura; i++){
			for(j=0; j<largura; j++){				
				if(i==altura-1|| j ==0 || i==0 || j==largura-1){
					mat[i][j]='#';
				}				
				printf("%c", mat[i][j]);
			}
			printf("\n");
		}


		printf("FRUTA / TOPO \n");
		printf("X / Y || X / Y \n");
		printf("%i/%i |",fruta->x, fruta->y);
		printf("| %i/%i |",topoX, topoY);
		
		printf("  SCORE: %i", snk->score);
		printf("\n\n");

		
		printf("\n");
		listar(snk);
		printf("  TAMANHO: %i\n\n\n", snk->qtd);
		
	}while(gameover==false);
	printf("GAMEOVER\n");
	printf("GAMEOVER\n");
	printf("GAMEOVER\n");
	printf("GAMEOVER\n");	


  return 0;
}