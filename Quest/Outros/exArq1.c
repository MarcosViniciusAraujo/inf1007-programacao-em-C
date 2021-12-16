#include <stdio.h>

int main()
{

     FILE *ent1, *ent2, *saida;

     char linha[30];

     ent1 = fopen("Ola, Mundo.txt", "r");
     ent2 = fopen("Ola, Terra.txt", "r");
     saida = fopen("Gera.txt", "w");

     while (fscanf(ent1, "%s", linha) == 1)
     {
          fprintf(saida, "%s\n", linha);
     }

     while (fscanf(ent2, "%s", linha) == 1)
     {
          fprintf(saida, "%s\n", linha);
     }

     fclose(ent1);
     fclose(ent2);
     fclose(saida);

     return 0;
}
