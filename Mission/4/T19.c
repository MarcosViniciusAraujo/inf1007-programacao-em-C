#include <stdio.h>

#define t 5
float serieHarmonica(int n)
{
     int i;

     if (n == 0)
     {
          return 0;
     }

     else
     {
          return (1.0 / n) + serieHarmonica(n - 1);
     }
}

int somaInteirosVetor(int vetor[], int n)
{
     if (n == 1)
     {
          return vetor[0];
     }

     else
     {
          return vetor[n - 1] + somaInteirosVetor(vetor, n - 1);
     }
}

int main()
{
     int serie = 7;
     float result1;

     int vetor[t] = {5, -3, -2, 2, 8};
     int result2;

     result1 = serieHarmonica(serie);

     printf("%.2f\n", result1);

     result2 = somaInteirosVetor(vetor, t);

     printf("%d", result2);

     return 0;
}