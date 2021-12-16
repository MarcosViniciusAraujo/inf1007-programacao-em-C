#include <stdlib.h>
#include <stdio.h>

#define num 3

int* pares(int *v, int tamanho, int *n_pares){
     int i, j;
     int *v_pares;

     *n_pares = 0;

     for (i = 0; i < tamanho ; i++){
          if (v[i] %2 == 0){
               *n_pares += 1;
          }
     }


     v_pares = (int*) malloc(*n_pares* sizeof(int));

     if(v_pares == NULL){
          printf("Não há memória sufuciente");
          exit(1);
     }

     j = 0;

     for (i = 0; i < tamanho; i++){
          if (v[i] %2 == 0){
               v_pares[j] = v[i];
               j++;
          }
     }

     return v_pares;

}

void PrintVector (int *v, int n){
     int i;

     for (i = 0; i < n; i++){
          printf("%d  ", v[i]);
     }
}

int main (){
     int n_pares , i;
     int v[num], *v_pares;

     for (i = 0; i < num; i++){
          printf("Digite o valor %d do vetor: ", i+1 );
          scanf("%d", &v[i]);
     }

     v_pares = pares(v, num, &n_pares);

     PrintVector(v_pares, n_pares);

     if (n_pares == 0){
          printf("Não há pares");

     }

     else {
          printf("\nCom o total de %d pares", n_pares);
     }
     free(v_pares);
     return 0;

}