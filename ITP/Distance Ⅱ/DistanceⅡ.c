#include <stdio.h>
#include <math.h>

#define SIZE 128
#define LIMIT  3 // 4次元のため、無限長になるから

int main() {
    int i, j;
    int n;
    int x[SIZE] = { 0 };
    int y[SIZE] = { 0 };
    
    double ans[SIZE]      = { 0.0 };
    double ret[LIMIT + 1] = { 0.0 };
    double tmp            = 0.0;
    
    scanf("%d", &n);
    
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < n; ++j){
            if (i == 0) scanf("%d", &x[j]);
            else scanf("%d", &y[j]);
        }
    }
    
    for (i = 0; i < LIMIT; ++i) {                              // p 乗根
        ret[i] = 0;                                            // 合計値初期化
        for (j = 0; j < sizeof x / sizeof x[0]; ++j) {         // 集合の要素数 n
            ans[i] += pow((abs(x[j] - y[j])), i + 1);          // 和集合の合計
            if(abs(x[j] - y[j]) > tmp) tmp = abs(x[j] - y[j]); // 最大距離(チェビシェフ距離)
        }
        ret[i] = pow(ans[i], ((double)1 / (double)(i + 1)));   // ミンコフスキー距離
    }

    for (i = 0; i < LIMIT + 1; ++i) {
        printf("%.8lf\n", ret[i]);
        if (i == LIMIT - 1) ret[LIMIT] = tmp;
    }
    
    return ( 0 );
}