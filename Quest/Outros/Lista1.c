#include <stdio.h>
#include <stdlib.h>

typedef struct informacao Informacao;
struct informacao
{
     int codigo;
     char nome[31];
};

typedef struct no No;
struct no
{
     Informacao *info;
     No *prox;
};

No *quebraAoMeio(No *lst);

int main()
{

     return 0;
}

No *quebraAoMeio(No *lst)
{
     No *p, *t;
     int cont, i;

     for (p = lst; p != NULL; p = p->prox)
     {
          cont++;
     }

     if (cont < 2)
          return NULL;

     if (cont % 2 == 0)
          cont = cont / 2;

     else
          cont = cont / 2 + 1;

     for (t = lst; i < cont; t = t->prox)
     {

          i++;
     }

     t = p->prox;

     t->prox = NULL;
}