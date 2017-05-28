#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
    int num, i;
    int array[SIZE] = { 0 };
    
    scanf("%d", &num);
    
    for(i = 0; i < num; ++i) 
        scanf(" %d", &array[i]);
    
    for(i = 0; i < num; ++i) {
        (i) ? printf(" ") : printf("");
        printf("%d", array[num - i - 1]);
    }
    
    printf("\n");
        
    return ( EXIT_SUCCESS );
}