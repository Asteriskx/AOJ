#include <stdio.h>

#define SIZE    1024
#define LENGTH   128

#define TEST       0

void insert_sort(int *, int);
void print_ary(int *, int);

void insert_sort(int *target, int length) {
    int i, j; 
    int buf;
    
    print_ary(target, length);
    
    for(i = 1; i < length; ++i) {
        buf = target[i];
        for(j = i - 1; j >= 0 && target[j] > buf; --j) {
            target[j + 1] = target[j];
        }
        target[j + 1] = buf;
        #if TEST
            printf("├╜─лллллллллллл╡!\n");
        #endif
        print_ary(target, length);
    }   
}

void print_ary(int *target, int length) {
    int i;
    
    for(i = 0; i < length; ++i) printf("%d ", target[i]);
    printf("%d\n", target[length]);
}

int main() {
    int num;
    int i, j;
    
    int ary[SIZE];
    
    scanf("%d", &num);
    
    for(i = 0; i < num; ++i) 
        scanf("%d", &ary[i]); 
    
    insert_sort(ary, num);
    
    return ( 0 );
            
}