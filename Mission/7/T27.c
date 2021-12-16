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

int compara_1(Dado *p, float altura, float peso)
{
     if (p->altura < altura)
          return 1;
     if (p->altura > altura)
          return -1;
     if (p->peso < peso)
          return 1;
     if (p->peso > peso)
          return -1;
     return 0;
}

char *busca(Dado *d[], int n, float altura, float peso)
{
     int ini = 0;
     int fim = n - 1;
     char *name;
     name = (char *)malloc(100 * sizeof(char));

     while (ini <= fim)
     {
          int meio = (ini + fim) / 2;

          if (compara_1(d[meio], altura, peso) == -1)
          {
               fim = meio - 1;
          }

          else if (compara_1(d[meio], altura, peso) == 1)
          {
               ini = meio + 1;
          }

          else
          {
               if (compara_1(d[meio], altura, peso) == 0)
               {
                    //printf("Nome: %s", d[meio].nome);

                    strcpy(name, d[meio]->nome);
                    return name;
               }

               else
               {
                    strcpy(name, "Usuario nao encontrado");
                    return name;
               }
          }
     }

     //strcpy(name,"Usuario nao encontrado");
}

int main()
{
     char *nome;
     char exibeNome[100];

     float altura = 1.80;
     float peso = 75;

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

     nome = busca(v, 8, altura, peso);
     strcpy(exibeNome, nome);
     printf("Altura procurada: %.2f\nPeso procurado: %.1f\n", altura, peso);
     printf("Achado: %s", exibeNome);

     free(nome);

     return 0;
}