#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void obtSubStr(char str[], int st, int end){
    for (int i = 0; i < end - st + 1; i++){
        str[i] = str[i + st];
    }
    str[end - st + 1] = '\0';
}

char* charSubStr(char* str){
    char* tmp = malloc(strlen(str) - 1);
    for (int i = 0; i < strlen(str)-1; i++) {
        tmp[i] = str[i+1];
    }
    tmp[strlen(str)-1]='\0';
    return tmp;
}

struct bin_tree{ // creates the struct bin_tree
    char num; // holds whether its '0' or '1' relative to its parent
    int leaf; // holds whether its a leaf ('1') or not ('0')
    char data; // holds its respective letter (Should only exist for leaves)
    struct bin_tree * right, * left; // Each node points at its children nodes
};
typedef struct bin_tree node; // rename bin_tree for accessibility

void insert(node ** tree, char binCode[], char letter, char which){
    node *temp = NULL; // create a temp pointer to a node that has value NULL
    char firstChar = binCode[0];
    int length;
    printf("The original length is: %d\n", length);
    //printf("The firstChar is: %c\n", firstChar);
    //char* newBinCode = charSubStr(binCode);
    obtSubStr(binCode, 1, strlen(binCode) - 1);
    length = strlen(binCode);
    
printf("\n\nstart  insert b%s l%d\n", binCode, length);
    //printf("The remaining is: %s\n", binCode);
    if (!(*tree)){ // check first if tree is empty, then insert node as root.
        //printf("The tree is not empty!\n");
        printf("The length is: %d\n", length);
        temp = (node *)malloc(sizeof(node)); // allocates memory for node temp.
        temp->left = temp->right = NULL; // initiates left and right children as NULL
        temp->leaf = 0;
        if (which != 'a'){
            temp->num = which;
        }
        *tree = temp;
        
        if (firstChar == '0'){ // if the first char of binCode is '0'
            printf("Going left!\n");
            printf("firstChar: %c\n", firstChar);
            if (length != 0){
            printf("binCode: %s\n", binCode);
            printf("letter: %c\n", letter);
            printf("firstChar: %c\n", firstChar);
            printf("INSERTING TO THE LEFT NODE");
            insert(&(*tree)->left, binCode, letter, firstChar);
            }
        } else if (firstChar == '1'){ // if the first char of binCode is '1'
            printf("Going right!\n");
            printf("%c\n", firstChar);
            if (length != 0){
            printf("INSERTING TO THE RIGHT NODE");    
            insert(&(*tree)->right, binCode, letter, firstChar);
            }
        }
        if (length == 0){ // if there are no remaining characters then this is a leaf.
            printf("binCode is empty!\n");
            temp->data = letter;
            printf("%c\n", firstChar);
            printf("The letter is: %c\n", letter);
            temp->leaf = 1;
            firstChar = 'b';
        }
        //*tree = temp;
        printf("The firstChar is: %c\n", firstChar);
        printf("The remaining is: %s\n", binCode);
    }
    /*
    if (firstChar == '0'){ // if the first char of binCode is '0'
        printf("Going left!\n");
        printf("%c", firstChar);
        insert(&(*tree)->left, binCode, letter, firstChar);
    } else if (firstChar == '1'){ // if the first char of binCode is '1'
        printf("Going right!\n");
        printf("%c", firstChar);
        insert(&(*tree)->right, binCode, letter, firstChar);
    } */
    
} 

void deltree(node * tree){
    if (tree){
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

void search(node ** tree, node ** root, char encMsg[]){
    int length = strlen(encMsg);
    if (!(*tree)){
    } else if ((*tree)->leaf){ // if the node is a leaf then print its value
        printf("printing a leaf!: %c\n", (*tree)->data);
        printf("aThe remaining encoded message is: %s\n", encMsg);
        search(&(*root), &(*root), encMsg);
    } else {for (int i = 0; i < length; i++){
        if(encMsg[0] == '0'){
            printf("going left!\n");
            obtSubStr(encMsg, 1, length - 1);
            printf("bThe remaining encoded Message is: %s\n", encMsg);
            search(&((*tree)->left), &(*root), encMsg);
        } else if(encMsg[0] == '1'){
            printf("going right!\n");
            obtSubStr(encMsg, 1, length - 1);
            printf("cThe remaining encoded Message is: %s\n", encMsg);
            search(&((*tree)->right), &(*root), encMsg);
        }
    }
    }
}

int main(){
    node *root;
    root = NULL;
    int N;
    char name[256];
    printf("Please input N: ");
    scanf("%d", &N);
    printf("N has the value: %d\n", N);
    char c;
    for (int i = 0; i < N; i++){
        c = getchar();
        printf("Please input the letter:binCode: ");
        c = getchar();
        scanf("%s", name);
        printf("The character you have entered is: %c\n", c);
        printf("You have entered: %s\n", name);
        insert(&root, name, c, ' ');
    }
    char msg[256];
    printf("Please enter the encoded message: ");
    scanf("%s", msg);
    search(&root, &root,  msg); 
    deltree(root);
}
