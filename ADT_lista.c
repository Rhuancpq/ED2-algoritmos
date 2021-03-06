#include <stdlib.h>

#define maxV 100000

typedef struct node *link;
struct node{
    int v; 
    link next;
};

typedef struct {
    int v, w;
} Edge;

typedef struct graph{
    int V, E;
    link *adj;
}graph, *Graph;

Edge EDGE (int a, int b){
    Edge e = {a, b};
    return e;
}

link NEW (int v, link next){
    link x = malloc(sizeof(link));
    if(x == NULL)
        exit(0);

    x->v = v;
    x->next = next;
    return x;
}

Graph GRAPHinit(int V){
    int v;
    Graph G = malloc(sizeof(*G));
    G->V = V; 
    G->E = 0;
    G->adj = malloc( V * sizeof (link));
    for (v = 0; v < V; ++v) 
        G->adj[v] = NULL;
    return G;
}

void GRAPHinsertE( Graph G, Edge e) { 
   int v = e.v, w=e.w;
   G->adj[v] = NEW(w, G->adj[v]);
   G->adj[w] = NEW(v, G->adj[w]);
   G->E++;
}

int GRAPHEdges(Edge a[], Graph G){
    int v, E = 0; link t;
    for(v = 0; v < G->V; v++){
        for(t = G->adj[v]; t != NULL; t = t->next){
            if(v<t->v) 
                a[E++] = EDGE(v, t->v);
        }
    }
    return E;
}
static int pre[maxV]; // pre[v]?
static int cnt = 0; // global cnt?

void dfsR(Graph G, Edge e){
    int t, w = e.w;
    link l;
    pre[w] = cnt++;
    for(l=G->adj[w]; l != NULL; l=l->next){
        t = l->v;
        if(pre[t] == -1)
            dfsR(G, EDGE(w, t));
    }
}

void GRAPHSearch(Graph G){
    int v;
    cnt = 0;
    int conexos = 0;
    for(v = 0; v < G->V; v++) pre[v]=-1;
    for(v=0; v < G->V; v++){
        if(pre[v] == -1){
            dfsR(G, EDGE(v,v));
            conexos++;
        }
    }
}