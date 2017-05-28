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
        ret = strcmp(Taro_word, Hanako_word); // �������Ō������A��r��̌��ʂ� ret �ɑ��
        if (ret > 0) t_pt += WIN;             // ��r�������ʁATaro_word  ���傫�������ꍇ
        if (ret < 0) h_pt += WIN;             // ��r�������ʁAHanako_word ���傫�������ꍇ
        if (ret == 0) { ++t_pt; ++h_pt; }     // ��r�������ʁA���������������ꍇ
    }   
     
    printf("%d %d\n", t_pt, h_pt);
     
    return ( 0 );
}