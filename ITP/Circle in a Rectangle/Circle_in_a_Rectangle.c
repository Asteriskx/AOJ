#include <stdio.h>

void Judge_Rect_Circle(int, int, int, int, int);

void Judge_Rect_Circle(int W, int H, int x, int y, int r) {
    int flag = 0;
    
    if(x + r > W)       flag = 1;
    else if( y + r > H) flag = 1;
    else if( r > x)     flag = 1;
    else if(r > y)      flag = 1;

    if(!flag)
        printf("Yes\n");
    else 
        printf("No\n");
}

int main() {
    int width = 0, height = 0;
    int x = 0, y = 0;
    int r = 0;
    
    scanf("%d %d %d %d %d", &width, &height, &x, &y, &r);
    Judge_Rect_Circle(width, height, x, y, r);
    
    return 0;
}

#include <stdio.h>

int main() {
    int read;
    int i = 1;
    
    do {
        printf("case %d ", i);
        scanf("%d", &read);
    while(read == 0);
    
    return 0; 
     
}