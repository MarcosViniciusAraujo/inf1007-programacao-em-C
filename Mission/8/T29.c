#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*Falei com professor por email e, ele deixou que eu usasse a biblioteca stdbool.io 
para deixar o código um pouco melhor de se ler. */

typedef struct no No;
struct no
{

     int value;
     No *prox;
};

No *cria()
{

     return NULL;
}

No *insere(No *lst, int n)
{
     No *novo = (No *)malloc(sizeof(No));

     novo->value = n;
     novo->prox = lst;

     return novo;
}

bool busca(No *lst, int n)
{
     No *p;
     for (p = lst; p != NULL; p = p->prox)
     {
          if (p->value == n)
               return true;
     }
     return false;
}

No *retira(No *lst, int compara)
{

     No *a = NULL;
     No *p = lst;

     while (p != NULL && p->value != compara)
     {
          a = p;
          p = p->prox;
     }

     if (p == NULL)
          return lst;
     if (a == NULL)
          lst = p->prox;
     else
          a->prox = p->prox;
     free(p);
     return lst;
}

void exibeLista(No *lst)
{
     No *p;
     for (p = lst; p != NULL; p = p->prox)
     {
          printf("%d\n", p->value);
     }
}

No *removeEscolha(No *lst, int compara, int *ocorre)
{
     int cont = 0;
     while (busca(lst, compara))
     {
          lst = retira(lst, compara);
          cont++;
     }
     *ocorre = cont;
     return lst;
}

int main()
{
     int ocorre;
     No *lst = cria();

     lst = insere(lst, 2);
     lst = insere(lst, 2);
     lst = insere(lst, 1);
     lst = insere(lst, 2);
     lst = insere(lst, 3);
     lst = insere(lst, 4);

     exibeLista(lst);

     lst = removeEscolha(lst, 2, &ocorre);

     printf("Depois...\n\n");
     exibeLista(lst);
     printf("Foram retiradas %d ocorrencias", ocorre);

     return 0;
}