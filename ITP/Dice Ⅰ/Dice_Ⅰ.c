#include <stdio.h>
#include <string.h>

#define SIZE 128

#define DEBUG_MODE 0

typedef struct Dice {
    int top;    // 上面
    int right;  // 右面
    int left;   // 左面
    int front;  // 前面
    int back;   // 背面
    int bottom; // 底面
} dice;

void rotate(dice *, char *, int);

void rotate(dice *d, char *str, int length) {
    int i;
    int buf;
    char str_buf[SIZE];
    
    for(i = 0; i < length; ++i) { 
        str_buf[i] = str[i];
        
#if DEBUG_MODE
    printf("************************\n");
    printf("i = %d\n", i);
    printf("str_buf[i] = %c\n", str_buf[i]);
#endif 
        switch ( str_buf[i] ) {
            case 'N': { // North
                buf         = d -> front;  // 上面の情報を退避
                d -> front  = d -> bottom;   
                d -> bottom = d -> back;
                d -> back   = d -> top;
                d -> top    = buf;
                break;
            } case 'S': { // South
                buf         = d -> back;
                d -> back   = d -> bottom;
                d -> bottom = d -> front;
                d -> front  = d -> top;
                d -> top    = buf;
                break;
            } case 'E': { // East
                buf         = d -> left;
                d -> left   = d -> bottom;
                d -> bottom = d -> right;
                d -> right  = d -> top;
                d -> top    = buf;
                break;
            } case 'W': { // West
                buf         = d -> right;
                d -> right  = d -> bottom;
                d -> bottom = d -> left; 
                d -> left   = d -> top;  
                d -> top    = buf;
                break;   
            }
        }
    }
}

int main() {
    dice d; // dice型 dの生成

    int  length = 0;
    char str[SIZE];
    
    scanf("%d %d %d %d %d %d", &d.top, &d.front, &d.right, &d.left, &d.back, &d.bottom);
    scanf("%s", str);

    length = strlen(str);
    rotate(&d, str, length);

    printf("%d\n", d.top);
    
    return ( 0 );
}
