#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream> // biblioteca arquivos
#include <stdbool.h>
#include <ostream>

#include "dictionary.h"

using  namespace std;

lista *creat(){
	lista *l = new lista[1];
	if(l!=NULL){
		l->head = NULL;
		l->tail= NULL;		
	}
	return l;
}

node *creatNode(string s){

	node *noh = new node[1];

	if(noh != NULL){
		noh->sin = creat();// criar  alista de sinonimos
		noh->cont=0;
		noh->next = NULL;
		noh->palavra = s;
	}
	return noh;
}

int addList(lista *l, node *noh){	
		
		if(l->head==NULL){			
			l -> head = noh;
			l -> tail = noh;
			l->tail->next = NULL;		
			return 1;
		}else{
			l->tail->next = noh;
			noh ->next= NULL;
			l->tail  = noh;	
			l->tail -> next= NULL;
			return 1;	
		}
		return 0;
}

node *compCont(node *palavra){
	if(palavra==NULL) return NULL;	
	node *sin = palavra->sin->head;

	node* menorNode = sin;	

	int menor = sin->cont;	

	while(sin->next!=NULL){		
		sin=sin->next;	
		if(menor>sin->cont){
			menor = sin->cont;
			menorNode = sin;
		}			
	}
	menorNode->cont++;	
	cout<<"	Sinonimo: "<<menorNode->palavra<<" 	|Contador: "<< menorNode->cont<<endl;
	return menorNode;
}

node *compWord(lista *l, string c){
	if(l==NULL) return NULL;
	node *palavra = l->head;
	
	while(palavra!=NULL){
		if(palavra ->palavra  ==  c){
			cout <<"............................................"<<endl;
			cout << "Palavra ("<<palavra->palavra<<") encontrada"<< endl;
			cout <<"............................................"<< endl;
			return compCont(palavra);
		}
		palavra = palavra->next;
	}
	return NULL;
}


void print(lista *l){
  node *aux = l->head;
	cout<<endl;
	cout<<endl;
	cout<<"	PILHA DE PALAVRAS/SINONIMOS"<<endl;
  while(aux!=NULL){			
      cout<<"Palavra:"<<aux->palavra << "\n";
			lista *sinonimos = aux->sin;
			node* sinPalavra = sinonimos->head;
			while(sinPalavra != NULL) {
        cout<<"	Sinonimo: "<<sinPalavra->palavra<<" 	|Contador: "<< sinPalavra->cont<<endl;
 				sinPalavra = sinPalavra->next;
			}
			aux = aux->next;
  }	
}


