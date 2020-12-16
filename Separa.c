typedef int Item;

#define key(A) A

#define less(A, B) (key(A) <  key(B))

#define lessequal(A, B) (key(A) <=  key(B))

#define exch(A, B) {Item t = A; A = B; B = t;}

#define cmpexch(A, B) {if(less(B, A)) exch(A, B)}

int separa_out_place(Item *v, int l, int r){
    int tam =  r-l+1;
    Item c = v[r];
    Item *menores = malloc(sizeof(Item)*tam);
    Item *maiores = malloc(sizeof(Item)*tam);
    int imaiores = 0, imenores = 0;

    for(int i = l; i < r; i++){
        if(lessequal(v[i], c)){
            menores[imenores++] = v[i];
        }else
            maiores[imaiores++] = v[i];
    }

    int i = l, cpos;
    for(int j = 0; j < imenores; j++)
        v[i++] = menores[j];

    v[i] = c;
    cpos = i;

    for(int j = 0; j < imaiores; j++)
        v[i++] = maiores[j];

    free(maiores);
    free(menores);
    return cpos;
}

int separa_sedgewick(Item *v, int l, int r){
    int i = l-1, j = r;
    Item c = v[r];
    for(;;){
        while(less(v[++i], c));
        while(less(c, v[--j])) if(j == l) break;
        if(i >= j)break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}