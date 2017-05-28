#include <stdio.h>

void Judge_Range(int, int, int);

void Judge_Range(int a, int b, int c) {
    if(a < b) {
        if(b < c) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else {
        printf("No\n");
    }
}

int main() {
    int x, y, z;
    
    scanf("%d %d %d", &x, &y, &z);
    
    Judge_Range(x, y, z);
    
    return 0;
}