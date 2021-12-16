#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente Cliente;
struct cliente
{
     char nome[51];
     float depos;
};

typedef struct lista Lista;
struct lista
{
     Cliente *info;
     struct lista *prox;
};

typedef struct fila Fila;
struct fila
{
     Lista *ini;
     Lista *fim;
};

Fila *fila_cria(void)
{
     Fila *f = (Fila *)malloc(sizeof(Fila));
     f->ini = f->fim = NULL;
     return f;
}

void fila_insere(Fila *f, Cliente *v)
{
     Lista *n = (Lista *)malloc(sizeof(Lista));

     strcpy(n->info->nome, v->nome);
     n->info->depos = v->depos;

     n->prox = NULL;     /* novo nó passa a ser o último */
     if (f->fim != NULL) /* verifica se lista não vazia */
          f->fim->prox = n;
     else /* fila estava vazia */
          f->ini = n;
     f->fim = n; /* fila aponta para novo elemento */
}

Cliente *fila_retira(Fila *f)
{
     Lista *t;
     Cliente *v = (Cliente *)malloc(sizeof(Cliente));

     if (fila_vazia(f))
     {
          printf("Fila vazia.\n");
          exit(1); /* aborta programa */
     }
     t = f->ini;
     strcpy(v->nome, t->info->nome);
     v->depos = t->info->depos;
     f->ini = t->prox;
     if (f->ini == NULL) /* verifica se fila ficou vazia */
          f->fim = NULL;
     free(t);
     return v;
}

void fila_libera(Fila *f)
{
     Lista *q = f->ini;
     while (q != NULL)
     {
          Lista *t = q->prox;
          free(q);
          q = t;
     }
     free(f);
}

void exibeCliente(Cliente *c)
{
     printf("Nome: %s\nDeposito: R$%.2f", c->nome, c->depos);
     printf("\n\n");
}

float atendimentoCaixaBanco(Fila *f, int *i)
{
     int n = 0;
     Cliente *c;
     float total_money = 0.0;

     while (n < i)
     {
          c = fila_retira(f);
          printf("fila: %d\n", n + 1);
          exibeCliente(c);
          total_money += c->depos;
          n++;
     }

     return total_money;
}

int main()
{

     return 0;
}