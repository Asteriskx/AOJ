#include <stdio.h>

#define SIZE 32768

void b_Sort(int *, int);

void b_Sort(int *num, int array_size) {
  int i, j, temp;

  for(i = 0; i < (array_size - 1); i++) {
      for(j = (array_size - 1); j > i; j--) {
          if(num[j-1] > num[j]) {
              temp     = num[j];
              num[j]   = num[j-1];
              num[j-1] = temp;
          }
      }
  }
  
}

int main() {
    int nCnt, i;
    int array[SIZE] = {0};
    long ans = 0;
    
    scanf("%d", &nCnt); //Data
    
    for(i = 0; i < nCnt; i++) {
        scanf("%d", &array[i]);
        ans += array[i];
    }
    
    b_Sort(array, nCnt);
    
    printf("%d %d %ld\n", array[0], array[nCnt-1], ans);
    
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

#define Max(a,b) (a > b ? a : b)
#define Min(a,b) (a < b ? a : b)
 
int main(){
  int n,i;
  int *a;
  int max,min;
  long sum=0;
   
  scanf("%d",&n);
  a = (int *)malloc(sizeof(int) * n);
 
  for(i=0;i<n;i++)
    scanf("%d", &a[i]);
   
  //init max & min
  max = a[0];
  min = a[0];
   
   
  //cal max, min and sum
  for(i=0;i<n;i++){
    if(i < n-1){
      max = Max(max, a[i+1]);
      min = Min(min, a[i+1]);
    }
    sum += a[i];
  }
   
  printf("%d %d %ld\n", min, max, sum);
   
  free(a);
  return 0;
}
*/