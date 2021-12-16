#include <stdio.h>
#include <stdlib.h>

#define N 200

typedef struct pilha Pilha;
struct pilha
{
     int n; /* vet[n]: primeira posição livre do vetor */ // troque aqui
     float vet[N];                                        /* vet[n-1]: topo da pilha */
     /* vet[0] a vet[N-1]: posições ocupáveis */
};

Pilha *pilha_cria(void)
{
     Pilha *p = (Pilha *)malloc(sizeof(Pilha));
     if (p == NULL)
          exit(1);
     p->n = 0; /* inicializa com zero elementos */
     return p;
}

void pilha_push(Pilha *p, float v) //troque aqui
{
     if (p->n == N)
     { /* capacidade esgotada */
          printf("Capacidade da pilha estourou.\n");
          exit(1);
     }
     /* insere elemento na próxima posição livre */
     p->vet[p->n] = v; //troque aqui
     p->n++;           /* equivalente a: p->n = p->n + 1 */
}

float pilha_pop(Pilha *p)
{
     float v; //troque aqui
     if (pilha_vazia(p))
     {
          printf("Pilha vazia.\n");
          exit(1);
     }
     /* retira elemento do topo */
     v = p->vet[p->n - 1];
     p->n--;
     return v; //troque aqui
}

