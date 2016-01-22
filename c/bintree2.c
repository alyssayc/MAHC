#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct bin_tree {
    char letter; 
    struct bin_tree * right, * left;
} node;

void insert(node ** tree, char val) 
{
    node *temp = NULL;
    char tmp;
    printf("Hello there! I'm inserting!\n");
    if(!(*tree)) {
        //printf("appending \n");
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->letter= val;
        printf("My value is: %c\n", val);
        *tree = temp;
        //return;
    }
        
    tmp = getchar();
    //printf("printing tmp: %c \n", tmp);

    if (tmp == '\n') {
        printf("What the!");
        return;
    }

    if (tmp == '0') {
        (*tree)->letter= '0';
        printf("going left! \n");
        printf("i am 0 \n");
        insert(&(*tree)->left, val); 
    }
    else if (tmp == '1') {
        printf("going right! \n");
        (*tree)->letter= '0';
        printf("i am 1 \n"); 
        insert(&(*tree)->right, val);        
    } 
    
    //return;
}

void deltree(node * tree) {
    if (tree) {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

void print_inorder(node * tree)
{
    if (tree) {
        print_inorder(tree->left);
        printf("%c\n",tree->letter);
        print_inorder(tree->right);
     }
}

int main() {
    node *root;
    node *tmp;
    //int i;
    root = NULL;
    
    int N, i;
    char letter;
    scanf("%d", &N);
    getchar();
    /* Inserting nodes into tree */
    for (i = 0; i < N; i++) {
        printf("i: %d\n", i);
       // printf("Please input your char:binCode! \n");
        letter = getchar();
        printf("The letter is: %c\n", letter);
        //putchar(letter);
       // printf("before the insert \n");
       printf("Let's insert!\n");
        insert(&root, letter);
        printf("done inserting!\n");
       // printf("after the insert \n");
    }

    //input code
    char bincode[100002];
    printf("Please give me your Encoded Message! :D\n");
    //while( getchar() != '\n' );
    scanf("%s", bincode);
    getchar();
    //while( getchar() != '\n' );
    printf("bincode is: %s\n", bincode);
    printf("length: %d\n", (int)strlen(bincode));
    node *current = root;
    for (i = 0; i <= strlen(bincode) ; i++){
        printf("i: %d\n", i);
        printf("letter: %c\n", current->letter);
        if (current->letter != '0'){
            printf("printing letter! \n");
            printf("%c", current->letter);
            printf("returning to root! \n");
            current = root;
        }
        if (bincode[i] == '0'){
            printf("going left!\n");
            current = current->left;
        }
        if (bincode[i] == '1'){
            printf("going right!\n");
            current = current->right;
        }
    }
    
    deltree(root);
}

