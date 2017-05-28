#include <stdio.h>
#include <stdlib.h>

#define SIZE 100 // CONST TO ARRAY SIZE.

int main() {
    int m, n, o; // m * n line
    int i, j; // Loop Counter.
    
    int    a[SIZE][SIZE]     = { 0 };
    int    b[SIZE]           = { 0 };
    int  ans[SIZE]           = { 0 };
    
    scanf("%d %d",&n, &m);
    
    for(i = 0; i < n; ++i) 
        for(j = 0; j < m; ++j) 
            scanf("%d", &a[i][j]);
            
    for(i = 0; i < m; ++i) 
        scanf("%d", &b[i]);
    
    for(i = 0; i < n; ++i) {
        o = 0;
        for(j = 0; j < m; ++j) {
            o += (a[i][j] * b[j]);
        }
        ans[i] = o;
    }
    
    for(i = 0; i < n; ++i) 
        printf("%d\n", ans[i]);
    
    return ( 0 );
}