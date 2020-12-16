#include <stdlib.h>
#include <limits.h>

#define vertex int

typedef struct node *link;
struct node{
    int v;
    int c;
    link next;
};

typedef struct {
    int v, w, c;
} Edge;

typedef struct graph{
    int V, E;
    link *adj;
}graph, *Graph;

Edge EDGE (int a, int b, int c){
    Edge e = {a, b, c};
    return e;
} // não copia essa parte n

void GRAPHcptD1(Graph G, int s, int *pa, int *dist){
    int mature[1000];
    for (int v = 0; v < G->V; v++){
        pa[v] = -1;
        mature[v] = 0;
        dist[v] = INT_MAX;
    }
    pa[s] = s;
    dist[s] = 0;
    while(1){
        int min = INT_MAX;
        int y;
        for (int z = 0; z < G->V; z++){
            if(mature[z]) continue;
            if(dist[z] < min)
                min = dist[z], y = z;
        }
        if(min = INT_MAX) break;
        for(link a = G->adj[y]; a != NULL; a=a->next){
            if(mature[a->v]) continue;
            if(dist[y]+a->c < dist[a->v]){
                dist[a->v] = dist[y] + a->c;
                pa[a->v] = y;
            }
        }
    }
}