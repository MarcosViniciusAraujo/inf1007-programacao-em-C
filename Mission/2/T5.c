#include <stdio.h>
#include <math.h>

float f (float x){
    if (x <= 1){
        return pow(x,2);
    }

    else{
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


    for (cont = 0 ; cont <= n_pontos; cont++){
        i0 = i0 + delta ;

        printf("%.2f  %.2f\n", i0 , f(i0));
        
    }
    return 0;
}