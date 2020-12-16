#include <stdlib.h>

typedef struct Item{
    int chave;
    long e1, e2;
    long elemento;
} Item;

typedef struct celula{
    celula* prox;
    Item cont;
} celula;

static int N, M;
static celula **ht;

#define key(x) (x.chave)

#define hash(v, m) ((618033* (unsigned) v) % m)

#define less(A, B) (key(A) <  key(B))

#define lessequal(A, B) (key(A) <=  key(B))

#define null(A) (key(ht[A]) == key(NULLItem))

void HTInit(int max){
    N = 0, M = 2*max;
    ht = malloc(sizeof(celula)*M);
    for(int i = 0; i < M; i++){
        ht[i] == malloc(sizeof(celula));
        ht[i]->prox = NULL;
    }
}

int HTCount(){ 
    return N;
}

void HTInsert(Item item){
    int v = key(item);
    int i = hash(v, M);
    celula *atual = ht[i];
    celula *nova = malloc(sizeof(celula));
    nova->cont = item;
    nova->prox = atual->prox;
    atual->prox = nova;
    N++;
}

Item HTSearch(int v){
    int i = hash(v, M);
    celula *atual = ht[i];
    Item a = {0,0,0,0};
    atual = atual->prox; //movendo da cabeça pro prox
    while(atual != NULL){
        if(v == key(atual->cont)){
            return atual->cont;
        }else{
            atual = atual->prox;
        }
    }
    return a;
}