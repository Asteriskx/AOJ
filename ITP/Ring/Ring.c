#include <stdio.h>
 
#define MAX 100

enum {YES, NO} judge; 
/*
    �^�����郊���O��̕������ s,
        �������猩���镶����� p �Ƃ���.
    s �̒������擾���C
        s ��2�A������ custom_word �����.        
    custom_word �̐擪���� p �𑖍�.
        p �̒������擾.
    custom_word �̐擪����Cp �̈ꕶ���ڂɈ�v������̂�T���D
        ��v������C�������� custom_word ����������
    p �̂��ׂĂ̕����Ɉ�v���邩���ׂ�D
        ��v������C�������I���� Yes �ƕ\���D
    ��v���Ȃ��ꍇ�C�܂� custom_word ���� p �̈ꕶ���ڂ�T���D
        �ǂ����v���Ȃ��ꍇ�CNo �ƕ\���D
*/
 
int main() {
    int i, j;
    int s_length, p_length;
    
    char s[MAX + 1];
    char p[MAX + 1];
    char custom_word[MAX * 2 + 1];
    
    scanf("%s %s", s, p);
 
    for (i = 0; (custom_word[i] = s[i]) != '\0'; ++i); //custom_word[i] �� �����O������(�I�[����������܂�)����������
    
    s_length = i;
    for (i = 0; (custom_word[s_length + i] = s[i]) != '\0'; ++i);
    for (i = 0; p[i] != '\0'; ++i);
    
    p_length = i;
    judge    = NO;
    for (i = 0; i < s_length; ++i) {
        if (custom_word[i] == p[0]) {
            for (j = 0; j < p_length; ++j) {
                if (custom_word[i + j] == p[j]) {
                    judge = YES;
                    continue;
                } else {
                    judge = NO;
                    break;
                }
            }
            if (judge == YES) break;
            else continue;
        }
    }
     
    (judge == YES) ? printf("Yes\n") : printf("No\n"); 

    return ( 0 );
}