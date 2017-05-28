#include <stdio.h>

#define SEC_DIV_MIN 3600
#define CONST_NUM 60

void watch(int time);

void watch(int time) {
    int h = 0, m = 0, s = 0;
    
    if(time >= 0) {
        h = time / SEC_DIV_MIN;
        m = (time % SEC_DIV_MIN) / CONST_NUM;
        s = (time % SEC_DIV_MIN) % CONST_NUM;
    }
    
    printf("%d:%d:%d\n", h, m, s);
}


int main() {
    int x;
    
    scanf("%d",&x);    
    watch(x);

    return 0;
}