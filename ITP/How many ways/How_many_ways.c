#include <stdio.h>

int main() {
    int n, x;
    int i, j, k;
    int cnt = 0;
    
    for(;;) {
        scanf("%d %d", &n, &x);
        if(n == 0 && x == 0) break;
        
        cnt = 0;
        
        for(i = 1; i * 3 + 3 <= x; ++i) {
            for(j = i + 1; i + 2 * j + 1 <= x; ++j) {
                for(k = n; k > j; --k) {
                    if(x == (i + j + k)) {
                        ++cnt;
                        break;
                    } else if(x >= (i + j + k)) {
                        break;
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
    
    return ( 0 );
}