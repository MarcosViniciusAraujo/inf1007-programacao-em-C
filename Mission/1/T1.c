#include <stdio.h>
#include <math.h>

float free_fall ( float t){
    return (0.5 * 9.8 * pow(t,2) + 1.0 );
}

int main (void){
    float y1 , y2 ;

    printf("  g  v0      y0      y\n");
    
    y1 = free_fall( 2.0 ) ;
    y2 = free_fall( 3.0 ) ;

    printf("9.80  0.0  1.00  %.2f\n " , y1 );
    printf("9.80  0.0  1.00  %.2f  " , y2 );
    
    return 0;
}