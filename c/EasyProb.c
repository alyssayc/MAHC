#include <stdio.h>
int main(){
int N, i, sum = 0;
scanf("%d", &N);
for (i = 0; i < N; i++){
   int a;
   scanf("%d", &a);
   sum += a;
}
printf("%d", sum);
}

