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
        ret = strcmp(Taro_word, Hanako_word); // «‘‡‚ÅŒŸõ‚µA”äŠrŒã‚ÌŒ‹‰Ê‚ğ ret ‚É‘ã“ü
        if (ret > 0) t_pt += WIN;             // ”äŠr‚µ‚½Œ‹‰ÊATaro_word  ‚ª‘å‚«‚©‚Á‚½ê‡
        if (ret < 0) h_pt += WIN;             // ”äŠr‚µ‚½Œ‹‰ÊAHanako_word ‚ª‘å‚«‚©‚Á‚½ê‡
        if (ret == 0) { ++t_pt; ++h_pt; }     // ”äŠr‚µ‚½Œ‹‰ÊAˆø‚«•ª‚¯‚¾‚Á‚½ê‡
    }   
     
    printf("%d %d\n", t_pt, h_pt);
     
    return ( 0 );
}