#include  <stdio.h>

int main(){
    
    int n_pessoa , maior_idade , menor_idade , idade , soma;
    float media_idade;

    maior_idade = 0;
    soma = 0;
    menor_idade = 200;

    n_pessoa = 0;

    printf("Sua idade: ");
    scanf("%d", &idade);

    while (idade != 0){
        if (idade >= maior_idade){
            maior_idade = idade;
        }

        if (idade <= menor_idade & idade != 0){
            menor_idade = idade; 
        }

        n_pessoa++ ;
        soma = soma + idade ;

        printf("Sua idade: ");
        scanf("%d", &idade);

    }

    media_idade = soma/n_pessoa;

    printf("Média:%.2ff\nMaior idade:%d\nMenor idade:%d\n", media_idade, maior_idade, menor_idade);



    return 0;
}