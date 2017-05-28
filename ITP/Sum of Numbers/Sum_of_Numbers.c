#include<stdio.h>

int main() {

    char ch;
    int ans = 0;

    while( (ch = getchar()) != EOF) {
        if(ch == '\n') {
            if(ans == 0) 
                return 0;
            printf("%d\n", ans);
            ans = 0;
        } else {
            ans += ch - '0';
        }
    }

    return ( 0 );
}

