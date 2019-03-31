

typedef struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
}node;

typedef struct List{
	node *head;
	node *tail;
}list;

list *criar();
void destruir(list **l);
void inserir(list *l, int dado);
int concatenar(list *l1, list *l2);
int tamanho(list *l);
int removerpos(list *l, int pos);
int removerultimo(list *l);
int inserirpos(list *l,int pos, int dado);
int removersegundo(list *l);
int soma(list *l);
list *copia(list *l);
void ascendente(list *l);
list *concatenarordenado(list *l1, list *l2);
void insereordenado(list *l, int dado);
list *concatenarordenado2(list *l1, list *l2);
void deslocarnposicoes(list *l, int pos, int n);
void inverter(list *l);
list *uniao(list *l1, list *l2);
list *diferenca(list *l1, list *l2);
void removerdado(list *l, int dado);
list *intersecao(list *l1, list *l2);



node* buscardado(list *l, int dado);
node *buscapos(list *l, int pos);

void printlist(list *l);


