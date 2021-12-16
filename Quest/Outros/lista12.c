#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
struct no
{
     int codigo; /* pode haver codigos repetidos */
     int quantidade;
     No *prox;
};

No *insere(No *lst, int cod, int qto)
{
     No *novo = (No *)malloc(sizeof(No));

     novo->codigo = cod;
     novo->quantidade = qto;
     novo->prox = lst;

     return novo;
}

No *colocaVetor(No *lst, int vetor[10][2])
{
     int i;
     for (i = 0; i < 10; i++)
     {
          lst = insere(lst, vetor[i][0], vetor[i][1]);
     }

     return lst;
}

void exibe(No *lst)
{

     No *p;
     for (p = lst; p != NULL; p = p->prox)
     {

          printf("Cod.: %d    Qto.: %d\n", p->codigo, p->quantidade);
     }
}

int buscaPosicao(No *lst, int pos)
{
     int cont = 1;
     No *p;
     for (p = lst; p != NULL; p = p->prox)
     {
          if (cont == pos)
          {
               return p->codigo;
          }
          cont++;
     }

     return -1;
}

int main()
{

     No *lst = NULL;
     int cod;
     int vetor[10][2] = {{444, 13},
                         {888, 34},
                         {222, 21},
                         {444, 13},
                         {444, 18},
                         {555, 10},
                         {222, 15},
                         {999, 25},
                         {444, 10},
                         {222, 30}};

     lst = colocaVetor(lst, vetor);

     exibe(lst);

     cod = buscaPosicao(lst, 6);

     printf("Pos: %d", cod);

     return 0;
}