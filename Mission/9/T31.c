#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no No;
struct no
{
     char a;
     No *prox;
};

typedef struct pilha Pilha;
struct pilha
{
     No *prim;
};

int pilha_vazia(Pilha *p)
{
     if (p->prim == NULL)
          return 1;
     return 0;
}

Pilha *pilha_cria(void)
{
     Pilha *p = (Pilha *)malloc(sizeof(Pilha));
     if (p == NULL)
          exit(1);
     p->prim = NULL;
     return p;
}

void pilha_push(Pilha *p, char v)
{
     No *n = (No *)malloc(sizeof(No));
     if (n == NULL)
          exit(1);
     n->a = v;
     n->prox = p->prim;
     p->prim = n;
}

char pilha_pop(Pilha *p)
{
     No *t;
     float v;
     if (pilha_vazia(p))
          exit(1); /* aborta programa */
     t = p->prim;
     v = t->a;
     p->prim = t->prox;
     free(t);
     return v;
}

void pilha_libera(Pilha *p)
{
     No *t, *q = p->prim;
     while (q != NULL)
     {
          t = q->prox;
          free(q);
          q = t;
     }
     free(p);
}

char *inverte(char nome[])
{

     Pilha *p = pilha_cria();
     int i;
     char *result;
     result = (char *)malloc((strlen(nome) + 1) * sizeof(char));

     for (i = 0; nome[i]; i++)
     {
          pilha_push(p, nome[i]);
     }

     while (!pilha_vazia(p))
     {
          char c = pilha_pop(p);

          strcpy(result, c);
     }

     return result;
}

int main()
{
     char nome[] = "Marcos";
     char *invertido;

     invertido = inverte(nome);

     printf("%s\n", invertido);

     return 0;
}