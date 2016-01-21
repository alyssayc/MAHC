#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    long int M, K; // measures length (1 <= M <= 1000000) and cow id (1 <= K < = 10^10)
    int N, L, B, R; // # of races (1 <= N <= 1000) and # of lanes (2 <= L <= 1000)
    // where N*L <= 10000. # of bulls in each race ( 1 <= B <= L) and # of laps (1<=R<=8)
    char *line;
    scanf("%d %ld %d", &N, &M, &L);
    printf("N: %d, M: %ld, L: %d\n", N, M, L);
    char bull[10000]; // allocate memory to store the info of the bulls?
    for (int i = 0; i < N; i++){ // The number of races occuring
        printf("i: %d\n", i);
        scanf("%d %d", &B, &R);
        printf("B: %d, R: %d\n", B, R);
        for (int j = 0; j < B; j++){ // The number of input lines for each bull
            printf("j: %d\n", j);
            
            //char *cow[R + 2];
            scanf("%s", line);
            printf("line: %s", line);
            cow[0] = strtok(line, " ");
            printf("cow[0]: %s", cow[0]);
            for (int k = 1; k < R + 1; k++){
                cow[k] = strtok(NULL, " ");
                printf("cow[%d]: %s", k, cow[k]);
            }
        }
    }
}
