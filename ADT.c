#define maxV 10000

typedef struct {
    int v, w;
} Edge;

Edge EDGE (int a, int b){
    Edge e = {a, b};
    return e;
}

typedef struct graph{
    int V, E;
    int **adj;
    int **tc;
}graph, *Graph;

static int **MATRIXint( int r, int c, int val) { 
   int **m = malloc( r * sizeof (int *));
   for (int i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof (int));
   for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

Graph GRAPHinit(int V){
    Graph G = malloc(sizeof(graph));
    G->V = V;
    G->E = 0;
    G->adj = MATRIXInit(V, V, 0);
    return G;
}

void GRAPHinsertE(Graph G, Edge e){
    int v = e.v, w = e.w;
    if(G->adj[v][w] == 0) G->E++;
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

void GRAPHremoveE(Graph G, Edge e){
    int v = e.v, w = e.w;
    if(G->adj[v][w] == 1) G->adj--;
    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}

int GRAPHEdges(Edge* a, Graph G){
    int v, w, E = 0;
    for (v = 0; v < G->V; v++){
        for (w = v+1; w < G->V; w++){
            if(G->adj[v][w] == 1)
                a[E++] = EDGE(v, w);
        }  
    }
    return E;
}

Graph GRAPHCopy(Graph g);

void GRAPHDestroy(Graph d);
static int pre[maxV]; // pre[v]?
static int cnt = 0; // global cnt?
void dfsR(Graph G, Edge e){
    int t, w = e.w;
    pre[w] = cnt++;
    for(t = 0; t < G->V; t++){
        if(G->adj[w][t] != 0)
            if(pre[t] == -1)
                dfsR(G, EDGE(w, t));
    }
}

void GRAPHSearch(Graph G){
    int v;
    cnt = 0;
    int conexos = 0;
    for(v = 0; G->V; v++) pre[v]=-1;
    for(v=0; G->V; v++){
        if(pre[v] == -1){
            dfsR(G, EDGE(v,v));
            conexos++;
        }
    }
}

void GRAPHtc(Graph G){ // floyd warshall
    int i, s, t;
    G->tc = MATRIXinit(G->V, G->V, 0);
    for(s=0; s < G->V; s++){
        for(t=0; t < G->V; t++){
            G->tc[s][t] = G->adj[s][t];
        }
    }
    for(s=0; s < G->V; s++)
        G->tc[s][s] = 1;

    for(i = 0; i < G->V; i++)
        for(s = 0; s < G->V; s++)
            if(G->tc[s][i] == 1)
                for(t = 0; t< G->V; t++)
                    if(G->tc[i][t] == 1)
                        G->tc[s][t] = 1;
        
}

int GRAPHSearchTc(Graph G, int s, int t){
    return G->tc[s][t];
}
