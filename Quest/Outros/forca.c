#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no No;
struct no{
  char nome[50];
  no *prox;

};

No *insere(No *lt, char *nome){
  No *lst = NULL;

  strcpy(lst->nome, nome);

  lst->prox = lt;
  return lst;
}

int main(){

  File *nomes = fopen("nomes.txt", "r");
  char s[50];
  No *lst = NULL;


  while(fscanf(nomes, "%s",s ) == 1){
    lst = insere(lst, s);
  }





  return 0;
}
