#include <stdio.h>
 
int pow( int );
 
int pow(int num) {
    int ret = 0;
    ret = num * num * num;
    return ret;
}
 
int main() {
    int x, ans;
    scanf("%d", &x);
     
    ans = pow(x);
    printf("%d\n", ans);
 
    return 0;
 
}