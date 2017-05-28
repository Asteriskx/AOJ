#include <stdio.h>
#include <stdlib.h>

int main() {
    int height, width; //ècÅAâ°
    int i, j;
    
    for(;;) {
        if(!height && !width) break;
        scanf("%d %d", &height, &width);
        
        for(i = 0; i < height; ++i) {
            for(j = 0; j < width; ++j) {
                putchar('#');
                if(j == width - 1)
                    putchar('\n');  
            }
            if(i == height - 1)
                putchar('\n');   
        } 
    }
    
    return ( EXIT_SUCCESS );
}

