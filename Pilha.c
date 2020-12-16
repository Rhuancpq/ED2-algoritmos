
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int dado;
    struct pilha *prox;
} pilha;

pilha *cria_pilha () {
    pilha *topo = malloc(sizeof (pilha));
    topo->prox = NULL;

    return topo;
}

void empilha (pilha *p, int x) {
    pilha *novo = malloc (sizeof (p));
    if (novo == NULL) exit(1);
    novo->dado = x;
    novo->prox = p->prox;
    p->prox = novo;
}

int desempilha (pilha *p, int *y) {
    if (p->prox != NULL) {
        pilha *lixo = p->prox;
        *y = lixo->dado;
        p->prox = lixo->prox;
        free (lixo);
        return 1;
    } else {
        return 0;
    }
}