#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *openFile(char *file, char *mode)
{

     FILE *f;

     f = fopen(file, mode);
     if (f == NULL)
     {
          printf("Sem memoria");
          exit(2);
     }

     return f;
}

void preenche(char **vetor, char senha[21], int i)
{

     if (vetor[i] == NULL)
     {
          vetor[i] = (char *)malloc((strlen(senha) + 1) * sizeof(char));
     }
     strcpy(vetor[i], senha);
}

void liberaVetor(char **vetor)
{

     int i;

     for (i = 0; vetor[i]; i++)
     {
          free(vetor[i]);
     }
}

int comparaSenha(char **vetor, char *senhaNova, int nSenhas)
{

     int i;
     for (i = 0; i < nSenhas; i++)
     {
          if (strcmp(vetor[i], senhaNova) == 0)
          {
               printf("Sua senha é igual");
               return 0;
          }
     }
     return 1;
}

int main()
{

     FILE *fin = openFile("senhas.txt", "r");
     FILE *fout = openFile("novasSenhas.txt", "w");

     int dia, mes, ano;
     int i = 0;
     int nlinhas = 0;
     int lidas;
     char senha[21];
     char senhaNova[21];
     int id;
     int resultado;

     char **vetor;

     vetor = (char **)malloc(100 * sizeof(char));

     while (!(feof(fin)))
     {
          lidas = fscanf(fin, "%d %d %d %s", &dia, &mes, &ano, senha);
          if (lidas != EOF)
          {
               preenche(vetor, senha, i);
               printf("%d %d %d %s\n", dia, mes, ano, senha);
               i++;
               nlinhas++;
          }
     }

     //printf("OI");

     //printf("%d\n\n\n\n", nlinhas);
     printf("Digite sua id. e uma senha nova: ");
     scanf("%d %s", &id, senhaNova);

     resultado = comparaSenha(vetor, senhaNova, nlinhas);

     if (resultado == 1)
     {
          strcpy(vetor[id], strcat(senhaNova, "   Alterada"));
     }

     for (i = 0; i < nlinhas; i++)
     {
          fprintf(fout, "%s\n", vetor[i]);
     }

     liberaVetor(vetor);
     free(vetor);

     fclose(fin);
     fclose(fout);

     return 0;
}