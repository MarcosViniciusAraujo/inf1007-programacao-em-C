#include <stdio.h>

int main (){

     int n = 0;
     char c;
     
     while (c = getc(stdin) != EOF){
          
          printf("%d", c);
          n++;

          
     }
}