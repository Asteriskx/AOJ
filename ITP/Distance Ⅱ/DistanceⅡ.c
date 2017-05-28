#include <stdio.h>
#include <math.h>

#define SIZE 128
#define LIMIT  3 // 4�����̂��߁A�������ɂȂ邩��

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
    
    for (i = 0; i < LIMIT; ++i) {                              // p �捪
        ret[i] = 0;                                            // ���v�l������
        for (j = 0; j < sizeof x / sizeof x[0]; ++j) {         // �W���̗v�f�� n
            ans[i] += pow((abs(x[j] - y[j])), i + 1);          // �a�W���̍��v
            if(abs(x[j] - y[j]) > tmp) tmp = abs(x[j] - y[j]); // �ő勗��(�`�F�r�V�F�t����)
        }
        ret[i] = pow(ans[i], ((double)1 / (double)(i + 1)));   // �~���R�t�X�L�[����
    }

    for (i = 0; i < LIMIT + 1; ++i) {
        printf("%.8lf\n", ret[i]);
        if (i == LIMIT - 1) ret[LIMIT] = tmp;
    }
    
    return ( 0 );
}