/***********************************************************************
NOME COMPLETO : Marcos Vinicius Araujo Almeida
MATRICULA PUC-Rio: 1910869
DATA : 07/05/2020
DISCIPLINA : INF1007 TURMA (33A, 33B): 33A
DECLARACAO DE AUTORIA :
 Declaro que este documento foi produzido em sua totalidade por mim,
 sem consultas a outros alunos, professores ou qualquer outra pessoa.
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dtoi(char c)
{
     int num;

     num = c - '0';
     return num;
}

char *strDigit(char *cadeia, int codigo)
{
     char *saida;
     int e = strlen(cadeia);
     int i;
     char a;

     saida = (char *)malloc((e + 1) * sizeof(char));

     if (saida == NULL)
     {
          return NULL;
     }
     //impar
     if (codigo == 1)
     {
          for (i = 0; *(cadeia + i); i++)
          {
               if (*(cadeia + i) >= '0' && *(cadeia + i) <= '9')
               {
                    //salva o digito
                    a = *(cadeia + i);
                    dtoi(a);
                    if (a % 2 != 0)
                    {
                         *(saida + i) = '*';
                    }

                    else
                    {
                         *(saida + i) = a;
                    }
               }

               else
               {
                    *(saida + i) = *(cadeia + i);
               }
          }
     }

     //par
     else if (codigo == 0)
     {
          for (i = 0; *(cadeia + i); i++)
          {
               if (*(cadeia + i) >= '0' && *(cadeia + i) <= '9')
               {
                    a = *(cadeia + i);
                    dtoi(a);
                    if (a % 2 == 0)
                    {
                         *(saida + i) = '*';
                    }

                    else
                    {
                         *(saida + i) = a;
                    }
               }

               else
               {
                    *(saida + i) = *(cadeia + i);
               }
          }
     }

     *(saida + i) = '\0';

     return saida;
}

int main()
{
     int codigo = 1;

     char *carac = "a@13F2345";
     char *teste = "A21R34#25";
     char *testeMatricula = "@19$0869";

     char *saida;
     char *testeResp;
     char *resp;

     saida = strDigit(carac, codigo);
     resp = strDigit(testeMatricula, codigo);
     testeResp = strDigit(teste, codigo);

     if (saida == NULL || testeResp == NULL || resp == NULL)
     {
          //sem espaço
          exit(1);
     }

     printf("Codigo: %d\n", codigo);
     printf("%s ----> %s\n", carac, saida);
     printf("%s ----> %s\n", teste, testeResp);
     printf("%s ----> %s", testeMatricula, resp);

     free(saida);
     free(testeResp);
     free(resp);

     return 0;
}