#include <stdio.h>
 
void Judge(int, int);
 
void Judge(int a, int b) {
    if(a < b) 
        printf("a < b\n");
    else if(a > b) 
        printf("a > b\n");
    else
        printf("a == b\n");
}
 
int main() {
    int x, y;
     
    scanf("%d %d", &x, &y);
     
    Judge(x, y);
     
    return 0;
}