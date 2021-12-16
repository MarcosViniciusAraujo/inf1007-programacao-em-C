#include <stdio.h>
#include <math.h>

float f (float x){
    if (x <= 1){
        return x*x;
    }

    else {
        return 6 - x;
    }
}

int main (){
    int n_pontos, cont;
    float delta, i0, valor;

    printf ("Extreme inicial, um incrmento delta e unumero maximo de pontos ");
    scanf("%f", &i0);
    scanf("%f", &delta);
    scanf("%d", &n_pontos);

    printf("x    f(x)\n");
    printf("%.2f  %.2f\n", i0 , f(i0));

    cont = 0;

    while (cont <= n_pontos){
        i0 = i0 + delta ;

        printf("%.2f  %.2f\n", i0 , f(i0));

        cont++; 
        
    }
    return 0;
}