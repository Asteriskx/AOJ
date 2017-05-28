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

dice *rotate(dice *d, char);

dice *rotate(dice *d, char str) {
    int buf;
  
    switch ( str ) {
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
   
int main() {
    dice d;    // dice型 d1の定義
    dice *root; // dice型 の ポインタを管理する
    int i, num, tp, fp;
       
    root = &d; // d1のアドレスを管理ポインタ root に代入
    
    scanf("%d %d %d %d %d %d", &d.top, &d.front, &d.right, &d.left, &d.back, &d.bottom);
    scanf("%d", &num);
  
    for(i = 0; i < num; ++i) { 
        scanf("%d %d", &tp, &fp);
        
        if      (tp == d.top);     // None
        else if (tp == d.front)    root = rotate(root, 'N');
        else if (tp == d.right)    root = rotate(root, 'W');
        else if (tp == d.left)     root = rotate(root, 'E');
        else if (tp == d.back)     root = rotate(root, 'S');
        else if (tp == d.bottom) { root = rotate(root, 'N'); root = rotate(root, 'N'); }
   
        if      (fp == d.front) printf("%d\n", d.right);
        else if (fp == d.right) printf("%d\n", d.back);
        else if (fp == d.left)  printf("%d\n", d.front);
        else if (fp == d.back)  printf("%d\n", d.left);
    }
   
    return ( 0 );
}
