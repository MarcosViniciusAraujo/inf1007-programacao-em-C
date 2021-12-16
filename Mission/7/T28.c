#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pd 12

typedef struct dado
{
     char nome[26];
     float altura;
     float peso;
} Dado;

void exibeEspaco(int n)
{

     int i;

     for (i = 0; i < n; i++)
     {
          printf(" ");
     }
}

void exibeVetor(Dado *d[], int n)
{
     int i;
     int branco;

     for (i = 0; i < n; i++)
     {
          printf("%s", d[i]->nome);
          branco = pd - strlen(d[i]->nome);
          exibeEspaco(branco);
          printf("%.2f %.2f\n", d[i]->altura, d[i]->peso);
     }
}

int compara_1(float n1, float n2)
{
     if (n1 < n2)
          return 1;
     if (n1 > n2)
          return -1;
     return 0;
}

int busca(Dado *d[], int n, float altura)
{
     int ini = 0;
     int fim = n - 1;
     int indice;

     while (ini <= fim)
     {
          int meio = (ini + fim) / 2;
          if (compara_1(d[meio]->altura, altura) == -1)
          {

               fim = meio - 1;
          }

          else if (compara_1(d[meio]->altura, altura) == 1)
          {

               ini = meio + 1;
          }

          else
          {
               while ((meio > 0) && compara_1(d[meio - 1]->altura, altura) == 0)
               {
                    meio--;
               }

               return meio;
          }
     }

     return 0;
}

int main()
{
     int i;

     Dado d[] = {
         {"Leo", 1.70, 70},
         {"Eva", 1.70, 75},
         {"Ana", 1.80, 40},
         {"Turing", 1.80, 50},
         {"Luiza", 1.80, 75},
         {"Lovelace", 1.90, 60},
         {"Sato", 2.0, 50},
         {"Duda", 2.0, 55}

     };

     Dado *v[] = {d, d + 1, d + 2, d + 3, d + 4, d + 5, d + 6, d + 7};

     exibeVetor(v, 8);

     i = busca(v, 8, 1.70);
     printf("Achado: %s", d[i].nome);

     return 0;
}