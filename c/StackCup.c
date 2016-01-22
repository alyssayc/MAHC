#include <stdio.h>
#include <string.h>
int main(){
int N, M, cup, i, index = 0;
scanf("%d %d", &N, &M);
int stack[N];
char command[5];
for (i = 0; i < M; i++){
	scanf("%s", command);
	if (strcmp(command, "PUSH") == 0){
		scanf("%d", &cup);
		stack[index++] = cup;
	} else{
		printf("%d\n", stack[--index]);
	}
}
}
