#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct biodata
{
     float peso;
     float altura;
} BioData;

typedef struct cliente
{
     char *nome;
     int id;
     BioData bio;
} Cliente;

void ExibeInfCliente(Cliente c)
{
     printf("Nome: %s\nId: %d\nPeso: %.2fKg\nAltura: %.2fm\n", c.nome, c.id, c.bio.peso, c.bio.altura);
}

Cliente retornaCliente(char *nome, int id, float peso, float altura)
{
     Cliente c;
     strcpy(c.nome, nome);
     c.id = id;
     c.bio.peso = peso;
     c.bio.altura = altura;

     return c;
}

float BodyMaxIndex(Cliente c, int *result)
{
     float peso = c.bio.peso;
     float altura = c.bio.altura;
     float imc;

     imc = peso / (altura * altura);

     if (imc <= 18.5)
     {
          *result = 0;
     }

     else if (imc >= 26.0)
     {
          *result = 1;
     }

     return imc;
}

int main()
{
     Cliente c1;
     Cliente c2;

     int result;
     float imc1, imc2;
     char nome[21];
     char *nomePonteiro;
     int id;
     float peso;
     float altura;

     printf("Digite o nome, id, altura, peso: ");
     scanf("%s", nome);
     scanf("%d", &id);
     scanf("%f", &altura);
     scanf("%f", &peso);

     nomePonteiro = (char *)malloc((strlen(nome) + 1) * sizeof(char));
     strcpy(nomePonteiro, nome);

     c1 = retornaCliente(nomePonteiro, id, peso, altura);

     printf("\nDigite o nome, id, altura, peso: ");
     scanf("%s", nome);
     scanf("%d", &id);
     scanf("%f", &altura);
     scanf("%f", &peso);

     ExibeInfCliente(c1);
     strcpy(nomePonteiro, nome);
     c2 = retornaCliente(nomePonteiro, id, peso, altura);

     //cliente 1
     imc1 = BodyMaxIndex(c1, &result);
     if (result == 1)
     {
          printf("Acima do peso\n");
     }
     else if (result == 0)
     {
          printf("Abaixo do peso\n");
     }
     printf("IMC = %.2f\n\n", imc1);

     //cliente 2
     ExibeInfCliente(c2);
     imc2 = BodyMaxIndex(c2, &result);
     if (result == 1)
     {
          printf("Acima do peso\n");
     }

     else if (result == 0)
     {
          printf("Abaixo do peso\n");
     }

     printf("IMC = %.2f", imc2);

     return 0;
}