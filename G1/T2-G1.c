/***********************************************************************
NOME COMPLETO : Marcos Vinicius Araujo Almeida
MATRICULA PUC-Rio: 1910869
DATA : 12/05/2020
DISCIPLINA : INF1007 TURMA (33A, 33B): 33A
DECLARACAO DE AUTORIA :
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
************************************************************************/
#include <stdio.h>

int retornaAprovado(float *prova1, float *prova2, int totAlunos, float mediaAprova)
{
     float mediaAluno = 0.0;

     if (totAlunos == 1)
     {
          mediaAluno = (*(prova1) + *(prova2)) / 2;
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
               subsSinalCorrespondente(nomeSinal + 1, result + 1);
          }

          else
          {
               printf("%c", *(nomeSinal + 0));
               subsSinalCorrespondente(nomeSinal + 1, result);
          }
     }
}

int main()
{

     // variaveis quest 1
     int numAlunos = 5;
     float prova1[5] = {10.0, 6.0, 4.0, 8.0, 5.0};
     float prova2[5] = {9.0, 7.0, 2.0, 8.0, 4.0};
     float mediaNecessaria = 5.0;
     int numPassaram;

     numPassaram = retornaAprovado(prova1, prova2, numAlunos, mediaNecessaria);

     //variaves quest 2
     char *nomeSinal = "+u++a Li++";
     char *result = "Lizma";

     char *meuNome = "+arco+ V+n+ci+s";
     char *result_meuNome = "Msiiu";

     char *meuNome_caso2 = "Marcos Vinicius";
     char *vazio = "";

     printf("Quest. 1\n");
     printf("Passaram: %d\n\n", numPassaram);

     printf("Quest. 2\n");

     subsSinalCorrespondente(nomeSinal, result);
     subsSinalCorrespondente(meuNome, result_meuNome);
     subsSinalCorrespondente(meuNome_caso2, vazio);
     // Provando que a função funciona para ambos os casos

     return 0;
}