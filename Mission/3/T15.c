#include <stdio.h>
#include <stdlib.h>

float* reverse (int *v, int n){
     int *v_invert = (int*) malloc(n*sizeof(int));
     int i, j = 0;

     if (v_invert == NULL){
          printf("Não há memória suficiente");
          exit(1);
     }

     for (i = n-1 ; i>=0 ; i--){
          v_invert[j] = v[i];
          j++;
     }
     return v_invert;
}

void print_vector(int *v, int n ){
     int i;

     for (i=0 ; i < n; i++){
          printf("%d  ", v[i]);
     }
}

int main (){
     int *vector, *vector_novo;
     int  i, n;

     printf("Dgite o tamanho do vetor: ");
     scanf("%d", &n);

     vector = (int *) malloc(n* sizeof(int));

     if (vector == NULL){
          printf("Não há memória");
          exit(1);
     }

     for (i = 0; i <n ; i++){
          printf("Digite o valor %d do vetor: ", i+1);
          scanf("%d", &vector[i]);
     }

     vector_novo = reverse( vector, n);
     print_vector(vector_novo , n);


     free(vector);
     free(vector_novo);

     return 0;

}