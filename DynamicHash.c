#include <stdlib.h>

typedef struct Item{
    int chave;
    long e1, e2;
    long elemento;
} Item;

Item NULLItem = {0,0,0,0};

static int N, M;
static Item *ht;

#define key(x) (x.chave)

#define hash(v, m) (v % m)

#define hashtwo(v, m) (v%97 + 1)

#define less(A, B) (key(A) <  key(B))

#define lessequal(A, B) (key(A) <=  key(B))

#define null(A) (key(ht[A]) == key(NULLItem))

void HTInit(int max){
    int i;
    N = 0, M = 2*max;
    ht = malloc(sizeof(Item)*M);
    for(i = 0; i < M; i++)
        ht[i] = NULLItem;
}

int HTCount(){ 
    return N;
}


void STInsert(Item item){
    int v = key(item);
    int i = hash(v, M);
    int k = hashtwo(v, M);
    while(!null(i)) i = (i+k)%M;
    ht[i] = item;
}

void expand(){
    int i;
    Item *t = ht;
    ht = malloc(sizeof(Item)*2*M);
    M *= 2;
    for (i = 0; i < M; i++)
        ht[i] = NULLItem;
    for (i = 0; i < M/2; i++){
        if(key(t[i]) != key(NULLItem))
            STInsert(t[i]);
    }
    free(t);
}

void HTInsert(Item item){
    int v = key(item);
    int i = hash(v, M);
    int k = hashtwo(v, M);
    while(!null(i)) i = (i+k)%M;
    ht[i] = item;
    N++;    
    if (N >= M/2)
        expand();
}

Item HTSearch(int v){
    int i = hash(v, M);
    int k = hashtwo(v, M);
    while(!null(i)){
        if(v == key(ht[i]))
            return ht[i];
        else
            i = (i+k)%M;
    }
    return NULLItem;
}