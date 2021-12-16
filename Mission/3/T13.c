#include <stdio.h>

void maxmin (int v[] , int n , int *maior, int *menor){
     int i;

     for (i=0 ; i < n ; i++){
          if ( v[i] > *maior )
               *maior = v[i] ;
          
          if ( v[i] < *menor )
               *menor = v[i];

     }
}

int main (){
     int n , i, maior,menor, el;
     int v[10];

     printf("Tamanho do vetor (max 10): ");
     scanf("%d", &n);


     for (i=0 ; i < n ;i++){

          printf("Digite o elementos: ");
          scanf("%d", &el);

          v[i] = el;

     }

     maxmin(v, n , &maior ,&menor);

     printf("Maior: %d\nMenor: %d", maior , menor);

     return 0;

}