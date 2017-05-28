#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE      6
#define TYPE      3
#define ARY     100
#define TRUE      1
#define FALSE     0

typedef struct Dice {
    int top;    // ã–Ê
    int right;  // ‰E–Ê
    int left;   // ¶–Ê
    int front;  // ‘O–Ê
    int back;   // ”w–Ê
    int bottom; // ’ê–Ê
} dice;

typedef void (*DiceCmd)(dice *dp); // ŠÖ”ƒ|ƒCƒ“ƒ^
 
void turn_back(dice *dp) { // Œã“]
    int buf;
 
    buf          = dp -> top;
    dp -> top    = dp -> front;
    dp -> front  = dp -> bottom;
    dp -> bottom = dp -> back;
    dp -> back   = buf;
}
 
void turn_front(dice *dp) { //‘O“]
    int buf;
 
    buf          = dp -> top;
    dp -> top    = dp -> back;
    dp -> back   = dp -> bottom;
    dp -> bottom = dp -> front;
    dp -> front  = buf;
}
 
void turn_right(dice *dp) { // ‰E‰ñ“]
    int buf;
 
    buf          = dp -> top;
    dp -> top    = dp -> left;
    dp -> left   = dp -> bottom;
    dp -> bottom = dp -> right;
    dp -> right  = buf; 
}
 
void turn_left(dice *dp) { // ¶‰ñ“]
    int buf;
 
    buf          = dp -> top;
    dp -> top    = dp -> right;
    dp -> right  = dp -> bottom;
    dp -> bottom = dp -> left;
    dp -> left   = buf;
}
 
void clockwise(dice *dp) { // ŽžŒv‰ñ‚è
    int buf;
 
    buf         = dp -> front;
    dp -> front = dp -> right;
    dp -> right = dp -> back;
    dp -> back  = dp -> left;
    dp -> left  = buf;
}
 
void anticlockwise(dice *dp) { //”½ŽžŒv‰ñ‚è
    int buf;
 
    buf         = dp -> front;
    dp -> back  = dp -> left;
    dp -> left  = dp -> back;
    dp -> back  = dp -> right;
    dp -> left  = buf;
}
 
void input_dice(dice *dp) { // “ü—Í
    scanf("%d", &dp -> top);
    scanf("%d", &dp -> front);
    scanf("%d", &dp -> right);
    scanf("%d", &dp -> left);
    scanf("%d", &dp -> back);
    scanf("%d", &dp -> bottom);
}

int is_equals_dice(dice *dp, dice *dp2) {
    dice is_d;

    int i, j;
    int success;
 
    DiceCmd cmd[SIZE][TYPE] = {
        { turn_back,  NULL, NULL },     // front  -> Top
        { turn_front, NULL, NULL },     // back   -> Top
        { turn_right, NULL, NULL },     // right  -> Top
        { turn_left,  NULL, NULL },     // left   -> Top
        { NULL,  NULL, NULL },          // Top    -> Top
        { turn_back, turn_back, NULL }, // Bottom -> Top
    };
    
    // Solve
    success = 0;
    for(i = 0; i < SIZE; ++i) {
        // init 
        memcpy( &is_d, dp, sizeof(dice) );
        // Turn
        for(j = 0; cmd[i][j] != NULL; ++j)
            cmd[i][j](&is_d);
            
        // Turn & Check
        j = 1;
        for(;;) {
            if( memcmp(&is_d, dp2, sizeof(dice)) == 0 ) {
                success = TRUE;
                break;
            } else if( j < TYPE + 1 ) {
                clockwise(&is_d); ++j;
            } else {
                break;
            }
        }
 
        if( success ) break;
    }
 
    return success;
}

int main() {
    dice d[ARY];
    int num, found;
    int i, j;
 
    // Input
    scanf("%d", &num);
    for (i = 0; i < num; ++i)
        input_dice(&d[i]);
    
    // Solve
    found = 0;
    for (i = 0; i < num - 1; ++i) {
        for (j = i + 1; j < num; ++j) {
            if (is_equals_dice(&d[i], &d[j])) {
                found = TRUE;
                break;
            }
        }
        if( found ) break;
    }
 
    // Output
    if( found ) printf("No\n");
    else printf("Yes\n");
 
    return ( 0 );
}