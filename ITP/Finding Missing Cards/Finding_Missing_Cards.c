#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MARK 4
#define TYPE 13

int main() {
    
    int i, j;
    int num, t;
    
    char *mark = "SHCD";
    int card[MARK][TYPE] = { 0 };
    char kind_mark;
    
    scanf("%d", &num);
    
    for(i = 0; i < num; ++i) {
        scanf(" %c %d", &kind_mark, &t);
        card[strchr(mark, kind_mark) - mark][t - 1] = 1;
    }
    
    for(i = 0; i < MARK; ++i) 
        for(j = 0; j < TYPE; ++j) 
            if(!card[i][j]) 
                printf("%c %d\n", mark[i], j + 1);
            
    return ( EXIT_SUCCESS );
}