#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct elemento
{
     int info;
     struct Elemento *prox;
};

typedef struct elemento Elemento;

struct pilha
{
     Elemento *prim;
};

Pilha *cria()
{
     Pilha *p = (Pilha *)malloc(sizeof(Pilha));
     if (p == NULL)
     {
          exit(1);
     }

     p->prim = NULL;

     return p;
}

void push(Pilha *p, int digito)
{
     Elemento *n = (Elemento *)malloc(sizeof(Elemento));
     if (n == NULL)
     {
          exit(1);
     }
     n->info = digito;
     n->prox = p->prim;
     p->prim = n;
}

int pop(Pilha *p)
{
     Elemento *t;
     int v;
     if (vazio(p))
     {
          exit(1);
     }

     t = p->prim;
     v = t->info;
     p->prim = t->prox;
     free(t);
     return v;
}

int vazio(Pilha *p)
{
     if (p->prim == NULL)
          return 1;
     return 0;
}

void libera(Pilha *p)
{
     Elemento *t, *q = p->prim;

     while (q != NULL)
     {
          t = q->prox;
          free(q);
          q = t;
     }

     free(p);
}

void exibePilha(Pilha *p)
{
     Elemento *t = p->prim;

     while (t != NULL)
     {

          printf("Info: %d", t->info);

          t = t->prox;
     }
}