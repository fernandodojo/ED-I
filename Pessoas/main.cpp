
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include "tree.h"

using namespace std;

int main()
{
  int menu;

  dado *nomesCol = NULL;  // árvore de nomes
  dado *inputCol = NULL;  // árvore de datas de entrada
  dado *outputCol = NULL; // árvores de saída

  list *bancoDados = criar(); //criando a lista que possui o banco de dados do laboratorio

  do
  {
    cout << "****MENU****" << endl;
    cout << "Inserir[1]" << endl;
    cout << "Editar[2]" << endl;
    cout << "Buscar[3]" << endl;
    cout << "Sair[0]" << endl;
    cout << "****MENU****" << endl;
    cin >> menu;
    switch (menu)
    {

      // ================== INSERÇÃO ARVORE ==================

    case 1:
    {

      colaborador *aux = new colaborador;

      colaborador *aux0 = new colaborador;
      aux0->nome = "fernando";
      aux0->dtsaida = "07/10/2297";
      aux0->dtentrada = "22/09/1997";

      colaborador *aux1 = new colaborador;
      aux1->nome = "henrique";
      aux1->dtsaida = "07/10/2187";
      aux1->dtentrada = "22/09/1987";

      colaborador *aux2 = new colaborador;
      aux2->nome = "ana";
      aux2->dtsaida = "07/10/2057";
      aux2->dtentrada = "22/09/1957";

      // ================== INSERÇÃO BANCO DE DADOS ==================
      insert(bancoDados, aux0);
      insert(bancoDados, aux1);
      insert(bancoDados, aux2);

      cout << "\n**********BANCO DE DADOS**********\n";
      print(bancoDados);
      cout << "**********BANCO DE DADOS**********\n";

      node *BD = bancoDados->head;
      nomesCol = criaTree(BD->data->nome, BD->data);
      inputCol = criaTree(BD->data->dtentrada, BD->data);
      outputCol = criaTree(BD->data->dtsaida, BD->data);

      node *tempBD = BD->next;
      while (tempBD != NULL)
      {
        inserirTree(nomesCol, tempBD->data->nome, tempBD->data);
        inserirTree(inputCol, tempBD->data->dtentrada, tempBD->data); // Árvore de entradas
        inserirTree(outputCol, tempBD->data->dtsaida, tempBD->data);  //Árvore de Saída
        tempBD = tempBD->next;
      }

      cout << "\n\n**********ARVORES********\n";
      cout << "NOMES:\n";
      inOrdem(nomesCol);
      cout << endl;

      cout << "ENTRADA:\n";
      inOrdem(inputCol);
      cout << endl;

      cout << "SAIDA:\n";
      inOrdem(outputCol);
      cout << "\n**********ARVORES********\n";
      cout << "\n\n";
    }
    break;
      // ================== INSERÇÃO ARVORE ==================

      // ================== EDIÇÃO ==================

    case 2:
    {

      int op;
      cout << "editar nome[1]" << endl;
      cout << "editar data entrada[2] " << endl;
      cout << "editar data de saida[3] " << endl;
      cin >> op;
      switch (op)
      {
      case 1:
      {
        string name, novoNome;
        colaborador *tempBusca;

        cout << "Informe o nome que deseja alterar: " << endl;
        cin >> name;
        tempBusca = busca(nomesCol, name); // guardando endereço de memoria

        if (tempBusca == NULL)
        {
          cout << "O nome informado nao esta cadastrado" << endl;
        }
        else
        {
          cout << "Informe o novo nome:" << endl;
          cin >> novoNome;
          tempBusca->nome = novoNome;

          //impressão de lista  após alteração dos dados
          /*cout << "\n\nIMPRESSAO LISTA APOS ALTERACAO\n"<<endl;
              node *tempNode = bancoDados->head; 

              while(tempNode!=NULL){
                cout<<tempNode->dado->nome<<endl;        
                tempNode = tempNode->prox;

              cout<<"\n\n";
              }*/

          deleteNode(nomesCol, name);

          inserirTree(nomesCol, tempBusca->nome, tempBusca);

          cout << "\n**********NOVA ARVORES(Em Ordem)********\n";
          inOrdem(nomesCol);
          cout << endl;

          cout << "\n**********NOVA ARVORES(Pre Ordem)********\n";
          preOrdem(nomesCol);
          cout << endl;
        }
      }
      break;
      case 2:
      {
        string input;
        string novoInput;
        colaborador *tempBusca;

        cout << "Informe a data de entrada que deseja alterar: " << endl;
        cin >> input;
        tempBusca = busca(inputCol, input); // guardando endereço de memoria

        if (tempBusca == NULL)
        {
          cout << "A data informada nao esta cadastrado" << endl;
        }
        else
        {
          cout << "Informe a nova data de entrada:" << endl;
          cin >> novoInput;
          tempBusca->dtentrada = novoInput;

          //impressão de lista  após alteração dos dados
          /*cout << "\n\nIMPRESSAO LISTA APOS ALTERACAO\n"<<endl;
              node *tempNode = bancoDados->head; 

              while(tempNode!=NULL){
                cout<<tempNode->dado->nome<<endl;        
                tempNode = tempNode->prox;

              cout<<"\n\n";
              }*/

          deleteNode(nomesCol, input);

          inserirTree(nomesCol, tempBusca->dtentrada, tempBusca);

          cout << "\n**********NOVA ARVORES(Em Ordem)********\n";
          inOrdem(nomesCol);
          cout << endl;

          cout << "\n**********NOVA ARVORES(Pre Ordem)********\n";
          preOrdem(nomesCol);
          cout << endl;
        }
      }
      break;
      case 3:
      {
        string output;
        string novoOutput;
        colaborador *tempBusca;

        cout << "Informe a data de saida que deseja alterar: " << endl;
        cin >> output;
        tempBusca = busca(outputCol, output); // guardando endereço de memoria

        if (tempBusca == NULL)
        {
          cout << "A data informada nao esta cadastrado" << endl;
        }
        else
        {
          cout << "Informe a nova data de saida:" << endl;
          cin >> novoOutput;
          tempBusca->dtsaida = novoOutput;

          //impressão de lista  após alteração dos dados
          /*cout << "\n\nIMPRESSAO LISTA APOS ALTERACAO\n"<<endl;
              node *tempNode = bancoDados->head; 

              while(tempNode!=NULL){
                cout<<tempNode->dado->nome<<endl;        
                tempNode = tempNode->prox;

              cout<<"\n\n";
              }*/

          deleteNode(nomesCol, output);

          inserirTree(nomesCol, tempBusca->dtsaida, tempBusca);

          cout << "\n**********NOVA ARVORES(Em Ordem)********\n";
          inOrdem(nomesCol);
          cout << endl;

          cout << "\n**********NOVA ARVORES(Pre Ordem)********\n";
          preOrdem(nomesCol);
          cout << endl;
        }
      }
      break;
      }
    }
    break;
    // ================== EDIÇÃO ==================

    // ================== BUSCA ==================
    case 3:
    {
      int opMenu;

      cout << "Consultar por Nome[1]" << endl;
      cout << "Consultar por Data de entrada[2]" << endl;
      cout << "Consultar por Data de saida[3]" << endl;
      cin >> opMenu;

      switch (opMenu)
      {
      case 1:
      {
        string name;
        cout << "Informe o nome de colaborador:" << endl;
        cin >> name;
        colaborador *nomeColaborador = busca(nomesCol, name);

        if (nomeColaborador != NULL)
        {
          cout << "\nEncontrado!" << endl;
          cout << "Nome: " << nomeColaborador->nome << endl;
          cout << "Data de Entrada: " << nomeColaborador->dtentrada << endl;
          cout << "Data de Saída: " << nomeColaborador->dtsaida << endl;
          cout << endl;
        }
        else
        {
          cout << "\nNao Encontrado" << endl;
        }
      }
      break;

      case 2:
      {

        string input;
        cout << "Informe a data de entrada:" << endl;
        cin >> input;
        colaborador *inputColaborador = busca(inputCol, input);
        if (inputColaborador != NULL)
        {
          cout << "\nEncontrado!" << endl;
          cout << "Nome: " << inputColaborador->nome << endl;
          cout << "Data de Entrada: " << inputColaborador->dtentrada << endl;
          cout << "Data de Saída: " << inputColaborador->dtsaida << endl;
          cout << endl;
        }
        else
        {
          cout << "\nNao Encontrado" << endl;
        }
        break;
      }

      case 3:
      {
        string output;
        cout << "Informe a data de saida:" << endl;
        cin >> output;
        colaborador *outputColaborador = busca(outputCol, output);
        if (outputColaborador != NULL)
        {
          cout << "\nEncontrado!" << endl;
          cout << "Nome: " << outputColaborador->nome << endl;
          cout << "Data de Entrada: " << outputColaborador->dtentrada << endl;
          cout << "Data de Saída: " << outputColaborador->dtsaida << endl;
          cout << endl;
        }
        else
        {
          cout << "\nNao Encontrado" << endl;
        }
      }
      break;
      }
      break;
    }
    break;
      // ================== BUSCA ==================
    }

  } while (menu != 0);
}