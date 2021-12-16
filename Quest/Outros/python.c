#include <stdio.h>

float calcula_imposto(int kg_peixe)
{
    float impost;
    int dif, multa;

    if (kg_peixe <= 50)
    {
        impost = 1.15 * kg_peixe;
    }

    else
    {
        dif = kg_peixe - 50;
        impost = dif * 4.0 + kg_peixe * 1.15;
        multa = dif * 4.0;

        printf("Multa: R$%d\n", multa); //Atenção ao "d" ou "f" //
    }
    return impost;
}

int main(void)
{

    int kg_peixe;
    float imposto;

    printf("Quantos kilos? ");
    scanf("%d", &kg_peixe);

    imposto = calcula_imposto(kg_peixe);

    printf("Imposto: R$%.2f", imposto);

    return 0;
}