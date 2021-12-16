/***********************************************************************
NOME COMPLETO : Marcos Vinicius Araujo Almeida 
MATRICULA PUC-Rio: 1910869
DATA : 25/06/2020
DISCIPLINA : INF1007 TURMA (33A, 33B): 33A
DECLARACAO DE AUTORIA :
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento Elemento;
struct elemento
{

     int info;
     Elemento *prox;
};

typedef struct pilha Pilha;
struct pilha
{
     Elemento *topo;
};

int vazio(Pilha *p)
{
     if (p->topo == NULL)
          return 1;
     return 0;
}

Pilha *cria()
{
     Pilha *p = (Pilha *)malloc(sizeof(Pilha));
     if (p == NULL)
     {
          exit(1);
     }

     p->topo = NULL;

     return p;
}

void push(Pilha *p, int a)
{
     Elemento *n = (Elemento *)malloc(sizeof(Elemento));
     if (n == NULL)
     {
          exit(1);
     }
     n->info = a;
     n->prox = p->topo;
     p->topo = n;
}

int pop(Pilha *p)
{
     Elemento *t;
     int v;
     if (vazio(p))
     {
          exit(1);
     }

     t = p->topo;
     v = t->info;
     p->topo = t->prox;
     free(t);
     return v;
}

void libera(Pilha *p)
{
     Elemento *t, *q = p->topo;

     while (q != NULL)
     {
          t = q->prox;
          free(q);
          q = t;
     }

     free(p);
}

Pilha *pilhaNumInteiro(char *s)
{
     Pilha *p = cria();
     int i;
     char a;
     int b;
     for (i = 0; *(s + i); i++)
     {
          a = *(s + i);
          b = a - '0';
          push(p, b);
     }

     return p;
}

void exibeSomaNumPilha(char *n1, char *n2)
{
     Pilha *soma = cria();
     Pilha *pilha_n1;
     Pilha *pilha_n2;
     int vai = 0;

     //numeros já se encontram na pilha
     pilha_n1 = pilhaNumInteiro(n1);
     pilha_n2 = pilhaNumInteiro(n2);

     while (!vazio(pilha_n1) && !vazio(pilha_n2))
     {
          int fator1 = pop(pilha_n1);
          int fator2 = pop(pilha_n2);
          int result = vai + fator1 + fator2;

          if (result >= 10)
          {
               push(soma, result % 10);
               vai = result / 10;
          }

          else
          {
               push(soma, result);
               vai = 0;
          }
     }

     int c;
     if (!vazio(pilha_n1))
     {
          libera(pilha_n2);

          while (!vazio(pilha_n1))
          {
               c = vai + pop(pilha_n1);
               push(soma, c);
               vai = 0;
          }
     }

     if (!vazio(pilha_n2))
     {
          libera(pilha_n1);

          while (!vazio(pilha_n2))
          {
               c = vai + pop(pilha_n2);
               push(soma, c);
               vai = 0;
          }
     }

     printf("Resultado: ");

     while (!vazio(soma))
     {
          int saida = pop(soma);
          printf("%d", saida);
     }

     printf("\n");

     libera(soma);
}

int main()
{

     //teste 1

     char n1_t1[] = "100000";
     char n2_t1[] = "138139";
     printf("Teste 1: ");
     printf("%s  +  %s\n", n1_t1, n2_t1);
     exibeSomaNumPilha(n1_t1, n2_t1);
     printf("======================================\n");

     //teste 2

     char n1_t2[] = "7340913232";
     char n2_t2[] = "1274385942";
     printf("Teste 2: ");
     printf("%s  +  %s\n", n1_t2, n2_t2);
     exibeSomaNumPilha(n1_t2, n2_t2);
     printf("=========================================\n");

     //teste 3

     char n1_t3[] = "37";
     char n2_t3[] = "2783";
     printf("Teste da figura: ");
     printf("%s  +  %s\n", n1_t3, n2_t3);
     exibeSomaNumPilha(n1_t3, n2_t3);
     printf("========================================\n");
     return 0;
}
