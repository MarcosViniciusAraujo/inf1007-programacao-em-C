#include <stdio.h>
#include <math.h>

int main (void){
    int n_filhos , familia , salario_100, n ; 
    float salario_t , s , percent , maior_salario , media_salario ;
    float media_filho;

    n_filhos = 0;
    familia = 0;
    salario_t = 0.0;
    salario_100 = 0;
    maior_salario = -1;

    printf("Salário:\n");
    scanf("%f", &s );
    

    while (s >= 0){
        printf("Numero de filhos: ");
        scanf("%d", &n );

        n_filhos = n_filhos + n;

        if (s >= 100.0){
            salario_100 = salario_100 +s;
        }
        if (s > maior_salario){
            maior_salario = s;
        }

        salario_t = salario_t + s; 
        familia++;
        printf("Salário:\n");
        scanf("%f", &s);
    }

    percent = (salario_100/familia)*100.0; 
    media_salario = salario_t/familia;
    media_filho = n_filhos/familia;
    
    printf("Maior salário: %.2f\n", maior_salario);
    printf("Média de salário: % .2f", media_salario);
    printf("Média de filhos: %.2f" , media_filho);
    printf("Percentual maior de 100: %.2f" , percent);

    return 0;


}