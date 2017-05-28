#include <stdio.h>
#include <stdlib.h>

int main() {
    int height, width; //ècÅAâ°
    int i, j;
    
    for(;;) {
        scanf("%d %d ", &height, &width);
        if(!height && !width) break;
        
        for(i = 0; i < height; ++i) {
            for(j = 0; j < width; ++j) {
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                    printf("#");
                } else {
                    printf(".");
                }
            }
            printf("\n");   
        } 
        printf("\n");
    }
    
    return ( EXIT_SUCCESS );
}