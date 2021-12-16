#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_ALUNOS 100

FILE *openFile(char *file, char *mode)
{

     FILE *f;

     f = fopen(file, mode);
     if (f == NULL)
     {
          printf("Sem memoria");
          exit(2);
     }

     return f;
}


void preenche(char **vetor, char *senha, int i)
{

     if (vetor[i] == NULL)
     {
          vetor[i] = (char *)malloc((strlen(senha) + 1) * sizeof(char));
     }
     strcpy(vetor[i], senha);
}

void liberaVetor(char **vetor)
{

     int i;

     for (i = 0; vetor[i]; i++)
     {
          free(vetor[i]);
     }
}

float calculaMedia(float *vetor, int nAlunos){
    
    float media, soma = 0.0;
    int i;
    
    for (i = 0; i<nAlunos; i++){
        soma+= vetor[i];
    }
    
    media = soma/nAlunos;
    return media;
}

float desvioPadrao (float *vetor, int nAlunos, float media){
    
    int i;
    float desvio, somatorio = 0.0;
    
    
    for (i = 0; i < nAlunos; i++){
        somatorio +=  ((vetor[i] - media ) * (vetor[i]- media));
    }
    
    desvio = pow(somatorio * 1.0/nAlunos , 0.5);
    
    return desvio;
}

float scorePadrao (float nota, float media, float desvio){
    float result;
    
    result = (nota - media)/ desvio;
    
    return result;
}

void exibeVetor(char **vetor, int n){
    
    int i;
    
    for (i =0; i<n; i++){
        
        printf("%s\n", vetor[i]);
    }
}


int main()
{

     FILE *f_alunos = openFile("codigo.txt", "r");
     FILE *f_notas = openFile("notas.txt", "r");
     FILE *f_saida = openFile("saida.txt", "w");


     int i = 0;
     int nAlunos = 0;
     int lidas;
     char *aluno;
     float nota;
     float media;
     float desvio;
     float score;


     char **vetorAlunos;
     float *vetorNotas;
     
     vetorAlunos = (char **)malloc(MAX_ALUNOS * sizeof(char));
     if (vetorAlunos == NULL){
         printf("Sem espaço");
         exit(1);
     }

     while (!(feof(f_alunos)))
     {
          lidas = fscanf(f_alunos, "%s",  aluno);
          if (lidas != EOF)
          {
               preenche(vetorAlunos, aluno, i);
               nAlunos++;
          }
     }
     
    
     vetorNotas = malloc(nAlunos*sizeof(float));
     if(vetorNotas == NULL){
         printf("Sem memoria");
         exit(1);
     }
     
     while(!(feof(f_notas))){
         
         lidas = fscanf(f_notas, "%f", &nota);
         if (lidas != EOF){
            vetorNotas[i] = nota;
            i++;
         }
     }
     
     
     media = calculaMedia(vetorNotas, nAlunos);
     
     desvio = desvioPadrao(vetorNotas, nAlunos, media);
     
     fprintf(f_saida, "Alunos: %d    Média: %.2f   Desvio Padrão: %.2f\n", nAlunos, media, desvio);
     printf("Alunos: %d    Média: %.2f   Desvio Padrão: %.2f\n", nAlunos, media, desvio);
     
     
     for (i = 0; i<nAlunos; i++){
         nota = vetorNotas[i];
         score = scorePadrao(nota, media, desvio);
         fprintf(f_saida, "A%d: %.2f\n",i+100, score);
     }

     liberaVetor(vetorAlunos);
     free(vetorAlunos);

     fclose(f_alunos);
     fclose(f_notas);
     fclose(f_saida);

     return 0;
}