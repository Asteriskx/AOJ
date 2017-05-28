#include <stdio.h>

#define SIZE     128
#define SUCCESS    0

#define DEBUG_MODE 0
 
int  bubble_sort(int *, int);
void print_ary(int *, int);

int bubble_sort(int *target, int length) {
    int i, j, buf, cnt = 0;
    
    for(i = 0; i < length; ++i) {
        for (j = length - 1; i < j; --j) {
            if (target[j] < target[j - 1]) {
                buf           = target[j];
                target[j]     = target[j - 1];
                target[j - 1] = buf;
                ++cnt;
            }
        }
    }
    
    return ( cnt );
}

void print_ary(int *target, int length) {
    int i;
    
    for (i = 0; i < length - 1; ++i) printf("%d ", target[i]);
    printf("%d\n", target[length - 1]);
}

int main() {
    int i, num, cnt = 0;
    int ary[SIZE];
    
    scanf("%d", &num);
    
    for(i = 0; i < num; ++i) 
        scanf("%d", &ary[i]);
    
    cnt = bubble_sort(ary, num);
    
    #if DEBUG_MODE
        printf("╢│▌─ллллллллллллл = %d\n", cnt);
    #endif 
    
    print_ary(ary, num);
    
    printf("%d\n", cnt);
    
    return ( SUCCESS );
}