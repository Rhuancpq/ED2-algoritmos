#include <stdio.h>
#include <stdlib.h>

# define PRIMO 262139

int hashN(int n){
    return n%PRIMO;
}

int main(void){
    int v[PRIMO];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        v[hashN(t)] = t;
    }
    int c;
    while(scanf("%d", &c)==1){
        int t = hashN(c);
        if(v[t] == c)
            printf("Numero proibid\n");
        else if(v[t] == 0)
            printf("não\n");
        else if(v[t] != c)
            printf("Colisão socorro");
    }
    
    return 0;
}