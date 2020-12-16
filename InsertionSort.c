typedef int Item;

#define key(A) A

#define less(A, B) (key(A) <  key(B))

#define exch(A, B) {Item t = A; A = B; B = t;}

#define cmpexch(A, B) {if(less(B, A)) exch(A, B)}

void insertionsort_slow(Item *v, int l, int r){ // [l,r]
    for(int i = l+1; i <= r; i++){
        for(int j = i; j > l; j--){
            cmpexch(v[j], v[j-1]);
        }
    }
}

void insertionsort_fast(Item *v, int l, int r){ // [l,r]
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

int main(){
    return 0;
}