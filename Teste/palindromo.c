#include <string.h>
#include <stdio.h>


int palim ( char* s){
     int i,j = strlen(s)-1;

     for (i = 0; i<strlen(s); i++){
          if (s[i] != s[j]){
               return -1;
          }

          j--;

     }

     return 1;
}

int palim_r (char* s){
     
}

int main (){

     char* teste = "ovo";

     printf("%d", palim(teste));

     return 0;
}