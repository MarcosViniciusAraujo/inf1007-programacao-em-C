#include <stdio.h>

int dtoi(char c)
{
     int num;

     num = c - '0';
     return num;
}

int main(void)
{
     char *c = '2';
     int result = dtoi(c);

     printf("%d", result);

     return 0;
}