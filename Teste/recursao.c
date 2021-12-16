#include <stdio.h>

int fatorial (int num){
    if (num == 1) {
        return 1;
    }
    else{
        return num * fatorial (num-1);
    }
}

int main (void){
    
    printf( "%d\n", fatorial(5));

    return 0;
}