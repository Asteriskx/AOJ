#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, x, num;
    
    scanf("%d", &num);
    
    for(i = 3; i <= num; ++i) {
        x = i;
        if(x % 3 == 0) {
            printf(" %d", i);
        } else {
            do {
                if(x % 10 == 3) { 
                    printf(" %d", i);
                    break;
                }
                x /= 10;
            } while( x );
        }
    }
    printf("\n");
    
    return ( EXIT_SUCCESS );   
}
