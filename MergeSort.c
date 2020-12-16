typedef int Item;

#define key(A) A

#define less(A, B) (key(A) <  key(B))

#define lessequal(A, B) (key(A) <=  key(B))

#define exch(A, B) {Item t = A; A = B; B = t;}

#define cmpexch(A, B) {if(less(B, A)) exch(A, B)}

void merge(Item *v, int l, int r1, int r2){
    Item *v2 = malloc(sizeof(Item)*(r2-l+1));
    int k = 0;
    int i = l;
    int j = r1+1;
    while(i <= r1 && j <= r2){
        if(less(v[i], v[j]))
            v2[k++] = v[i++];
        else
            v2[k++] = v[j++];
    }
    while(i <= r1)
        v2[k++] = v[i++];

    while(j <= r2)
        v2[k++] = v[j++];

    k = 0;
    for(i = l; i <= r2; i++)
        v[i] = v2[k++];
    free(v2);
}

void mergesort(Item *v, int l, int r){
    if(l>=r)
        return;
    int meio = (r+l)/2;
    mergesort(v, l, meio);
    mergesort(v, meio+1, r);
    merge(v, l, meio, r);
}