#include <stdio.h>

void swap(int *, int *);
void b_sort(int *, int *, int *);

void swap(int *nx, int *ny) {
    int temp = *nx;
    *nx = *ny;
    *ny = temp;
    
}

void b_sort(int *n1, int *n2, int *n3) {
    if (*n1 > *n2) swap(n1, n2);
    if (*n2 > *n3) swap(n2, n3);
    if (*n1 > *n2) swap(n1, n2);
}

int main() {
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    b_sort(&a, &b, &c);
    printf("%d %d %d",a, b, c);
    
    return 0;
}