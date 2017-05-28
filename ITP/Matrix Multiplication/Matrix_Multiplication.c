#include <stdio.h>

#define SIZE 100 // CONST TO ARRAY SIZE.

int main() {
    int m, n, l; 
    long buf; // ここ注意(退避領域のサイズを考えなければならなかった)
    int i, j, k; // Loop Counter.
    
    int    a[SIZE][SIZE] = { 0 };
    int    b[SIZE][SIZE] = { 0 };
    long ans[SIZE][SIZE] = { 0 };
    
    scanf("%d %d %d",&n, &m, &l);
    
    for(i = 0; i < n; ++i) 
        for(j = 0; j < m; ++j)  
            scanf("%d", &a[i][j]);
    
    for(i = 0; i < m; ++i) 
        for(j = 0; j < l; ++j)  
            scanf("%d", &b[i][j]);
            
    for(i = 0; i < n; ++i) {
        for(j = 0; j < l; ++j) {
            buf = 0;
            for(k = 0; k < m; ++k) { 
                buf += (a[i][k] * b[k][j]);
                ans[i][j] = buf;
            }
        }
    }
    
    for(i = 0; i < n; ++i) { 
        for(j = 0; j < l; ++j) {
            printf("%ld", ans[i][j]); 
            if(j != l - 1) putchar(' ');
        }
        printf("\n");
    }
    
    return ( 0 );
}