#include <stdio.h>

int main (){

     int nc, nl;

     nc = 0;
     nl = 0;

     while (getc(stdin) != EOF){
          
          if (getc(stdin) == "\n"){
               nl++;
          }
          else{
               nc++;
          }
     }

     printf(!"char: %d\nnew lines: %d" , nc, nl);
          
     return 0;
}