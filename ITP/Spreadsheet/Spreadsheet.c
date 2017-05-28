#include <stdio.h>

#define ROW     101
#define COL     101

int main() {

    int i, j;
    int row, col;
    
    int rc[ROW][COL] = {0};

    scanf("%d %d", &row, &col);
    
    for(i = 0; i < row; ++i) 
        for(j = 0; j < col; ++j) 
            scanf("%d", &rc[i][j]);
        
    for(i = 0; i < row; ++i) {
        for(j = 0; j < col; ++j) {
            rc[i][col]   += rc[i][j];
            rc[row][j]   += rc[i][j];
            rc[row][col] += rc[i][j];
        }
    }
    
    for(i = 0; i <= row; ++i) {
        for(j = 0; j <= col; ++j) {
            printf("%d", rc[i][j]);
            (j == col) ? putchar('\n') : putchar(' ');
        }
    }
    
    return ( 0 );
}



/*int main() { 
    int r,c,tmp;
     
    scanf("%d %d", &r, &c); 
    int sheet[r + 1][c + 1]; 
    sheet[r][c] = 0; 
    
    for(int i = 0; i < r; i++) { 
        tmp = 0; 
        for(int j = 0; j < c; j++) { 
            if(i == 0) sheet[r][j] = 0; 
            scanf("%d", &sheet[i][j]); 
            tmp         += sheet[i][j]; 
            sheet[r][j] += sheet[i][j];
            sheet[r][c] += sheet[i][j]; 
        } 
        sheet[i][c] = tmp; 
    }
     
    for(int i = 0; i < r + 1; i++) { 
        for(int j = 0; j < c + 1; j++) {  
            if(j < c) { 
                printf("%d ", sheet[i][j]); 
            } else { 
                printf("%d\n", sheet[i][j]); 
            } 
        } 
    }
     
    return 0; 
}
*/
