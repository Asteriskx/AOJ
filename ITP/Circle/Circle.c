#include <stdio.h>

#define PI     3.141592653589  // ‰~Žü—¦
#define RAD(x) ((x) * (x))     // ”¼Œa
#define DIA(x) ((x) * 2)       // ’¼Œa

int main() {
    double r;
    double area, circum;
    
    scanf("%lf", &r); // ”¼Œa‚ÌŽw’è
    
    area   = RAD(r) * PI;
    circum = DIA(r) * PI;
    
    printf("%lf %lf\n", area, circum);
    
    return ( 0 );
}