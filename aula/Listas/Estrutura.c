#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidato
{
     int inscr;
     char nome[51];
     int idade;
     float nota;
} Candidato;

Candidato *criaCandidato(int inscr, char nome[51], int idade, float nota)
{

     Candidato *c;

     c = (Candidato *)malloc(sizeof(Candidato));
     if (c == NULL)
          return NULL;

     strcpy(c->nome, nome);
     c->idade = idade;
     c->inscr = inscr;
     c->nota = nota;

     return c;
}

void exibeCandidato(Candidato **v, int n)
{
     int i;

     for (i = 0; i < n; i++)
     {

          printf("Nome: %s  Idade: %d  Nota: %.2f  Inscr: %d\n", v[i]->nome, v[i]->idade, v[i]->nota, v[i]->inscr);
     }
}

Candidato *buscaCandidato(Candidato **v, int n, int inscr)
{

     int i;

     for (i = 0; i < n; i++)
     {
          if (v[i]->inscr == inscr)
               return v[i];
     }

     return NULL;
}

int main()
{

     Candidato **cand;
     int id;
     Candidato *achado;
     int i, n = 5;

     cand = (Candidato **)malloc(n * sizeof(Candidato *));

     cand[0] = criaCandidato(1, "Marcos", 19, 9.0);
     cand[1] = criaCandidato(2, "Rafaela", 23, 8.0);
     cand[2] = criaCandidato(3, "Eduardo", 17, 7.0);
     cand[3] = criaCandidato(4, "Isabela", 27, 5.0);
     cand[4] = criaCandidato(5, "Alberto", 15, 3.0);

     exibeCandidato(cand, n);

     printf("Digite o ID: ");
     scanf("%d", &id);

     achado = buscaCandidato(cand, n, id);

     if (achado == NULL)
     {
          printf("Usuario não achado");
     }

     else
     {
          printf("\nNome: %s Idade: %d  Nota: %.2f", achado->nome, achado->idade, achado->nota);
     }

     for (i = 0; i < n; i++)
     {

          free(cand[i]);
     }

     free(cand);
     free(achado);
     return 0;
}