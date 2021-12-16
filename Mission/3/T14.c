#include <stdio.h>
#define num 2

void reverse (float v[] , int n){
     int i, cont;
     float el;

     cont = 0;

     for (i = n-1; i > cont; i--){
          el = v[cont];
          v[cont] = v[i];
          v[i] = el;

          cont++;
     }
}

void p_vector (float *v, int n ){
     int i;

     for (i = 0; i<n; i++){
          printf("%f\n", v[i]);
     }

}

int main (void){
     float v[num] ={2.0 ,1.0};

     reverse(v, num);

     p_vector(v,num);
     
     return 1;
}