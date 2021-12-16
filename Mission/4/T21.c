#include <stdio.h>

void troca(char cadeia[], char sai, char subs)
{

     if (cadeia[0] == '\0')
     {
          cadeia[0] = '\0';
     }

     else
     {

          if (cadeia[0] == sai)
          {
               cadeia[0] = subs;
               troca(&cadeia[1], sai, subs);
          }

          else
          {
               troca(&cadeia[1], sai, subs);
          }
     }
}

int countNoLetter(char *cadeia)
{

     if (cadeia[0] == '\0')
     {
          return 0;
     }

     else
     {
          if (!((cadeia[0] >= 'A' && cadeia[0] <= 'Z') || (cadeia[0] >= 'a' && cadeia[0] <= 'z')))
          {
               return 1 + countNoLetter(&cadeia[1]);
          }

          else
          {
               return countNoLetter(&cadeia[1]);
          }
     }
}

int main()
{

     char cadeia[] = "abacate";
     char a = 'a';
     char b = '_';
     char *comN = "Ah!tenho35";
     int result;
     int pontos = 0, cont = 0;

     troca(cadeia, a, b);

     printf("%s\n", cadeia);

     result = countNoLetter(comN);

     printf("%d", result);

     return 0;
}