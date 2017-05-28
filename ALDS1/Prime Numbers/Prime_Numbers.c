#include <stdio.h>
#include <math.h>

#define SIZE  10000
#define EVEN      2
#define ODD       3
#define TRUE      1
#define FALSE     0

#define DEBUG_MODE 1

int isPrime(int);

int isPrime(int x) {
    int i;
    
    if (x == EVEN) return TRUE;
    
    if ((x < EVEN) || (x % EVEN == FALSE)) 
        return FALSE;

    for(i = ODD; i <= sqrt(x); i += EVEN) 
        if (x % i == FALSE) return FALSE;
    
    return TRUE;
}

int main() {
    
    int prime[SIZE + 1];
    int i, num, cnt = 0;
    
    scanf("%d", &num);
    
    for(i = 0; i < num; ++i) 
        scanf("%d", &prime[i]);

    for(i = 0 ; i < num; ++i)
        if(isPrime(prime[i])) 
            ++cnt;     
        
    printf("%d\n", cnt);
    
    return ( 0 );
}
