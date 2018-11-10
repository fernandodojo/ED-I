#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
	list *l = criar();
  for(int i =0; i< 10; i++ ){
		inserir(l, i);
	}

	list *l2 = criar();
	for(int i =9; i>= 0; i-- ){
		inserir(l2, i);
	}


	//printlist(l);
	//printlist(l2);
	//concatenar(l, l2);
	//removerpos(l, 10);
	//removerpos(l, 9);
	//emoverpos(l, 8);
 	//printf("\n%d",removerpos(l, 1));

	//printf("\n%d",removerpos(l, 1));
	//destruir(&l);
	//destruir(&l2);
	//removerultimo(l);
	//inserirpos(l, 10, -1);

	//removersegundo(l);
	//printf("\n%d",soma(l));
	//list *c = copia(l);
	//inserir(c, -5);
	//printlist(c);
	//printlist(l2);
	//printf("\nPosição do item: %d", buscapos(l, 1));
	//printf("\nTamanho: %d", tamanho(l));
	//printlist(l);
	inserirpos(l, 5, 12);
	inserirpos(l, 9, 17);
	inserirpos(l, 4, 13);
	inserirpos(l, 1, 20);
	inserirpos(l, 9, 37);
	printlist(l);

	inserirpos(l2, 5, 45);
	inserirpos(l2, 9, 24);
	inserirpos(l2, 4, 12);
	inserirpos(l2, 1, 49);
	inserirpos(l2, 9, 100);
	printlist(l2);

	//ascendente(l2);
	//concatenarordenado(l, l2);
	//removerpos(l,10);
	//printlist(l);
	//insereordenado(l, 19);
	// insereordenado(l, 11);
	// insereordenado(l, 1);
	// insereordenado(l, 5);
	// insereordenado(l, 8);
	// insereordenado(l, 40);
	// insereordenado(l, 30);
	// insereordenado(l, 100);
	// insereordenado(l, -100);
	//concatenarordenado2(l, l2);
	//printlist(l);
	//deslocarnposicoes(l, 8, 1);
	//inverter(l);
	//uniao(l,l2);
	//ascendente(l);
	//diferenca(l, l2);
	//intersecao(l, l2);
	//printlist(l);
	//printlist(l2);
	
}