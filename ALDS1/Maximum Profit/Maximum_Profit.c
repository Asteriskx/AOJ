#include <stdio.h>
 
#define MAX(a, b) (a >= b) ? a : b;
#define MIN(a, b) (a <= b) ? a : b;
 
int main() {
    int i;
    int num;
    long rate_min, rate_buf, range_max, range_buf;
    
    scanf("%d", &num);
 
    scanf("%ld %ld", &rate_min, &rate_buf);
    
    range_max = rate_buf - rate_min;
    rate_min  = MIN(rate_min, rate_buf);
 
    for (i = 2; i < num; ++i) {
        scanf("%ld", &rate_buf);
        range_buf = rate_buf - rate_min;
        rate_min  = MIN(rate_min, rate_buf);
        range_max = MAX(range_max, range_buf);
    }
 
    printf("%ld\n", range_max);
 
    return ( 0 );
}