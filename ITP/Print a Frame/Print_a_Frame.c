#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int height, width; // èc, â°
    int i, j;
     
    for(;;) {
        scanf("%d %d ", &height, &width);
        if(!height && !width) break;
         
        for(i = 0; i < height; ++i) {
            for(j = 0; j < width; ++j) {
                if(i == 0 || i == height - 1 || j == 0 || j == width - 1 ) {
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