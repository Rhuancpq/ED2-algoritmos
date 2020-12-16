#include <math.h>
#include <setjmp.h>
typedef int Item;

#define key(A) A

#define less(A, B) (key(A) <  key(B))

#define lessequal(A, B) (key(A) <=  key(B))

#define exch(A, B) {Item t = A; A = B; B = t;}

#define cmpexch(A, B) {if(less(B, A)) exch(A, B)}

int separa(Item *v, int l, int r){
    Item c = v[r];
    int j = l;
    for(int k = l; k < r; k++){
        if(lessequal(v[k], c)){
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

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

int quicktrapstop = 0;
jmp_buf env;
void quicksort(Item *v, int l, int r, int maxrec){
    int j;
    if(maxrec == 0){
        quicktrapstop = 1;
        longjmp(env, 1);
        return;
    }
    if(quicktrapstop == 1) return;
    if(l-r<=32) return;
    exch(v[(l+r)/2], v[r-1]);
    cmpexch(v[l], v[r-1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r-1], v[r]);
    j = separa(v, l+1, r-1);
    quicksort(v, l, j-1, maxrec-1);
    quicksort(v, j+1, r, maxrec-1);
}

void insertionsort(Item *v, int l, int r){ // [l,r]
    for(int i = r; i > l; i--){
        cmpexch(v[i-1], v[i]);
    }

    for(int i = l+2; i <= r; i++){
        int j = i;
        Item tmp = v[j];
        while(less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}


void introsort(Item *v, int l, int r){
    int maxrec = 2*log2((r-l+1));
    Setjmp(env);    
    if(quicktrapstop == 0)
        quicksort(v, l, r, maxrec);
    if(quicktrapstop == 1)
        mergesort(v, l, r);
    else
        insertionsort(v, l, r);
}