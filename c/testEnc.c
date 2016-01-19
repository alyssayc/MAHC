#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void charSubStr(char* str){ // This should modify str
    printf("length of subStr: %d\n", (int)strlen(str));
    int length = strlen(str);
    for (int i = 0; i < length; i++){
        str[i] = str[i + 1];
    }
    str[length - 1] = '\0';
}

struct bin_tree{ // struct for a binary tree
    int leaf; // '0' if not a leaf, '1' if a leaf
    char data; // holds the letter (only applies to leaf)
    struct bin_tree * right, * left; // points at children nodes
};
typedef struct bin_tree node; // rename bin_tree for accessibility

void insert(node ** tree, char binCode[], char letter){
    node *temp = NULL;
    int length = strlen(binCode);
    char firstChar = binCode[0];
    charSubStr(binCode);
    printf("binCode is now: %s\n", binCode);
    printf("length: %d\n", length);
    if (length == 1){
        if (0 == 0){
            printf("debug alpha");
            temp = (node *)malloc(sizeof(node));
            temp->left = temp->right = NULL;
            temp->data = letter;
            temp->leaf = 1;
            printf("firstChar: %c\n", firstChar);
            if (firstChar == '0'){
                printf("debug bravo");
                *(&((*tree)->left)) = temp;
            } else if (firstChar == '1'){
                printf("debug charlie");
            }
        } else {
        printf("debug a");
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = letter;
        temp->leaf = 1;
        if (firstChar == '0'){
            (*tree)->left = temp;
        } else if (firstChar == '1'){
            (*tree)->right = temp;
        }

        return;
        }

    } else if (firstChar == '0'){
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->leaf = 0;
        *tree = temp;
        printf("debug b");
        insert(&(*tree)->left, binCode, letter);
    } else if (firstChar == '1'){
        printf("debug c");
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->leaf = 0;
        *tree = temp;
        insert(&(*tree)->right, binCode, letter);
    }
    return;
}

void deltree(node * tree){
    if (tree){
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

void traverse(node ** tree, node ** root, char encMsg[]){
    int length = strlen(encMsg);
    if ((*tree)->leaf == 1){
        printf("%c", (*tree)->data);
        traverse(root, root, encMsg);
    } else {
        char firstChar = encMsg[0];
        charSubStr(encMsg);
        if (firstChar == '0'){
            traverse(&(*tree)->left, root, encMsg);
        } else if (firstChar == '1'){
            traverse(&(*tree)->right, root, encMsg);
        }
    }
}

int main(){
    node *root;
    root = NULL;
    int N;
    scanf("%d", &N);
    char charCode[100000];
    char c;
    for (int i = 0; i < N; i++){
        c = getchar();
        c = getchar();
        scanf("%s", charCode);
        insert(&root, charCode, c);
    }
    char msg[100000];
    scanf("%s", msg);
    traverse(&root, &root, msg);
    deltree(root);
}


