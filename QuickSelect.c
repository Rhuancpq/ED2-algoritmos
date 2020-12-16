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

void quickselect(Item *v, int l, int r, int k){
    cmpexch(v[(l+r)/2], v[r]);
    cmpexch(v[l], v[(l+r)/2]);
    cmpexch(v[r], v[(l+r)/2]);
    int i;
    i = separa(v, l, r);
    if(i > k) quickselect(v,l,i-1, k);
    if(i < k) quickselect(v, i+1, r, k);
}