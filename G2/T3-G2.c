/***********************************************************************
NOME COMPLETO : Marcos Vinicius Araujo Alemida
MATRICULA PUC-Rio: 1910869
DATA : 02/07/2020
DISCIPLINA : INF1007 TURMA (33A, 33B): 33A
DECLARACAO DE AUTORIA :
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
typedef struct fila Fila;
struct fila
{
     int n;
     int ini;
     char vet[N];
};

int fila_vazia(Fila *f)
{
     return (f->n == 0);
}

int ehVogal(char c)
{
     if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
     {
          return 1;
     }

     return 0;
}

Fila *fila_cria(void)
{
     Fila *f = (Fila *)malloc(sizeof(Fila));
     f->n = 0;
     f->ini = 0;
     return f;
}

void fila_insere(Fila *f, char v)
{
     int fim;
     if (f->n == N)
     {
          printf("Capacidade da fila estourou.\n");
          exit(1);
     }

     fim = (f->ini + f->n) % N;
     f->vet[fim] = v;
     f->n++;
}

char fila_retira(Fila *f)
{
     char v;
     if (fila_vazia(f))
     {
          printf("Fila vazia.\n");
          exit(1);
     }

     v = f->vet[f->ini];
     f->ini = (f->ini + 1) % N;
     f->n--;
     return v;
}

void separaFila(Fila *mensagem, Fila *vogais, Fila *cons)
{
     char c;
     while (!fila_vazia(mensagem))
     {
          c = fila_retira(mensagem);

          if (c == ' ')
          {
               fila_insere(cons, '_');
          }

          else if (ehVogal(c) == 1)
          {
               fila_insere(vogais, c);
               fila_insere(cons, '*');
          }

          else
          {
               fila_insere(cons, c);
          }
     }
}

Fila *StringParaFila(char *s)
{
     Fila *saida = fila_cria();
     int i;

     for (i = 0; s[i]; i++)
     {
          fila_insere(saida, s[i]);
     }

     return saida;
}

void exibeFila(Fila *f)
{
     char c;
     while (!fila_vazia(f))
     {
          c = fila_retira(f);
          printf("%c", c);
     }

     printf("\n\n");
}

void exibeResultados(char *string)
{

     Fila *mensagem;
     Fila *vogais = fila_cria();
     Fila *consoantes = fila_cria();

     printf("Mensagem--> %s\n\n", string);
     mensagem = StringParaFila(string);

     separaFila(mensagem, vogais, consoantes);
     printf("Vogais--> ");
     exibeFila(vogais);
     printf("Consoantes--> ");
     exibeFila(consoantes);

     free(vogais);
     free(consoantes);
     free(mensagem);
}

int main()
{
     char *string1 = "ola mundo";
     char *string2 = "ieaiaio";
     char *string3 = "mrghk";

     printf("============================================\n\n");
     //teste1
     printf("Teste 1: \n\n");
     exibeResultados(string1);

     printf("============================================\n\n");

     //teste2
     printf("Teste 2: \n\n");
     exibeResultados(string2);

     printf("============================================\n\n");

     //teste3
     printf("Teste 3: \n\n");
     exibeResultados(string3);

     printf("============================================\n\n");

     return 0;
}