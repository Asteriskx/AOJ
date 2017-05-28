#include <stdio.h>

#define GET_ALPHA 26

int main() {
    int i;
    char ch;
    unsigned char alphabet[GET_ALPHA] = {0};

    while ((ch = getchar()) != EOF) {
        if ('A' <= ch && ch <= 'Z') {
            alphabet[ch - 'A']++;
        } else if ('a' <= ch && ch <= 'z')
            alphabet[ch - 'a']++;
    }

    for (i = 0; i < GET_ALPHA; ++i) 
        printf("%c : %d\n", 'a' + i, alphabet[i]);

    return ( 0 );
}