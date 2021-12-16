#include <stdio.h>
#include <string.h>

int retornaAprovado(float *prova1, float *prova2, int totAlunos, float mediaAprova)
{
     float mediaAluno = 0.0;

     if (totAlunos == 1)
     {
          mediaAluno = (*(prova1) + *(prova2)) / 2;
          printf("%.2f %.2f  %.2f\n", *(prova1), *(prova2), mediaAluno);
          if (mediaAluno >= mediaAprova)
          {
               return 1;
          }

          else
          {
               return 0;
          }
     }

     else
     {
          mediaAluno = (*(prova1 + totAlunos - 1) + *(prova2 + totAlunos - 1)) / 2;
          printf("%.2f %.2f  %.2f\n", *(prova1 + totAlunos - 1), *(prova2 + totAlunos - 1), mediaAluno);
          if (mediaAluno >= mediaAprova)
          {
               return 1 + retornaAprovado(prova1, prova2, totAlunos - 1, mediaAprova);
          }

          else
          {
               return retornaAprovado(prova1, prova2, totAlunos - 1, mediaAprova);
          }
     }
}

void subsSinalCorrespondente(char *nomeSinal, char *result)
{

     if (*(nomeSinal + 0) == '\0')
     {
          printf("\n");
     }

     else
     {
          if (*(nomeSinal) == '+')
          {
               printf("%c", *(result + 0));
               subsSinalCorrespondente(&nomeSinal[1], &result[1]);
          }

          else
          {
               printf("%c", *(nomeSinal + 0));
               subsSinalCorrespondente(&nomeSinal[1], result);
          }
     }
}

int main()
{
     int numAlunos = 5;
     float prova1[5] = {10.0, 9.0, 10.0, 8.0, 5.0};
     float prova2[5] = {10.0, 7.0, 6.0, 8.0, 7.0};
     float mediaNecessaria = 8.0;
     int numPassaram;

     char *nomeSinal = "+u++a Li++";
     char *result = "Lizma";

     char *meuNome = "+arco+ V+n+ci+s";
     char *result_meuNome = "Msiiu";

     numPassaram = retornaAprovado(prova1, prova2, numAlunos, mediaNecessaria);

     printf("%d\n\n", numPassaram);

     //subsSinalCorrespondente(nomeSinal, result);

     //subsSinalCorrespondente(meuNome, result_meuNome);

     return 0;
}

///Presta atenção na média cara... TA BIZARRO