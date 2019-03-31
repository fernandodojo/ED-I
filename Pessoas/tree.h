
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

// ================== Estruturas  Árvores  ==================

typedef struct _colaborador
{
	string nome;
	string dtentrada;
	string dtsaida;
	string matricula;
} colaborador;

typedef struct _dado_
{
	string chave;				//chave usada para busca
	struct _dado_ *right;		//no a direira
	struct _dado_ *left;		//no a esquerda
	colaborador *ptcolaborador; //estrutura colaborador
} dado;

// ================== Estruturas Lista Banco de Dados ==================

typedef struct _node_
{
	colaborador *data;   //estrutura colaborador
	struct _node_ *prev; //nó anterior
	struct _node_ *next; //nó posterior
} node;

typedef struct _list_
{
	node *head; //estrutura auxilar lista
	node *tail; //estrutura auxilar lista
} list;

// ================== Funções Lista Banco de Dados ==================

list *criar();

void insert(list *l, colaborador *nome);

void print(list *banco);

// ================== Funções Árvores ==================

dado *criaTree(string name, colaborador *ptrcolaborador);

dado *inserirTree(dado *pai, string name, colaborador *vetorcolaborador);

colaborador *busca(dado *raiz, string name);

void inOrdem(dado *raiz);

void preOrdem(dado *raiz);

dado *minValueNode(dado *raiz);

dado *deleteNode(dado *raiz, string key);