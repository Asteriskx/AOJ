#include <stdio.h>
#include <math.h>

#define POW 2.0

int main() {
    double x1, x2, y1, y2;
    double ret;
    
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    ret = sqrt((pow((x2 - x1), POW)) + (pow((y2 - y1), POW)));
    printf("%lf\n", ret);
    
    return ( 0 ); 
}