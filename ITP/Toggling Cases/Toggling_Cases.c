#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    
    for(;;) {
        scanf("%c", &ch);
        if(ch == '\n') {
            printf("\n");
            break;
        } else if( islower(ch) )
            printf("%c", toupper(ch));
          else if( isupper(ch) ) 
            printf("%c", tolower(ch));
          else
            printf("%c", ch);
    }
        
    return ( 0 );
}

/*
#include <stdio.h>

int main() {

    char c;
    int area = 'a' - 'A'; //文字コードから考えた

    while((c = getchar()) != EOF) {
        if(c >= 'a' && c <= 'z')
            c -= area;
        else if(c >= 'A' && c <= 'Z')
            c += area;
        putchar(c);
    }

    return ( 0 );

}