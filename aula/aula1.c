#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{

     char *nome;
     float notas[2];

} Aluno;

float media(Aluno *a)
{
     return (a->notas[0] + a->notas[1]) / 2;
}

int main()
{
     Aluno *a1;

     a1 = (Aluno *)malloc(sizeof(Aluno));
     if (a1 == NULL)
     {
          exit(1);
     }
     a1->nome = (char *)malloc(50 * sizeof(char));
     if (a1->nome == NULL)
     {
          exit(1);
     }

     strcpy(a1->nome, "Ana");
     a1->notas[0] = 9.;
     a1->notas[1] = 7.;

     printf("%s: notas %.2f e %.2f com media = %.2f\n", a1->nome, a1->notas[0], a1->notas[1], media(a1));
     //printf("%s: notas %.2f e %.2f com media = %.2f\n", a2.nome, a2.notas[0], a2.notas[1], media(&a2));

     // questao1();

     free(a1);
     free(a1->nome);

     return 0;
}
