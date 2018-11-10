#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

Snake *criarcobra(int max){
	if(max<=0){
		return NULL;
	}
	Snake *snake = (Snake*)malloc(sizeof(Snake));
	if(snake==NULL){
		return NULL;
	}
	
	snake->dado = (char*)malloc(max*sizeof(char));

	snake->t = (topo*)malloc(sizeof(topo));
	snake->f = (fim*)malloc(sizeof(fim));
	
	if(snake==0 || snake->dado==0){
		free(snake);
		snake=NULL;
		return snake;
	}
	snake->direcao = 'd';	
	snake->t->x = 13;
	snake->t->y = 13;
	snake->max=max;
	snake->topo=0;
	snake->score=0;
	snake->qtd=0;
	empilhar(snake);
	empilhar(snake);
	empilhar(snake);
	
	return snake;
}

void listar(Snake *snake){
	if(snake==NULL || snake->dado==NULL){
		return;
	}
	for(int i=0; i<=snake->qtd; i++){
		printf("%c", snake->dado[i]);
	}	
	return;
}


int empilhar(Snake *snake){
	if(snake==NULL || snake->dado==NULL){
		return 0;
	}
	if(snake->topo>=snake->max-1 || snake->qtd>=snake->max){
		return 0;
	}
	snake->topo++;
	snake->dado[snake->topo]='@';
	snake->qtd++;
	return 1;
}

int desempilhar(Snake *snake){
	if(snake==NULL || snake->dado==NULL || snake->topo==-1){
		return 0;
	}
	snake->topo--;
	snake->qtd--;
	return snake->dado[snake->topo+1];
}

Fruta *criarfruta(){
	Fruta *fruta = (Fruta*)malloc(sizeof(Fruta));
	if(fruta==NULL){
		return NULL;
	}
	fruta->x = 18;
	fruta->y = 13;
	return fruta;
}


