//*************************
// ITP1_9_C: Card Game
//   @author K.takeyama 
//*************************
#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#define LENGTH 1024 
#define WIN       3
#define DRAW      1
 
int main() {
     
    int i;
    int num, ret;
    int t_pt = 0, h_pt = 0;
     
    const char Taro_word[LENGTH];    
    const char Hanako_word[LENGTH];
  
    scanf("%d", &num);
     
    for (i = 0; i < num; ++i) {
        scanf("%s %s", Taro_word, Hanako_word);
        ret = strcmp(Taro_word, Hanako_word); // 辞書順で検索し、比較後の結果を ret に代入
        if (ret > 0) t_pt += WIN;             // 比較した結果、Taro_word  が大きかった場合
        if (ret < 0) h_pt += WIN;             // 比較した結果、Hanako_word が大きかった場合
        if (ret == 0) { ++t_pt; ++h_pt; }     // 比較した結果、引き分けだった場合
    }   
     
    printf("%d %d\n", t_pt, h_pt);
     
    return ( 0 );
}