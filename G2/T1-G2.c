/***********************************************************************
NOME COMPLETO : Marcos Vincius Araujo Almeida
MATRICULA PUC-Rio: 1910869
DATA : 18/06/2020
DISCIPLINA : INF1007 TURMA (33A, 33B): 33A
DECLARACAO DE AUTORIA :
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no No;
struct no
{

     float total;
     No *prox;
};

No *insere(No *lst, float total)
{

     No *novo;
     novo = (No *)malloc(sizeof(No));

     novo->total = total;
     novo->prox = lst;

     return novo;
}

void exibe(No *lst)
{

     No *p;

     for (p = lst; p != NULL; p = p->prox)
     {
          printf("[ Ruido: %.2f dB] - ", p->total);
     }
     printf("NULL\n");
}

int contaELemento(No *lst)
{

     int cont = 0;
     No *p;

     for (p = lst; p != NULL; p = p->prox)
     {

          cont++;
     }

     return cont;
}

float somaValoresLista(No *lst)
{

     float soma = 0.0;
     No *p;
     float v;

     for (p = lst; p != NULL; p = p->prox)
     {

          v = p->total;
          soma += v;
     }

     return soma;
}

void libera(No *lst)
{

     No *p;

     for (p = lst; p != NULL; p = p->prox)
     {

          free(p);
     }
}

void exibeInf(No **v, int n)
{
     int i;

     for (i = 0; i < n; i++)
     {
          printf("Sala %d\n", i);
          int numEquip = contaELemento(v[i]);
          printf("Total: %d equipamentos\n", numEquip);
          exibe(v[i]);
          float totalRuido = somaValoresLista(v[i]);
          printf("Total de ruido: %.2f dB\n\n", totalRuido);
     }
}

int compara(No *p, int nEquip)
{
     int totalE = contaELemento(p);
     if (totalE > nEquip)
     {
          return 1;
     }
     if (totalE < nEquip)
     {
          return -1;
     }
     return 0;
}

int busca(No **v, int n, int nEquip)
{
     int ini = 0;
     int fim = n - 1;

     while (ini <= fim)
     {
          int meio = (ini + fim) / 2;
          if (compara(v[meio], nEquip) == 1)
          {
               fim = meio - 1;
          }

          else if (compara(v[meio], nEquip) == -1)
          {
               ini = meio + 1;
          }

          else
          {

               while (compara(v[meio], nEquip) == 0)
               {
                    meio++;
               }

               return meio - 1;
          }
     }

     return -1;
}

void resultadoBusca(int i)
{
     if (i == -1)
     {
          printf("Não foi encontrado!\n");
     }

     else
     {
          printf("A procura foi achada no local: %d\n", i);
     }

     printf("\n\n");
}

int main()
{
     No **v;
     int n = 8;
     v = (No **)malloc(n * (sizeof(No *)));

     int a, b, c;
     int i;

     v[0] = NULL;
     v[0] = insere(v[0], 50);

     v[1] = NULL;
     v[1] = insere(v[1], 60);

     v[2] = NULL;
     v[2] = insere(v[2], 40);
     v[2] = insere(v[2], 70);

     //sala 3,4,5 com o mesmo numero de equipamentos
     //Caso a:
     v[3] = NULL;
     v[3] = insere(v[3], 30);
     v[3] = insere(v[3], 50);
     v[3] = insere(v[3], 70);

     v[4] = NULL;
     v[4] = insere(v[4], 30);
     v[4] = insere(v[4], 50);
     v[4] = insere(v[4], 75);

     v[5] = NULL;
     v[5] = insere(v[5], 30);
     v[5] = insere(v[5], 50);
     v[5] = insere(v[5], 80);

     //sala 6,7 com o mesmo numero de equipamentos no final
     //Caso b:
     v[6] = NULL;
     v[6] = insere(v[6], 30);
     v[6] = insere(v[6], 40);
     v[6] = insere(v[6], 50);
     v[6] = insere(v[6], 75);

     v[7] = NULL;
     v[7] = insere(v[7], 30);
     v[7] = insere(v[7], 40);
     v[7] = insere(v[7], 50);
     v[7] = insere(v[7], 80);

     exibeInf(v, n);
     printf("===================================================\n");

     int equip = 3;
     //resultado do caso A
     printf("Procurando %d equipamentos:\n", equip);
     a = busca(v, n, equip);

     resultadoBusca(a);

     //resultado do caso B
     equip = 4;
     printf("Procurando %d equipamentos:\n", equip);
     b = busca(v, n, equip);

     resultadoBusca(b);

     //resultado do caso C
     equip = 10;
     printf("Procurando %d equipamentos:\n", equip);
     c = busca(v, n, equip);

     resultadoBusca(c);

     for (i = 0; i < n; i++)
     {

          libera(v[i]);
     }

     free(v);

     return 0;
}
