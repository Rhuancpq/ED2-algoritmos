typedef int Item;

#define key(A) A

#define less(A, B) (key(A) <  key(B))

#define exch(A, B) {Item t = A; A = B; B = t;}

#define cmpexch(A, B) {if(less(B, A)) exch(A, B)}

void bubblesort(Item *v, int l, int r){ // [l, r]
    for(int i = l; i < r; i++){
        int t = 0;
        for(int j = l; j < r; j++){
            if(less(v[j+1], v[j])){
                exch(v[j+1], v[j]);
                t += 1;
            }
        }
        if(t == 0)
            break;
    }
} 

int main(){
    return 0;
}