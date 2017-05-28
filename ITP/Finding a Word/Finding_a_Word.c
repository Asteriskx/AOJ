#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SEARCH_SIZE      10
#define SENTENCE_SIZE  1000

#define END ("END_OF_TEXT")

int main() {
    int i;
    int find_cnt = 0;
    
    char search_word[SEARCH_SIZE];
    char sentence[SENTENCE_SIZE];

    scanf("%s", search_word);
    
    for(i = 0; search_word[i]; ++i) 
        search_word[i] = tolower(search_word[i]);
    
    for(;;) {
        scanf("%s", sentence);
        
        if( strcmp(END, sentence) == 0 ) 
            break;
        for(i = 0; sentence[i]; ++i)  
            sentence[i] = tolower(sentence[i]);
        if(strcmp(search_word, sentence) == 0) 
            ++find_cnt;
    }

    printf("%d\n", find_cnt);

    return ( 0 );
}