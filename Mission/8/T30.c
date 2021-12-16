#include <stdio.h>
#include <stdlib.h>

typedef struct retangulo Retangulo;
struct retangulo
{
     float w;
     float h;
};

typedef struct no No;
struct no
{
     Retangulo *ret;
     No *prox;
};

No *cria()
{
     return NULL;
}

No *insere(No *lst, float w, float h)
{
     No *novo = (No *)malloc(sizeof(No));

     novo->ret = (Retangulo *)malloc(sizeof(Retangulo));

     novo->ret->h = h;
     novo->ret->w = w;
     novo->prox = lst;
     return novo;
}

void exibeLista(No *lst)
{
     if (lst == NULL)
     {
          printf("");
     }

     else
     {
          printf("W: %.2f  H: %.2f\n", lst->ret->w, lst->ret->h);
          exibeLista(lst->prox);
     }
}

float areaTotal(No *lst)
{

     if (lst == NULL)
     {
          return 0.0;
     }

     else
     {
          float area = areaTotal(lst->prox);

          return area + ((lst->ret->w) * (lst->ret->h));
     }
}

void libera(No *lst)
{
     if (lst == NULL)
     {

          free(lst);
     }

     else
     {
          free(lst->ret);
          libera(lst->prox);
     }
}

int main()
{
     No *lst = cria();
     float area;

     lst = insere(lst, 10, 2);
     lst = insere(lst, 1, 2);
     lst = insere(lst, 3, 4);
     lst = insere(lst, 6, 5);
     lst = insere(lst, 9, 2);
     lst = insere(lst, 1, 10);

     exibeLista(lst);

     area = areaTotal(lst);

     printf("Area: %.2f\n", area);

     libera(lst);
     free(lst);

     printf("A memoria foi liberada");

     return 0;
}