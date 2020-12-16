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
    int v, w;
} Edge;

typedef struct graph{
    int V, E;
    link *adj;
}graph, *Graph;

Edge EDGE (int a, int b, int c){
    Edge e = {a, b};
    return e;
} // não copia essa parte n

int queue[2000000]; 
int begin, end;

void QUEUEinit( int N) {

    queue = malloc(N * sizeof (int));
    begin = 0;
    end = 0; 
}

int QUEUEempty( void) { 
   return begin == end; 
}

void QUEUEput( vertex v) {
   queue[end++] = v;
}

vertex QUEUEget( void) { 
   return queue[begin++];
}

void QUEUEfree( void) {
   free(queue);
}

int GRAPHcptBF(Graph G, int s, int *pa, int *dist){
    int onqueue[1000]; // cuidar do tamanho desse cara akie
    int V = G->V;
    for(int v = 0; v < G->V; v++)
        pa[v] = -1, dist[v] = INT_MAX, onqueue[v] = 0;
    pa[s] = s;
    dist[s] = 0;
    QUEUEinit(G->E);
    QUEUEput(s);
    QUEUEput(V);
    int k = 0;
    onqueue[s] = 1;
    while(1){
        int v = QUEUEget();
        if(v < V){
            for (link a = G->adj[v]; a != NULL; a = a->next){
                if(dist[v] + a->c < dist[a->v]){
                    dist[a->v] = dist[v] + a->c;
                    pa[a->v] = v;
                    if(onqueue[a->v] == 0){
                        QUEUEput(a->v);
                        onqueue[a->v] = 1;
                    }
                }
            }
        }else{
            if(QUEUEempty()) return 1;
            if(++k >= G->V) return 0;
            QUEUEput(V);
            for (int t = 0; t < G->V; t++){
                onqueue[t] = 0;
            }
        }
    }
}