#include <stdio.h>

double Calculo_PI(int n ){
     
     double pi, denom ;
     int cont;

     pi = 0.0;
     cont = 1; 

     while (cont <= n){
          
          if ( cont%2 == 0){
               denom = -1* (2*cont - 1);
          }
          else{
               denom = 1*(2*cont- 1);
          }

          pi += 4/denom;
          cont++;
          

     }

     return pi;

}

int main (){

     int n;

     printf("n: ");
     scanf("%d", &n);

     printf("Pi: %f", Calculo_PI( n ));

     return 0;

}