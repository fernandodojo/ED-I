#ifndef snake_h
#define snake_h

typedef struct _topo_{
	int x;
	int y;
}topo;

typedef struct _fim_{
	int x;
	int y;
}fim;


typedef struct _pilhasnake_{
	char *dado;
	char direcao;
	topo *t;	
	fim *f;
	//int x;
	//int y;
	int topo;
	int max;
	int score;	
	int qtd;
	int fim;
}Snake;

typedef struct _fruta_{
	int x;
	int y;
}Fruta;


Snake *criarcobra();
Fruta *criarfruta();
void listar(Snake *snake);
int empilhar(Snake *snake);
int desempilhar(Snake *snake);

/*
[0].direcao
for(int i=1;i<tamanho;i++){
	v[i].direcao = v[i-1].direcao
}
on press(){
	v[0].direcao =diecional
}*/
#endif