#include <stdio.h>
#include <string.h>

int main()
{

     char *nomeSinal = "Luiza +ima";
     char *result = "L";
     int j = 0;

     if (nomeSinal[2] == 'i')
          printf("%s", nomeSinal + 1);

     return 0;
}
