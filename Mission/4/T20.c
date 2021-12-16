#include <stdio.h>
#define N 4

int somaPares(int vetor[], int n)
{
     //if (n == 0)
     //{
     //     return 0;
     // }

     if (n == 1)
     {
          if (vetor[0] % 2 == 0)
          {
               return vetor[0];
          }
          else
          {

               return 0;
          }
     }

     else
     {
          if (vetor[n - 1] % 2 == 0)
          {
               return vetor[n - 1] + somaPares(vetor, n - 1);
          }

          else
          {
               return somaPares(vetor, n - 1);
          }
     }
}

int somaDigitos(int n)
{

     int divInteira = n / 10;
     int resto = n % 10;

     if (n < 10)
     {
          return n;
     }

     else
     {
          return resto + somaDigitos(divInteira);
     }
}

int main()
{

     int result;
     int vetor[N] = {1, 2, 3, 4};
     int num = 3651;

     result = somaPares(vetor, N);

     printf("%d\n", result);

     printf("%d", somaDigitos(num));

     return 0;
}
