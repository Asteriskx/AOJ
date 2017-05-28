#include <stdio.h>
#include <math.h>

#define SIZE 1024

int main() {
    int n;
    int i, j = 0, sum;
    int score[SIZE];
    
    double ave, tmp;
    double dev[SIZE];

    for(;;) {
        scanf("%d", &n);
        if(n == 0) break;
        
        sum = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d", &score[i]);
            sum += score[i];
        }
        
        ave = (double)sum / (double)n;
        tmp = 0.0;
        for(i = 0; i < n;++i) 
            tmp+=pow(score[i]-ave, 2);
        
        dev[j++] = sqrt(tmp / (double)n);
    }
    
    for(i = 0; i < j; ++i)
        printf("%f\n", dev[i]);
    
    return ( 0 );
}