#include <stdio.h>

int main() {
     int    a, b;
     int    d, r;
     double    f;
     
     scanf("%d %d", &a, &b);
     
     d = a / b;
     r = a % b;
     f = (double)a / (double)b;
     
     printf("%d %d %f",d, r, f);
     
     return ( 0 );
}