#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bin_tree{ int leaf; char data; struct bin_tree * right, *left;} node;

void insert(node ** tree, char binNum, char letter){
    node *temp = NULL;
}

int main(){
    node *root;
    root = NULL;
    int N;
    scanf("%d", &N);
    char c;
    char letter;
    for (int i = 0; i < N; i++){
        node* temp = root;
        c = getchar();
        letter = getchar();
        do{
            c = getchar();
            insert(&temp, c, c
        while (getchar() != '\n'){
            insert(&temp, 
        }
    }
}
