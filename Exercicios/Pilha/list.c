#include <stdio.h>
#include <stdlib.h>
#include "list.h"



list *criar(){
	list *l = (list*) malloc(sizeof(list));
	if(l!=NULL){
		l->head=NULL;
		l->tail = NULL;
	}
	return l;
}


//Liberar todos os nós numa lista.//
void destruir(list **l){
	node *current = (*l)->head;
	node *aux;
	while(aux->next!=NULL){
		aux = current;
		current = current->next;
		free(aux);
	}
	free(*l);
	*l = NULL;
}

//Incluir um elemento no final de uma lista.//
void inserir(list *l, int dado){
	if(l!=NULL){
		node *aux = l->head;

		node *newnode =(node*)malloc(sizeof(node));
		if(newnode != NULL)	newnode->data = dado;

		if(l->head== NULL){
			l->head=l->tail = newnode;
			l->head->next =l->tail->next = NULL;
		}else{
			l->tail->next =newnode;
			newnode->prev = l->tail;
			l->tail=newnode;
		}	
	}	
}

//retornar nó caso o mesmo exista na lista
node* buscardado(list *l, int dado){
	if(l->head == NULL || l->head == NULL) return NULL;

	node *aux = l->head;

	while(aux!= NULL){
		if(aux->data == dado){
			return aux;
		}
		aux = aux->next;
	}
	return NULL;
}


//buscar/retornar o nó em posição especifica
node *buscapos(list *l, int pos){
	if(l == NULL || l->head == NULL) return 0;

	node *aux = l ->head;
	int i=1;

	while(aux!=NULL && i<=pos){		
		aux = aux->next;
		i++;
	}
	return aux;
}


//Retornar o número de elementos numa lista.//
int tamanho(list *l){
	if(l==NULL || l->head == NULL) return 0;

	node *aux = l->head;
	int i=1;	

	while(aux->next != NULL){
		i++;		
		aux = aux->next;
		//printf("\ntamanho: %d| data: %d", i, aux->data);
	}
	return i;
}

//Eliminar o enésimo elemento de uma lista.//
int removerpos(list *l, int pos){
	if(l==NULL && l->head == NULL) return 0;
	node *current = l->head;

	int i=1;

	if(pos>0 && pos<=tamanho(l)){
		if(pos == 1){
			if(tamanho(l)==1) return 0;
				l->head = l->head->next;
				free(current);
				current = l->head;
				return 1;
			}
		}
		while(current!=NULL && i<pos){
			current = current->next;
			i++;
		}
		if(current->next == NULL){
			l->tail = l->tail ->prev;
			l->tail->next = NULL;
			free(current);
			return 1;
		}

		current->prev->next=current->next;
		current->next->prev = current->prev;
		return 1;
}


//Concatenar duas listas.//
int concatenar(list *l1, list *l2){
	if(l1==NULL || l2==NULL) return 0;

	l1->tail->next = l2->head;
	l2->head->prev = l1->tail;
	return 1;
}

void printlist(list *l){
	if(l==NULL) return;
	
	node *aux = l->head;
	printf("\n");
	while(aux!=NULL){
		printf(" %d", aux->data);
		aux = aux->next;
	}	
}

//Eliminar o último elemento de uma lista.//
int removerultimo(list *l){
	if(l==NULL) return 0;
	if(l->head->next==NULL) return 0;

	l->tail = l->tail->prev;
	l->tail->next = NULL;
	return 1;
}

//Inserir um elemento depois do enésimo elemento de uma lista//
int inserirpos(list *l,int pos, int dado){
	if(l==NULL) return 0;
	int i=1;
	node *current = l->head;

	node *newnode = (node*)malloc(sizeof(node));
	if(newnode != NULL){
		newnode->data = dado;
	}

	/*if(pos==0){
		newnode->next= current;
		current->prev = newnode;		
		l->head = newnode;
	}*/

	while(current->next!=NULL && i< pos){
		current = current->next;
		i++;
	}

	newnode->prev = current;
	newnode->next = current->next;
	current->next = newnode;
	if(newnode->next == NULL)
		l->tail=newnode;	

	//printf("\n%d", l->tail->data);

	return 1;
}

//Eliminar cada segundo elemento de uma lista.//
int removersegundo(list *l){
	if(l==NULL || tamanho(l)<2) return 0;

	node *current = l->head->next;
	node *aux;

	while(current->next!=NULL){
		//printf("\n%d", current->data);
		aux = current->next;
		//printf("\n|%d", aux->data);		
		current->next = aux->next;
		aux->next->prev = aux->prev;		
		free(aux);
		current = current->next;	
	}
	return 1;
}



//Retornar a soma dos inteiros numa lista.//
int soma(list *l){
	if(l==NULL || l->head == NULL) return 0;
	int soma =0;
	node *current = l->head;
	
	while(current!=NULL){
		soma+=current->data;
		current = current->next;				
	}
	return soma;
}


//Criar uma segunda cópia de uma lista.//
list *copia(list *l){
	list *copia = criar();

	node *aux = l->head;
	while(aux!=NULL){
		
		inserir(copia, aux->data);
		aux= aux->next;
	}

	return copia;
}


//Colocar os elementos de uma lista em ordem ascendente.	//
void ascendente(list *l){
	if(l==NULL || l->head==NULL || tamanho(l)<=1) return;

	node *current = l->head;
	int aux;
	int flag = 1;

	while (flag ==1){
		flag = 0;
		while(current->next!=NULL){
			//printf("\n%d | %d", current->data, current->next->data);
			if(current->data > current->next->data){
				aux = current->next->data;
				current->next->data = current->data;
				current->data  = aux;
				flag = 1;			
			}	
			current = current->next;
			//printlist(l);
		}
		//printf("\n%d", l->head->data);
		current = l->head;
	}
}


//Combinar duas listas ordenadas numa única lista ordenada.//
list *concatenarordenado(list *l1, list *l2){
	l1->tail->next = l2->head;
	l2->head->prev = l1->tail;
	l1->tail = l2->tail;
	ascendente(l1);
	free(l2);
	l2=NULL;

	printlist(l1);
	printlist(l2);

	return l1;
}


//inserção ordenada
void insereordenado(list *l, int dado){
	if(l==NULL) return;
	node *current = l->head;

	node *newnode = (node*)malloc(sizeof(node));
	if(newnode ==NULL) return;
	newnode->data = dado;

	if(l->head == NULL){
		l->head = l->tail = newnode;
		l->tail = NULL;
		return;
	}

	while(current->next!=NULL && current->data<dado){
		current = current->next;		
	}

	if(current->next == NULL && dado>l->tail->data){
		l->tail->next = newnode;
		newnode->prev = l->tail;
		l->tail= newnode;

	}else	if(current->prev==NULL){		
		newnode->next = l->head;
		l->head->prev = newnode;
		l->head = newnode;		

	}else{
	newnode->next=current;
	newnode->prev=current->prev;
	current->prev->next = newnode;
	current->prev = newnode;
	}	
	return;
}


//Combinar duas listas ordenadas numa única lista ordenada.//
list *concatenarordenado2(list *l1, list *l2){
	if(l1==NULL) return NULL;

	node *aux = l2->head;

	while(aux->next!=NULL){
		insereordenado(l1, aux->data);
		aux = aux->next;
		//printlist(l1);
	}

	destruir(&l2);
	return l1;
}


//Deslocar node(p) n posições à frente numa lista.//
void deslocarnposicoes(list *l, int pos, int n){
	if(l==NULL) return;
	node *aux, *current = l->head;
	int i=0;		

	while(current!=NULL && i<pos){		
		//printf("\n%d", current->data);
		current = current->next;		
		i++;
	}

	if(pos==0){		

		aux = current->next->next;
		current->next->next = current;
		
		current->next->prev = NULL;
		l->head = current->next;

		current->prev = current->next;
		current->next = aux;
		aux->prev=current;
		return;
	}

	if(current!=NULL){
		aux = current;
		current->next->prev = current->prev;
		current->prev->next = current->next;

		while(current!=NULL && i< pos + n){
			current = current->next;
			i++;
		}

		if(current->next == NULL){
			aux ->prev = current;
			aux-> next = NULL;
			//current->next->prev = aux;
			current->next = aux;
			l->tail = aux;
			return;		

		}
		if(current!=NULL){
			//aux ->prev = current->next->prev;
			aux ->prev = current;
			aux->next = current->next;
			current->next->prev = aux;
			current->next = aux;
			return;
		}
	}
}

//Formar uma lista contendo a união dos elementos de duas listas.//
list *uniao(list *l1, list *l2){
	if(l1==NULL || l2==NULL) return NULL;

	node *aux;
	node *current = l2->head;
	ascendente(l1);

	while(current!=NULL){
		if(buscardado(l1, current->data)==NULL){
			//inserir(l1, current->data);
			insereordenado(l1, current->data);
		}		
		current = current->next;
	}
	return l1;
}

//remoção caso o dado exista//
void removerdado(list *l, int dado){
	if(l==NULL) return ;

	node *vitima = buscardado(l, dado);

	if(vitima !=NULL){
		if(vitima->prev == NULL){
			l->head = l->head->next;
			l->head->prev = vitima->prev;
		}else if(vitima->next ==NULL){
			l->tail = l->tail->prev;
			l->tail->next = vitima->next;
		}else{
			vitima->prev->next = vitima->next;
			vitima->next->prev = vitima->prev;
		}
		free(vitima);
	}
	return;
}



//Formar uma lista contendo a diferenca dos elementos de duas listas.//
list *diferenca(list *l1, list *l2){
	if(l1==NULL || l2==NULL) return NULL;

	node *aux;
	node *current = l2->head;
	ascendente(l1);

	while(current!=NULL){
		if(buscardado(l1, current->data)!=NULL){
			//inserir(l1, current->data);
			removerdado(l1, current->data);
		}		
		current = current->next;
	}
	return l1;
}

//Formar uma lista contendo a intersecção dos elementos de duas listas.//
list *intersecao(list *l1, list *l2){
	if(l1==NULL || l2==NULL) return NULL;

	node *aux;
	node *current = l1->head;
	ascendente(l1);
	ascendente(l2);

	while(current!=NULL){
		if(buscardado(l2, current->data)==NULL){
			//inserir(l1, current->data);
			removerdado(l1, current->data);
			//removerdado(l2, current->data);
		}		
		current = current->next;
	}
	return l1;
}

