#include <stdlib.h>
#include <stdio.h>

typedef struct elemento Elemento;
struct elemento
{
     int info;
     Elemento *prox;
};

typedef struct pilha Pilha;
struct pilha
{
     Elemento *prim;
};

int vazio(Pilha *p)
{
     if (p->prim == NULL)
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

          printf("Info: %d\n", t->info);

          t = t->prox;
     }

     printf("\n");
}
Pilha *mixStacks(Pilha *p1, Pilha *p2)
{
     Pilha *nova = cria();
     Pilha *nova_invertida = cria();
     Pilha *pa1 = cria();
     Pilha *pa2 = cria();
     int saida1, saida2;

     while (!vazio(p1) && !vazio(p2))
     {
          saida1 = pop(p1);
          push(nova, saida1);
          saida2 = pop(p2);
          push(nova, saida2);
     }

     while (!vazio(p1))
     {
          saida1 = pop(p1);
          push(nova, saida1);
     }

     while (!vazio(p2))
     {
          saida2 = pop(p2);
          push(nova, saida2);
     }

     // inverter a pilha

     while (!vazio(nova))
     {
          push(nova_invertida, pop(nova));
     }
     return nova_invertida;
}

int main()
{

     Pilha *p1 = cria(), *p2 = cria(), *nova;

     push(p1, 9);
     push(p1, 5);
     push(p1, 8);
     push(p1, -1);
     push(p1, 4);

     push(p2, 10);

     push(p2, 50);

     exibePilha(p1);

     exibePilha(p2);

     nova = mixStacks(p1, p2);

     exibePilha(nova);

     libera(p1);
     libera(p2);
     libera(nova);
     return 0;
}