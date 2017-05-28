/*****************************************
    ITP1_9_D: String - Transformation
    
    ������ strstr �ɑ΂��āA�^����ꂽ���߂̗�����s����v���O�������쐬���Ă��������B���߂͈ȉ��̑���̂����ꂩ�ł��F
    print a b: strstr �� a �����ڂ��� b �����ڂ܂ł��o�͂���B
    reverse a b: strstr �� a �����ڂ��� b �����ڂ܂ł��t���ɂ���B
    replace a b p: strstr �� a �����ڂ��� b �����ڂ܂ł� p �ɒu��������B
    �����ł́A������ strstr �̍ŏ��̕����� 0 �����ڂƂ��܂��B
    Input
        1�s�ڂɕ����� strstr ���^�����܂��Bstrstr �͉p�������̂݊܂݂܂��B2�s�ڂɖ��߂̐� q ���^�����܂��B���� q �s�Ɋe���߂���L�̌`���ŗ^�����܂��B

    Output
        �e print ���߂��Ƃɕ�������P�s�ɏo�͂��Ă��������B

******************************************/
//-----------------------------------------------------
// Include
//-----------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------------------------------------------------
// Define
//-----------------------------------------------------
#define SIZE         1024
#define STR_BUF_SIZE SIZE +  1
#define BUF_SIZE     SIZE + 24

#define DEBUG_MODE   0

//-----------------------------------------------------
// Prototype
//-----------------------------------------------------
void print(char *, int, int);
void reserve(char *, int, int);
void replace(char *, int, int, char *);
int  judge(const char *);
void exec(int, char *, int, int, char *);

//-----------------------------------------------------
// Function : print
// Argument : char *str
//            int  a 
//            int  b
//-----------------------------------------------------
void print(char *str, int a, int b) {
    int i;
 
    for(i = a; i < (b + 1); ++i) printf("%c", str[i]);
    putchar('\n');
 
    return;
}
 
//-----------------------------------------------------
// Function : reverse
// Argument : char *str
//            int  a 
//            int  b
//-----------------------------------------------------
void reverse(char *str, int a, int b) {
    int i;
    int pos = b - a + 1;
    char c;
 
    for(i = 0; i < (pos / 2); ++i) {
        c = str[i + a];
        str[i + a] = str[pos - i + a - 1];
        str[pos - i + a - 1] = c;
    }
 
    #if DEBUG_MODE
        printf("%s\n", str);
    #endif
 
    return;
}
 
//-----------------------------------------------------
// Function : replace
// Argument : char *str
//            int  a 
//            int  b
//            char *p
//-----------------------------------------------------
void replace(char *str, int a, int b, char *p) {
    int i;
    int pos = b - a + 1;
 
    for(i = 0; i < pos; ++i) str[i+a] = p[i];
    
    #if DEBUG_MODE
        printf("%s\n", str);
    #endif
 
    return;
}
 
//-----------------------------------------------------
// Function : judge
// Argument : const char *str
//-----------------------------------------------------
int judge(const char *str) {
    if(str[0] == 'p')       return 1;
    else if(str[2] == 'v')  return 2;
    else                    return 3;
}

//-----------------------------------------------------
// Function : exec
// Argument : char *str
//            int  a 
//            int  b
//            char *tmp
//-----------------------------------------------------
void exec(int odr,char *str, int a, int b, char *tmp) {
    switch(odr) {
        case 1: print(str, a, b);          break;
        case 2: reverse(str, a, b);        break;
        case 3: replace(str, a, b, tmp);   break;
    }
 
    return;
}

//-----------------------------------------------------
// Function : main
// Argument : Nothing
//-----------------------------------------------------
int main() {
    int i;
    int a, b, n, odr;
    char str[STR_BUF_SIZE];
    char buf[BUF_SIZE];
    char *tok;
    char tmp[] = " \n";
 
    scanf("%s", str);
 
    #if DEBUG_MODE
        printf("%s\n", str);
    #endif
 
    scanf("%d%*c", &n);
 
    for(i = 0; i < n; ++i) {
        fgets(buf, BUF_SIZE, stdin);
 
        tok = strtok(buf, tmp);   odr = judge(tok);
        tok = strtok(NULL, tmp);  a   = atoi(tok);
        tok = strtok(NULL, tmp);  b   = atoi(tok);
        if(odr == 3) tok = strtok(NULL, tmp);
 
        exec(odr, str, a, b, tok);
    }
 
    return ( 0 );
}

