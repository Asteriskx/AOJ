#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE  6
#define TYPE  3
#define TRUE  1
#define FALSE 0

typedef struct Dice {
    int top;    // 上面
    int right;  // 右面
    int left;   // 左面
    int front;  // 前面
    int back;   // 背面
    int bottom; // 底面
} dice;

typedef void (*DiceCmd)(dice *dp); // 関数ポインタ
 
void turn_back(dice* dp) {
    int buf;
 
    buf          = dp -> top;
    dp -> top    = dp -> front;
    dp -> front  = dp -> bottom;
    dp -> bottom = dp -> back;
    dp -> back  = buf;
}
 
void turn_front(dice* dp) {
    int buf;
 
    buf          = dp -> top;
    dp -> top    = dp -> back;
    dp -> back   = dp -> bottom;
    dp -> bottom = dp -> front;
    dp -> front  = buf;
}
 
void turn_right(dice* dp) {
    int buf;
 
    buf          = dp -> top;
    dp -> top    = dp -> left;
    dp -> left   = dp -> bottom;
    dp -> bottom = dp -> right;
    dp -> right  = buf; 
}
 
void turn_left(dice* dp) {
    int buf;
 
    buf         = dp -> top;
    dp ->top    = dp -> right;
    dp ->right  = dp -> bottom;
    dp ->bottom = dp -> left;
    dp ->left   = buf;
}
 
void clockwise(dice* dp) { // 時計回り
    int buf;
 
    buf         = dp -> front;
    dp -> front = dp -> right;
    dp -> right = dp -> back;
    dp -> back  = dp -> left;
    dp -> left  = buf;
}
 
void anticlockwise(dice* dp) { //反時計回り
    int buf;
 
    buf         = dp -> front;
    dp -> back  = dp -> left;
    dp -> left  = dp -> back;
    dp -> back  = dp -> right;
    dp -> left  = buf;
}
 
void input_dice(dice *dp) { // 入力
    scanf("%d", &dp -> top);
    scanf("%d", &dp -> front);
    scanf("%d", &dp -> right);
    scanf("%d", &dp -> left);
    scanf("%d", &dp -> back);
    scanf("%d", &dp -> bottom);
}

int main() {
    
    dice d, d_ary[TYPE - 1];
    int success;
    int num;
    int i, j;
    
    DiceCmd cmd[SIZE][TYPE] = {
        { turn_back,  NULL, NULL },     // front  -> Top
        { turn_front, NULL, NULL },     // back   -> Top
        { turn_right, NULL, NULL },     // right  -> Top
        { turn_left,  NULL, NULL },     // left   -> Top
        { NULL,  NULL, NULL },          // Top    -> Top
        { turn_back, turn_back, NULL }, // Bottom -> Top
    };
    
        // Input
    scanf("%d", &num);
    
    for (i = 0; i < TYPE - 1; ++i) 
        input_dice( &d_ary[i] );
    
    // Solve
    success = 0;
    for (i = 0; i < SIZE; ++i) {
        // init
        memcpy( &d, &d_ary[0], sizeof(dice) );
        // Turn
        for (j = 0; cmd[i][j] != NULL; ++j) 
            cmd[i][j](&d);
        
        // Turn & Check
        j = 1;
        for (;;) { 
            if ( !(memcmp(&d, &d_ary[1], sizeof(dice))) ) {
                success = TRUE;
                break;
            } else if( j < TYPE ) {
                clockwise(&d); j++;
            } else {
                break;
            }
        }
        if( success ) break;
    }
 
    // Output
    if( success ) printf("Yes\n");
    else printf("No\n");
 
    return ( 0 );
}