#include <stdio.h>

int main() {
    int  i, cnt = 0;
    int  a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    for(i = a; i <= b; ++i) {
        if(c % i == 0)
             cnt++;
    }
    
    printf("%d\n", cnt);
        
    return ( 0 );
}

