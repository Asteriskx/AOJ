#include <stdio.h>
 
int area(int, int);
int around(int, int);
 
int area(int ROW, int COL) {
    int ret = 0;
    ret = ROW * COL; 
    return ret;
}
 
int around(int ROW, int COL) {
    int ret = 0;
    ret = (ROW * 2) + (COL * 2);
    return ret;
}
 
int main() {
    int x, y;
    int area_ans = 0, around_ans = 0; 
     
    scanf("%d %d",&x, &y);
     
    area_ans = area(x, y);
    around_ans = around(x, y);
     
    printf("%d %d\n", area_ans, around_ans);
     
    return 0;
}