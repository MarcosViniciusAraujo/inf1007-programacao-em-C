#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int branco(char *cadeia)
{
     int b = 0, i;

     for (i = 0; cadeia[i]; i++)
     {
          if (cadeia[i] == ' ')
          {
               b++;
          }
     }

     return b + 1;
}

//func para len da str
int comp_string(char *cadeia)
{
     int i, tamanho = 0;

     for (i = 0; *cadeia != "\0"; i++)
     {
          tamanho++;
     }

     return tamanho;
}

void ExibeNascimento(char *id_secreta)
{

     printf("%c%c/%c%c/%c%c%c%c", *(id_secreta + 6), *(id_secreta + 7), *(id_secreta + 4), *(id_secreta + 5), *(id_secreta), *(id_secreta + 1), *(id_secreta + 2), *(id_secreta + 3));
}

char *obtemMae(char *id)
{
     int i;

     for (i = 0; id[i]; i++)
     {
          if (id[i] == '*')
          {
               return &id[i + 1];
          }
     }
}
//concatenar string
char *mystrcat(char *s, char *t)
{
     char *saida;
     int i, j;
     j = comp_string(s);

     for (i = 0; s[i]; i++)
     {
          saida[i] = s[i];
     }

     for (i = 0; i < comp_string(t); i++)
     {
          saida[j] = *(t + i);
          j++;
     }
     saida[j] = "\0";

     return saida;
}

char *geraIdentidade(char *nome, char *data, char *mae)
{
     char *id;
     int i, j;
     int e = 8 + 1 + strlen(mae) + branco(nome);

     id = (char *)malloc((e + 1) * sizeof(char));

     if (id == NULL)
     {
          return NULL;
     }
     //ano
     *(id + 0) = *(data + 6);
     *(id + 1) = *(data + 7);
     *(id + 2) = *(data + 8);
     *(id + 3) = *(data + 9);
     //mes
     *(id + 4) = *(data + 3);
     *(id + 5) = *(data + 4);
     //dia
     *(id + 6) = *(data + 0);
     *(id + 7) = *(data + 1);
     //inicial
     *(id + 8) = *(nome + 0);

     for (i = 0, j = 9; *(nome + i); i++)
     {
          if (*(nome + i) == ' ')
          {
               *(id + j) = *(nome + (i + 1));
               j++;
          }
     }
     *(id + j) = '\0';

     strcat(id, "*");
     strcat(id, mae);

     return id;
}

int main()
{
     char nome_cand[80];
     char mae[20];
     char *id;
     char data[13];

     printf("\nDigite seu nome: ");
     scanf("%80[^\n]", nome_cand);

     printf("Digite o nome da sua mãe: ");
     scanf("%s", mae);

     printf("Digite a data de nascimento no formato dd/mm/aaaa: ");
     scanf("%s", data);

     id = geraIdentidade(nome_cand, data, mae);

     if (id == NULL)
     {
          printf("Não há memória");
          exit(1);
     }

     printf("Seu código secreto é: %s", id);

     free(id);

     return 0;
}