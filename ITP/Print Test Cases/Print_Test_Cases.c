#include <stdio.h>

int main() {
    int read;
    int i = 0;
    
    for(;;) {
        scanf("%d", &read);
        if(read == 0) break;
        printf("Case %d: %d\n", ++i, read);
    }
    
    return 0; 
     
}