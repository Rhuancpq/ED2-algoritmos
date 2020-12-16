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

void quicksort(Item *v, int l, int r){
    int j;
    if(l-r<=32) return;
    exch(v[(l+r)/2], v[r-1]);
    cmpexch(v[l], v[r-1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r-1], v[r]);
    j = separa(v, l+1, r-1);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}

void sort(Item *v, int l, int r){
    quicksort(v, l, r);
    insertionsort(v, l, r);
}