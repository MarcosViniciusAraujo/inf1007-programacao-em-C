#include <stdio.h>
#include <math.h>

void Hex_tudo (float l , float* per , float* area);

int main (){
     float l , per , area;

     printf("Digite o valor: ");
     scanf ("%f", &l);

     Hex_tudo(l , &per , &area);

     printf("%f\n%f\n%f", l , per , area);

     return 0;
}

void Hex_tudo (float l , float* per , float* area){

     *per = 6*l;

     *area = 3* l*l *1.7/2 ;

}