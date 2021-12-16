#include <stdio.h>
#include "geometria.h"
#include <math.h>

void trianeq(float l , float * area ){
     *area = l*l * pow(3, 0.5)/4;

}

void Circulo (float area , float *r , float *per_circ){
     
     *r = pow( area/Pi , 0.5 );

     *per_circ = 2 * Pi * *r;
}