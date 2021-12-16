#include <stdio.h>
#include <stdlib.h>

typedef struct ponto Ponto;
struct ponto
{
     float x;
     float y;
};

Ponto *centroGeometrico(Ponto **v, int n)
{
     Ponto *c;
     int i;

     float smx = 0, smy = 0;

     c = (Ponto *)malloc(sizeof(Ponto));

     for (i = 0; i < n; i++)
     {
          smx += v[i]->x;
          smy += v[i]->y;
     }

     c->x = smx / n;
     c->y = smy / n;

     return c;
}

int main()
{
     FILE *fp;
     Ponto **v;

     Ponto *centro;

     int n_lados, i;

     fp = fopen("ponto.txt", "r");

     fscanf(fp, "%d", &n_lados);

     v = (Ponto **)malloc(n_lados * sizeof(Ponto *));

     for (i = 0; i < n_lados; i++)
     {
          v[i] = (Ponto *)malloc(sizeof(Ponto));
          fscanf(fp, "%f %f", &(v[i]->x), &(v[i]->y));

          printf("X: %.2f  Y: %.2f\n", (v[i]->x), (v[i]->y));
     }

     fclose(fp);

     centro = centroGeometrico(v, n_lados);

     printf("Centro: %.2f %.2f \n", centro->x, centro->y);

     for (i = 0; i < n_lados; i++)
     {
          free(v[i]);
     }

     free(v);

     free(centro);

     return 0;
}
