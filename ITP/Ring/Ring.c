#include <stdio.h>
 
#define MAX 100

enum {YES, NO} judge; 
/*
    与えられるリング状の文字列を s,
        そこから見つける文字列を p とする.
    s の長さを取得しつつ，
        s を2つ連結した custom_word を作る.        
    custom_word の先頭から p を走査.
        p の長さを取得.
    custom_word の先頭から，p の一文字目に一致するものを探す．
        一致したら，そこから custom_word を検査して
    p のすべての文字に一致するか調べる．
        一致したら，走査を終えて Yes と表示．
    一致しない場合，また custom_word から p の一文字目を探す．
        どれも一致しない場合，No と表示．
*/
 
int main() {
    int i, j;
    int s_length, p_length;
    
    char s[MAX + 1];
    char p[MAX + 1];
    char custom_word[MAX * 2 + 1];
    
    scanf("%s %s", s, p);
 
    for (i = 0; (custom_word[i] = s[i]) != '\0'; ++i); //custom_word[i] に リング文字列(終端文字が来るまで)が代入される
    
    s_length = i;
    for (i = 0; (custom_word[s_length + i] = s[i]) != '\0'; ++i);
    for (i = 0; p[i] != '\0'; ++i);
    
    p_length = i;
    judge    = NO;
    for (i = 0; i < s_length; ++i) {
        if (custom_word[i] == p[0]) {
            for (j = 0; j < p_length; ++j) {
                if (custom_word[i + j] == p[j]) {
                    judge = YES;
                    continue;
                } else {
                    judge = NO;
                    break;
                }
            }
            if (judge == YES) break;
            else continue;
        }
    }
     
    (judge == YES) ? printf("Yes\n") : printf("No\n"); 

    return ( 0 );
}