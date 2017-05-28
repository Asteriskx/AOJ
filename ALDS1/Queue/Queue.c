#include <stdio.h>
 
#define SIZE 100000
#define N_SIZE   16
#define ADD       1
#define SUCCESS   0
 
typedef struct Param {
  char name[N_SIZE];
  int  exec_time;
} param;
 
void enque(param);
param deque(void);
void print_queue(void);
void print_result(void);
 
// global
param Q[SIZE + ADD];
param R[SIZE + ADD];

int length;
int head;
int tail;
int quantum;

void enque(param p) {
 
    Q[tail] = p;
  
    if (tail == length) tail = 0;
    else tail++;
}
 
param deque(void) {
    param p;
    
    p = Q[head];
    
    if (head == length) head = 0;
    else head++;
  
    return ( p );
}
 
void print_queue(void) {
    int i;
 
    for (i = head; i != tail; i++) {
        if (i == length) {
            printf("%s %d\n", Q[i].name, Q[i].exec_time);
            i = 0;
        }
        printf("%s %d\n", Q[i].name, Q[i].exec_time);
    }
}
 
void print_result(void) {
    int i;
 
    for (i = 0; i < length; ++i)
        printf("%s %d\n", R[i].name, R[i].exec_time);
}

int main() {
    param p;
    
    int i;
    int cnt = 0, q_res = 0;
 
    scanf("%d %d", &length, &quantum);
 
    head = length / 2;
    tail = length / 2;
 
    for (i = 0; i < length; i++) {
        scanf("%s %d", p.name, &p.exec_time);
        enque(p);
    }
 
    while (cnt != length) { 
        p = deque();
        if ((p.exec_time - quantum) <= 0) {
            q_res       += p.exec_time;
            p.exec_time  = q_res;
            R[cnt++]     = p;
        } else {
            p.exec_time -= quantum;
            enque(p);
            q_res       += quantum;
        }
    }
    print_result();
    
    return ( SUCCESS );
}
 