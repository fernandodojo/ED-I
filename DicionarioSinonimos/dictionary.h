#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <string.h>
#include <fstream> // biblioteca arquivos
#include <stdbool.h>

using  namespace std;


#ifndef DICIONARIO_H
#define DICIONARIO_H

typedef struct _node{
	string palavra;
	struct _node *next;
	struct _list *sin;
	int cont;
} node;


typedef  struct _list{
	struct _node *head, *tail;
} lista;


lista *creat();
node *creatNode(string s);
int addList(lista *l, node *noh);
node *compCont(node *palavra);
node *compWord(lista *l, string c);
void print(lista *l);
#endif
