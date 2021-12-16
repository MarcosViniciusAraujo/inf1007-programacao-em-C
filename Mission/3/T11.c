#include <stdio.h>
#include <math.h>

#define Pi 3.14159265

void trianeq (float l , float * area );

void Circulo (float area , float *r , float *per_circ);

int main (){

     float l_tri , per_circ , area_tri , r ;

     printf("Valor: ");
     scanf("%f", &l_tri);

     trianeq (l_tri , &area_tri);

     Circulo(area_tri, &r, &per_circ );

     printf("lado: %f\nraio: %f\narea: %f\ncircunferencia: %f", l_tri ,r ,area_tri ,per_circ );

     return 1;

}

void trianeq(float l , float * area ){
     *area = l*l * pow(3, 0.5)/4;

}

void Circulo (float area , float *r , float *per_circ){
     
     *r = pow( area/Pi , 0.5 );

     *per_circ = 2 * Pi * *r;
}