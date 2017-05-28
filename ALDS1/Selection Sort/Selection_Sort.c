#include <stdio.h>
 
#define SIZE     128
#define TRUE       1
#define SUCCESS    0

#define DEBUG_MODE 0

int  selection_sort(int *, int);
void print_ary(int *, int);
    
int selection_sort(int *target, int length) {
    int i, j;
    int buf, cnt = 0, min = 0;
    
    for (i = 0; i < length; ++i) {
        min  = i;                                   // No.i in small value.
        for (j = i; j < length; ++j) 
            if (target[j] < target[min]) min = j;   // Better small value. Set small loop value.
            
        if (min != i) {                      
            buf         = target[i];                // Change No.i in value <=> small value 
            target[i]   = target[min];
            target[min] = buf;
            ++cnt;        
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
    
    for (i = 0; i < num; ++i) 
        scanf("%d", &ary[i]);
    
    cnt = selection_sort(ary, num);
    
    #if DEBUG_MODE
        printf("╢│▌─ллллллллллллл = %d\n", cnt);
    #endif 
    
    print_ary(ary, num);
    
    printf("%d\n", cnt);
    
    return ( SUCCESS );
}