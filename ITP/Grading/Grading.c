#include <stdio.h>

int main(int argc, char *argv[]) {
    int     m, f, r;
    int     score;
    char    judge;
    
    for(;;) {
        scanf("%d %d %d", &m, &f, &r);
        
        if(m == -1 && f == -1 && r == -1)
            break;
        
        score = m + f;
        
        if(score >= 80) 
            judge = 'A';
        else if(score >= 65 && score < 80)
            judge = 'B';
        else if(score >= 50 && score < 65)
            judge = 'C';
        else {
            if(r >= 50)
                judge = 'C';
            else 
                judge = 'D';
        }
        
        if(m == -1 || f == -1 || score < 30)
            judge = 'F';
        
        printf("%c\n", judge);
    }
    
    return ( 0 );
}           
