#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define HARF 0.5
#define R_PI 180
#define POW  2.0

int main() {
    int deg;
    double rad, sq;
    double a, b, S, L, h;
    
    scanf("%lf %lf %d", &a, &b, &deg);
    
    rad = deg * PI / R_PI; //deg -> rad 
    sq  = sqrt(pow(a, POW) + pow(b, POW) - 2 * a * b * cos(rad));   
    S   = HARF * a * b * sin(rad);
    L   = a + b + sq;
    h   = b * sin(rad);
    
    printf("%lf %lf %lf", S, L, h);
    
    return ( 0 );
}