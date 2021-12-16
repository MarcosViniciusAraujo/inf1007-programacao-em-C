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
     char nome[81];
     int id;
     BioData bio;
} Cliente;

void ExibeInfCliente(Cliente c)
{
     printf("Nome: %s\nId: %d\nPeso: %.2fKg\nAltura: %.2fm\n", c.nome, c.id, c.bio.peso, c.bio.altura);
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
     Cliente c1 = {"Marcos", 1910869, {80.0, 1.75}};
     Cliente c2;

     int result;
     float imc1, imc2;

     strcpy(c2.nome, "Ronaldo");
     c2.id = 2021123;
     c2.bio.altura = 1.90;
     c2.bio.peso = 100.0;

     //cliente 1
     ExibeInfCliente(c1);
     imc1 = BodyMaxIndex(c1, &result);
     if (result == 1)
     {
          printf("Acima do peso\n");
     }
     if (result == 0)
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
     if (result == 0)
     {
          printf("Abaixo do peso\n");
     }

     printf("IMC = %.2f", imc2);

     return 0;
}