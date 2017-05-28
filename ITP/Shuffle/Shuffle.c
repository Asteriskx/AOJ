#include <stdio.h>
#include <string.h>

#define LENGTH (256)
#define END    ('-')

int main() {
    int m, h, num;
    int i, j, k;
    
    char str[LENGTH];
    char tmp[LENGTH];
    
    for(;;) {
        scanf("%s", str);

        if ((str[0] == END) && (str[1] == '\0')) break;
        scanf("%d", &h);

        for (i = 0; i < h; i++) {
            scanf("%d", &num);

            k = 0;
            for (j = num; j < strlen(str); ++j) 
                tmp[k++] = str[j];
      
            for (j = 0; j < num; ++j)
                tmp[k++] = str[j];
      
            tmp[k] = '\0';
            strcpy(str, tmp);
        }
        
        printf("%s\n", str);
    }

    return ( 0 );
}