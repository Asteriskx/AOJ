#include <stdio.h>

#define SIZE 40
#define TRUE  1
#define FALSE 0
 
typedef struct Cards {
    char str;
    int  value;
} cards;
 
void int_swap(int *, int *);
void char_swap(char *, char *);

void int_swap(int *x, int *y) {
    int tmp;
 
    tmp = *x;
    *x  = *y;
    *y  = tmp;
}
 
void char_swap(char *x, char *y) {
    char tmp;
 
    tmp = *x;
    *x  = *y;
    *y  = tmp;
}
 
int main() {
    
    cards card[SIZE], bubble[SIZE], selection[SIZE];
    int i, j, num, min;
    int stable = TRUE;
 
    scanf("%d", &num);
 
    for (i = 0; i < num; i++) {
        scanf("%c%d", &card[i].str, &card[i].value);
 
        bubble[i].str      = card[i].str;
        bubble[i].value    = card[i].value;
        selection[i].str   = card[i].str;
        selection[i].value = card[i].value;
    }
 
    for (i = 0; i < num; ++j) 
        for (j = num - 1; j > i; --j) 
            if (bubble[j].value < bubble[j - 1].value) {
                char_swap(&bubble[j].str, &bubble[j - 1].str);
                int_swap(&bubble[j].value, &bubble[j - 1].value);
            }
        
    for (i = 0; i < num; i++) {
        min = i;
        for (j = i; j < num; j++) 
            if (selection[j].value < selection[min].value) 
                min = j;
 
        if (min != i) {
            char_swap(&selection[i].str, &selection[min].str);
            int_swap(&selection[i].value, &selection[min].value);
        }
    }
 
    for (i = 0; i < num; i++) {
        if (bubble[i].str != selection[i].str) {
            stable = FALSE;
            break;
        }
    }
 
    for (i = 0; i < num - 1; i++) 
        printf("%c%d ", bubble[i].str, bubble[i].value);
 
    printf("%c%d\n", bubble[num - 1].str, bubble[num - 1].value);
    printf("Stable\n");
 
    for (i = 0; i < num - 1; i++) 
        printf("%c%d ", selection[i].str, selection[i].value);
 
    printf("%c%d\n", selection[num - 1].str, selection[num - 1].value);
 
    if (stable) printf("Stable\n");
    else        printf("Not stable\n");

    return ( 0 );
}
