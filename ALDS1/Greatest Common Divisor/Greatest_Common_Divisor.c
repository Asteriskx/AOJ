#include <stdio.h>

int swap(int, int);
int gcd(int, int);

int swap(int x, int y) {
    int buf;
    
    buf = x;
    x   = y;
    y   = buf;
    
    return y;
}

int gcd(int x, int y) {
    int buf;
    
    if (x < y) swap(x, y);
    while (y > 0) {
        buf = x % y;
        x   = y;
        y   = buf;
    }
    
    return x;
}

int main() {
    int x, y;
    
    scanf("%d %d", &x, &y);
    printf("%d\n", gcd(x, y));
    
    return ( 0 );
}