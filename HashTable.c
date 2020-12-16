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

#define hash(v, m) ((618033* (unsigned) v) % m)

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

void HTInsert(Item item){
    int v = key(item);
    int i = hash(v, M);
    while(!null(i)) i = (i+1)%M;
    ht[i] = item;
    N++;
}

Item HTSearch(int v){
    int i = hash(v, M);
    while(!null(i)){
        if(v == key(ht[i]))
            return ht[i];
        else
            i = (i+1)%M;
    }
    return NULLItem;
}