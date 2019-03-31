#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream> 
#include <stdbool.h>
#include <ostream>


#include "dictionary.h"
int main(){

	lista *dictionary = creat();
	

	//ABRE ARQUIVO SINONIMOS PARA GRAVAÇÃO
	string word, sin;	
	ifstream Word;  

	string line; 
	bool first = true;
	Word.open("sinonimos.txt");

	if(Word.is_open()){	
		while (Word >> line) {			
      if(first){
			    word = line;
					first = false;	
				
          node *noh = creatNode(word); //criando um nó				
					addList(dictionary, noh);
      }else if (line != "."){
          sin = line;
					node *noh = creatNode(sin); //criando um nó
					addList( dictionary->tail->sin,  noh);
      }
      if(line == "."){
          first = true;
      }
    }
	}

  Word.close();
	//FECHAMENTO SINONIMOS


// LENDO PARAGRAFO DO ARQUIVO E GRAVANDO NO ANTIGO
	ifstream insideText;
	insideText.open("text.txt", ios :: in);

	if(!insideText.is_open()){
		cout << "Erro" << endl;
		exit (1);
	}

//ABRE E LER ANTIGO ARQUIVO
	ifstream insidetext;  
  insidetext.open("text.txt", ios :: in);

	 // QUEBRA DO TEXTO EM PALAVRAS
  ofstream newFile("newtext.txt", ofstream::out);  //ABRE E GRAVA NOVO ARQUIVO
	string primeira;
	string l;
  node* aux;
	 while (insidetext >> l) {		    
      primeira = l;	
			
			aux = compWord(dictionary, primeira); 
      if (aux) {
        newFile << aux->palavra;
        newFile << " ";
     
       }  else{
         newFile << primeira;
         newFile << " ";         
       }
      
	 }  
	insidetext.close(); //FECHA A LEITURA ANTIGO ARQUIVO
  newFile.close(); //FECHA A GRAVAÇÃO NOVO ARQUIVO


	print(dictionary); // imprimir a lista com seus respectivos

	
	//IMPRESSÃO DO PARAGRAFO DO ARQUIVO
	ifstream auX;
  auX.open("text.txt", ios :: in);
  string temp;
  
  cout << endl << "Antigo " << endl;
	while(!auX.eof()){	
		while(getline(auX, temp)){
			cout<<temp<<endl;
		}		
  }
  auX.close();  
	//FECHA GRAVAÇÃO ANTIGO ARQUIVO text

	//ABRE A LEITURA NOVO ARQUIVO text
  ifstream newfile; 
  newfile.open("newtext.txt", ios :: in);
  string p;

  cout << endl << "Novo " << endl;
	while(!newfile.eof()){	      
	  while(getline(newfile, p)){        
			cout<<p<<endl;
		}	
  }  
  newfile.close();  
	//FECHA A LEITURA NOVO ARQUIVO text
}