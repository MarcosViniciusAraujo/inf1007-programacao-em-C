#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pedido Pedido;
struct pedido
{
     int matricula;         /* matricula do aluno que solicita a bolsa */
     char tipoDoPedido[21]; /* “soc”, “ic”, “mest”, “dout” */
     struct pedido *prox;   /* ponteiro para o proximo pedido */
};

Pedido *insere(Pedido *lst, int mat, char *tipo)
{

     Pedido *novo;
     novo = (Pedido *)malloc(sizeof(Pedido));

     novo->matricula = mat;
     strcpy(novo->tipoDoPedido, tipo);
     novo->prox = lst;
     return novo;
}

int maiorMatricula(Pedido *lst)
{
     int m;

     if (lst == NULL)
     {

          return -1;
     }

     m = maiorMatricula(lst->prox);

     if (m >= lst->matricula)
          return m;
     else
          return lst->matricula;
}

int maiorMatricula2(Pedido *lst)
{

     Pedido *p;
     int maior = -1;
     int i = 0;

     for (p = lst; p != NULL; p = p->prox)
     {
          if (p->matricula > maior)
          {

               maior = p->matricula;
          }
          i++;
     }

     if (i < 1)
          return -1;

     return maior;
}

void exibe(Pedido *lst)
{

     Pedido *p;

     for (p = lst; p != NULL; p = p->prox)
     {
          printf("Mat: %d    Tipo: %s\n", p->matricula, p->tipoDoPedido);
     }
}

int main()
{
     Pedido *lst = NULL;

     lst = insere(lst, 203, "ic");
     lst = insere(lst, 205, "ic");
     lst = insere(lst, 101, "soc");
     lst = insere(lst, 415, "dout");
     lst = insere(lst, 201, "ic");

     exibe(lst);

     printf("Recursiva: %d\n\n", maiorMatricula(lst));
     printf("Normal: %d", maiorMatricula2(lst));

     return 0;
}
