#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct noLista NoLista;
struct noLista
{
     int codigo;
     char nome[51];
     NoLista *prox;
};

NoLista *insere(NoLista *lst, int cod, char *nome)
{
     NoLista *novo;
     novo = (NoLista *)malloc(sizeof(NoLista));

     novo->codigo = cod;
     strcpy(novo->nome, nome);
     novo->prox = lst;

     return novo;
}

void exibe(NoLista *lst)
{

     NoLista *p;

     for (p = lst; p != NULL; p = p->prox)
     {

          printf("Nome: %s    Code: %d", p->nome, p->codigo);
     }
}

NoLista *lst_insere_ordenado(NoLista *lst, int cod, char *nome)
{
     NoLista *novo;
     NoLista *a = NULL; /* ponteiro para elemento anterior */
     NoLista *p = lst;  /* ponteiro para percorrer a lista */
     /* procura posição de inserção */
     while (p != NULL && p->codigo < cod)
     {
          a = p;
          p = p->prox;
     }

     /* cria novo elemento */
     novo = (NoLista *)malloc(sizeof(NoLista));
     novo->codigo = cod;
     strcpy(novo->nome, nome);

     /* encadeia elemento */
     if (a == NULL)
     { /* insere elemento no início */
          novo->prox = lst;
          lst = novo;
     }

     else
     { /* insere elemento no meio da lista */
          novo->prox = a->prox;
          a->prox = novo;
     }
     return lst;
}

bool busca(NoLista *lst1, int cod)
{

     NoLista *p;

     for (p = lst1; p != NULL; p = p->prox)
     {
          if (p->codigo = cod)
          {

               return true;
          }
     }

     return false;
}

NoLista *mergeListas(NoLista *lst1, NoLista *lst2)
{
     NoLista *p, *t;
     NoLista *novo = NULL;

     while (1)
     {
     }
}

int main()
{
     NoLista *lst1 = NULL, *lst2 = NULL;

     NoLista *result = NULL;

     lst1 = insere(lst1, 111, "leo");
     lst1 = insere(lst1, 333, "rui");
     lst1 = insere(lst1, 446, "cris");
     lst1 = insere(lst1, 558, "lara");
     lst1 = insere(lst1, 666, "cadu");
     lst1 = insere(lst1, 777, "rosa");
     lst1 = insere(lst1, 999, "bia");

     lst2 = insere(lst2, 111, "leo");
     lst2 = insere(lst2, 333, "rui");
     lst2 = insere(lst2, 440, "edu");
     lst2 = insere(lst2, 554, "vera");
     lst2 = insere(lst2, 777, "rosa");
     lst2 = insere(lst2, 888, "lia");

     result = mergeListas(lst1, lst2);

     exibe(result);

     return 0;
}
