#include <stdio.h>
#include <stdlib.h>

int main()
{

     FILE *fp;
     char msg[20];

     fp = fopen("Ola, Mundo.txt", "r");
     if (fp == NULL)
     {

          printf("Erro na abertura do arquivo");
          exit(1);
     }

     fscanf(fp, "%80[^\n]", &msg);

     printf("%s", msg);

     fclose(fp);

     return 0;
}