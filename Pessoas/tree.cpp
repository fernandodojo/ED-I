
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include "tree.h"

using namespace std;

list *criar()
{
    list *l = new list;

    if (l == NULL)
        return NULL;

    l->head = NULL;
    l->tail = NULL;

    return l;
}

void insert(list *l, colaborador *dado)
{
    if (l != NULL) //se a lista existir
    {
        node *aux = l->head; //aloca um auxiliar para percorrer

        node *newnode = new node; //aloca o novo nó
        if (newnode != NULL)
            newnode->data = dado; // se o  no for alocado com sucesso, atribui-se valor

        if (l->head == NULL)
        { // se a lista estiver vazia, insere na cabeça
            l->head = l->tail = newnode;
            l->head->next = l->tail->next = NULL;
        }
        else
        { // se não estiver vazia adiciona-se no final
            l->tail->next = newnode;
            newnode->prev = l->tail;
            l->tail = newnode;
        }
    }
}

void print(list *banco)
{
    node *print2 = banco->head; // aux para percorrer
    while (print2 != NULL)
    { //impressão de cada volor da estrutura colaborador
        cout << "COLABORADOR" << endl;
        cout << "Nome: " << print2->data->nome << endl;
        cout << "Data de Entrada: " << print2->data->dtentrada << endl;
        cout << "Data de Saída: " << print2->data->dtsaida << endl;
        cout << endl;
        print2 = print2->next; // atualiza a posição
    }
}

dado *criaTree(string name, colaborador *ptrcolaborador)
{
    dado *t = new dado;

    if (t == NULL)
        return NULL;

    t->chave = name;
    t->right = NULL;
    t->left = NULL;
    t->ptcolaborador = ptrcolaborador;

    return t;
}

dado *inserirTree(dado *pai, string name, colaborador *ptrcolaborador)
{
    dado *novo = criaTree(name, ptrcolaborador); // alocando um novo nó

    if (novo == NULL)
        return NULL;

    if (pai == NULL)
    { // se a arvore estiver vazia
        pai = novo;
        return novo;
    }
    else if (name < pai->chave)
    { // se o dado a ser inserido for menor que o pai

        pai->left = inserirTree(pai->left, name, ptrcolaborador);
    }
    else
    { // se o dado a ser inserido for maior que po pai
        pai->right = inserirTree(pai->right, name, ptrcolaborador);
    }

    return pai;
}

colaborador *busca(dado *raiz, string name)
{
    if (raiz == NULL)
        return NULL;
    else if (raiz->chave == name) //se for encontrado
        return raiz->ptcolaborador;
    else if (name <= raiz->chave) //se o nome for menor que a chave, buscar a esquerda
        return busca(raiz->left, name);
    else
        return busca(raiz->right, name); //se o nome for maior que a chave, buscar a direita
}

//visita primeiro esquerda, raiz, direita
void inOrdem(dado *raiz)
{
    if (raiz == NULL)
        return;
    inOrdem(raiz->left);

    cout << "Chave: " << raiz->chave << endl;

    inOrdem(raiz->right);
}

//visita raiz, esquerda, direita
void preOrdem(dado *raiz)
{
    if (raiz == NULL)
        return;
    cout << "Chave: " << raiz->chave << endl;
    preOrdem(raiz->left);
    preOrdem(raiz->right);
}

//encontrar o nó com menor valor, mais a esquerda
dado *minValueNode(dado *raiz)
{
    dado *current = raiz;
    while (current->left != NULL)
        current = current->left;

    return current;
}

dado *deleteNode(dado *raiz, string key)
{
    if (raiz == NULL) // se arvore é nula, não faz nada
        return raiz;
    if (key < raiz->chave) // se o valor é menhor que a raiz, procura-se a esquer
        raiz->left = deleteNode(raiz->left, key);
    else if (key > raiz->chave) // se o valor é maior que a raiz, procura-se a direita
        raiz->right = deleteNode(raiz->right, key);
    else
    {
        if (raiz->left == NULL) // se a raiz a esquerda não existe, torna o nó da direita a nova raiz
        {
            dado *temp = raiz->right;
            delete (raiz);
            return temp;
        }
        else if (raiz->right == NULL) // se a raiz a direita não existe, torna o nó da esquerda a nova raiz
        {
            dado *temp = raiz->left;
            delete (raiz);
            return temp;
        }
        //caso quando ha dois filhos

        dado *temp = minValueNode(raiz->right);                           //pega-se o menor valor da arvore direita
        raiz->ptcolaborador = temp->ptcolaborador;                        //atribu a estrutura do menor nó a direita a raiz que se quer remover
        raiz->chave = temp->chave;                                        // //atribu a chave do menor nó a direita a raiz que se quer remover
        raiz->right = deleteNode(raiz->right, temp->ptcolaborador->nome); // procura-se e deleta o nó com os dados iguais a menor arvore anterior
    }

    return raiz;
}
