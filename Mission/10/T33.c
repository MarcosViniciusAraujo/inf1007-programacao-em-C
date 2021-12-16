#include <stdio.h>
#include <stdlib.h>

#define N 100 /* número máximo de elementos */
typedef struct fila Fila;
struct fila
{
     int n;   /* número de elementos na fila */
     int ini; /* posição do próximo elemento a ser retirado da fila */
     int vet[N];
};

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

Fila *fila_cria(void)
{
     Fila *f = (Fila *)malloc(sizeof(Fila));
     f->n = 0;   /* inicializa fila como vazia */
     f->ini = 0; /* escolhe uma posição inicial */
     return f;
}

void fila_insere(Fila *f, int v)
{
     int fim;
     if (f->n == N)
     { /* fila cheia: capacidade esgotada */
          printf("Capacidade da fila estourou.\n");
          exit(1); /* aborta programa */
     }
     /* insere elemento na próxima posição livre */
     fim = (f->ini + f->n) % N;
     f->vet[fim] = v;
     f->n++;
}

int fila_retira(Fila *f)
{
     int v;
     if (fila_vazia(f))
     {
          printf("Fila vazia.\n");
          exit(1); /* aborta programa */
     }
     /* retira elemento do início */
     v = f->vet[f->ini];
     f->ini = (f->ini + 1) % N;
     f->n--;
     return v;
}

int fila_vazia(Fila *f)
{
     return (f->n == 0);
}

int tamanho_fil(Fila *f)
{

     return f->n;
}

int vazio(Pilha *p)
{
     if (p->topo == NULL)
          return 1;
     return 0;
}

void inverte_fila(Fila *f)
{
     Pilha *p = cria();
     int n = 0;

     while (n < tamanho_fil(f))
     {
          int v = fila_retira(f);
          fila_insere(f, v);
          push(p, v);
          n++;
     }

     while (!vazio(p))
     {

          fila_insere(f, pop(p));
     }
}

int main()
{

     Fila *f = fila_cria();

     fila_insere(f, 1);
     fila_insere(f, 2);
     fila_insere(f, 3);

     inverte_fila(f);

     while (!fila_vazia(f))
     {

          printf("%d", fila_retira(f));
     }

     return 0;
}