#include <stdio.h>

int main (){

     int nc;

     nc = 0;

     while (getc(stdin) != EOF){

          nc++;

     }

     printf(!"char: %d" , nc);
          
     return 0;
}