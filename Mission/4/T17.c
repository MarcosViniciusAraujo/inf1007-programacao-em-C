#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

char* strupper(char* cadeia){
     int i;
     char *string = (char*)malloc((strlen(cadeia))*sizeof(char*));

     if (string == NULL){ 
          printf("Não há memória");
          exit(1);
     }

     for (i = 0; *(cadeia + i) != '\0'; i++){
          *(string + i) = toupper(*(cadeia + i));
     }
     *(string + i) = '\0';

     return string;

}

char* mystrdup (char* cadeia){
     int tamanho = 2*strlen(cadeia)-1 ;
     char* string = (char*)malloc((tamanho)*sizeof(char));

     int i,j;

     if (string == NULL){
          return NULL;
          exit(1);
     }


     for (i=0; i<tamanho/2+ 1; i++){
          *(string+i) = *(cadeia + i);
     }

     j = 0;

     for (i = tamanho/2+1; i<tamanho+1; i++){
          *(string+i) = *(cadeia + j);
          j++;

     }
     *(string+i) = '\0';

     return string;


}

int mystrcmp(char* s, char* t){
     if (s < t){
          return -1;
     }
     
     else if(s == t){
          return 0;
     }

     else{
          return 1;
     }
}

void mystrcat (char* s, char* t){
     int i, j;
     j = strlen(s);

     for (i = 0; i<strlen(t); i++){
          *(s+j) = *(t+i);
          j++;
     }


     *(s+j) = '\0';



}
     
char* strShift(char* cadeia){
     char* string = (char*)malloc(strlen(cadeia)*sizeof(char));
     int i; 

     if (string == NULL){
          return NULL;
     }


     for (i = 0; i<strlen(cadeia); i++){
          *(string+i) = *(cadeia + i) + 1;
     }

     return string;
}

int main (){

     char s[80] = "puc";
     char v[] = "rio";
     char t[] = "-";
     char r[] = "Ana";
     char z[] = "zaZa";

     char *result1, *result2, *result3; 
     int valor;

     result1 = strupper(s);
     result2 = mystrdup(v);
     mystrcat(s, v);
     result3 = strShift(r);
     valor = strcmp(v , s);


     printf("%s\n", result1);
     printf("%s\n", result2);
     printf("%s\n", s);
     printf("%s\n", result3);
     printf("%d", valor);


     free(result1);
     free(result2);
     free(result3);


     return 0;
}