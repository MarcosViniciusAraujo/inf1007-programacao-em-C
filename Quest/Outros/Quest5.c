#include <stdio.h>

int comprimento(char *cadeia)
{
     int i;

     for (i = 0; cadeia[i]; i++)
     {
          ;
     }

     return i;
}

int main()
{

     char cadeia[] = "TENTATIVA";
     char lida[20];

     printf("Digite uma palavra: ");
     scanf("¨%20[^\n]", lida);

     printf("\nOs tamanhos da cadeia são %d e %d", comprimento(&cadeia), comprimento(&lida));

     return 0;
}