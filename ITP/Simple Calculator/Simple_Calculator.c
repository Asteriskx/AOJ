#include <stdio.h>

int main() {
    int cLeft, cRight;
    char op;
    
    for(;;) { 
        scanf("%d %c %d", &cLeft, &op, &cRight);
        if(op == '?') break;
        else if (op == '+') printf("%d\n", cLeft + cRight);  
        else if (op == '-') printf("%d\n", cLeft - cRight);
        else if (op == '*') printf("%d\n", cLeft * cRight);
        else if (op == '/') printf("%d\n", cLeft / cRight); 
    }
    
    return ( 0 );
}