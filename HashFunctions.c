#define hash(v, m) ((618033* (unsigned) v) % m)

int hashU(char *v, int M){
    int h, a =31415, b = 27183;
    for(h = 0; *v != '\0'; v++){
        a = a*b % (M-1);
        h = (a*h+*v) % M;
    }
    return h;
}

