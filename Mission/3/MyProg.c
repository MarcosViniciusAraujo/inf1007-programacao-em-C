#include <stdio.h>
#include "geometria.h"
#include <math.h>


int main (){

     float l_tri , per_circ , area_tri , r ;

     printf("Valor: ");
     scanf("%f", &l_tri);

     trianeq (l_tri , &area_tri);

     Circulo(area_tri, &r, &per_circ );

     printf("lado: %f\nraio: %f\narea: %f\ncircunferencia: %f", l_tri ,r ,area_tri ,per_circ );

     return 1;

}