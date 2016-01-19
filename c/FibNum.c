#include <stdio.h>
int main(){
int N, i, result;
scanf("%d", &N);
if (N < 2) {
	result = 1;
} else {
	int fib[N];
	fib[0] = fib[1] = 1;
	for (i = 2; i <= N; i++) {
		fib[i] = (fib[i-1] +fib[i-2]);
		fib[i] %= 1000000007;
	}
	result = fib[N];
}
printf("%d", result);
}
