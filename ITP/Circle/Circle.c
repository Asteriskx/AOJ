#include <stdio.h>

#define PI     3.141592653589  // �~����
#define RAD(x) ((x) * (x))     // ���a
#define DIA(x) ((x) * 2)       // ���a

int main() {
    double r;
    double area, circum;
    
    scanf("%lf", &r); // ���a�̎w��
    
    area   = RAD(r) * PI;
    circum = DIA(r) * PI;
    
    printf("%lf %lf\n", area, circum);
    
    return ( 0 );
}