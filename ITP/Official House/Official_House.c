#include <stdio.h>

#define AREA 4
#define B    3  // bill
#define F    10 // floor

int main() {
    int group[AREA][B][F] = {0};
    int i, j, k;
    int num, b, f, r, v;
    
    scanf("%d", &num);
    
    for(i = 0; i < num; ++i) {
        scanf("%d %d %d %d", &b, &f, &r, &v);
        group[b - 1][f - 1][r - 1] += v;
    }
    
    for(i = 0; i < AREA; ++i) {
        if(i > 0) printf("####################\n");
        for(j = 0; j < B; ++j) {
            for(k = 0; k < F; ++k) {
                printf(" %d", group[i][j][k]);
            }
            printf("\n");
        }
    }
    
    return ( 0 );
}
