#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* charSubStr(char* str){ //This should return the string without the first char.
    int length = strlen(str);
    char* tmp = malloc(length - 1);
    for (int i = 0; i < length - 1; i++){
        tmp[i] = str[i + 1];
    }
    tmp[length - 1] = '\0';
    return tmp;
}

char* combSubStr(char letter, char* str){ // This should return the string letter+str
    int length = strlen(str);
    char* tmp = malloc(length + 1);
    tmp[0] = letter;
    for (int i = 0; i < length; i++){
        tmp[i + 1] = str[i];
    }
    return tmp;
}

struct bin_tree{ // struct for a binary tree
    int leaf; // '0' if not a leaf, '1' if a leaf
    char data; // holds the letter (only applies to leaf)
    struct bin_tree * right, * left; // points at children nodes
};
typedef struct bin_tree node; // rename bin_tree for accessibility

void insert(node ** tree, char binCode[], char letter){  
   /* node ** tree is a pointer to the pointer of node
     * binCode[] is the associated binary code
     * letter is the associated character/letter */ 
    node *temp = NULL; // temp node pointer
    int length = strlen(binCode);
    if (length > 0){
        char firstChar = binCode[0]; // Looks to find direction in relation to parent '0'->left, '1'->right
        char* nextBinCode = charSubStr(binCode); // binCode to be passed
        if (!(*tree)){ // if it is not an empty tree
            temp = (node *)malloc(sizeof(node)); // allocates memory for node temp
            temp->left = temp->right = NULL; // children are NULL
            temp->leaf = 0;
            if (length == 0){ // this is then a leaf
                temp->data = letter; // initialize it to its letter
                temp->leaf = 1; // state that its a leaf
            }
            *tree = temp;
        }
        if ((length != 0) && (firstChar == '0')){ // it is not a leaf, we go left
            insert(&(*tree)->left, nextBinCode, letter); // insert left child w/ remaining binCode           
        } else if ((length != 0) && (firstChar == '1')){ // it is not a leaf, we go right
            insert(&(*tree)->right, nextBinCode, letter); // insert right child w/ remaining binCode
        }
        return;
    } else{
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = letter;
        temp->leaf = 1;
        *tree = temp;
    }
}

void deltree(node * tree){ // free up memory and delete the tree
    if (tree){ // free up memory
        deltree(tree->left); // recurse on left
        deltree(tree->right); // recurse on right
        free(tree); // free up current node
    }
}

void traverse(node ** tree, node ** root, char encMsg[]){ // go through the tree with the encMsg and print the msg.
    int length = strlen(encMsg);
    if (length > 0){
        char firstChar = encMsg[0];
        char* nextEncMsg = charSubStr(encMsg);
        if ((*tree)->leaf == 1){ // if the node is a leaf, print its value then continue with remaining code
            printf("%c", (*tree)->data); // prints its character/letter
            char* prevEncMsg = combSubStr(firstChar, nextEncMsg);
            traverse(&(*root), &(*root), prevEncMsg); // traverse starting from the root with the encMsg
        } else if (firstChar == '0'){ // if the node is not a leaf and the first char is 0, go to left child
            traverse(&(*tree)->left, &(*root), nextEncMsg); // traverse to left child with remaining EncMsg
        } else if (firstChar == '1'){ // if the node is not a leaf and the first char is 1, go to right child
            traverse(&(*tree)->right, &(*root), nextEncMsg); // traverse to right child with remaining EncMsg
        }
    } else {
        printf("%c", (*tree)->data);
    }
}

int main(){
    node *root; // instatiate the root node of the tree;
    root = NULL; // it is the root so it has no parent (NULL parent)
    int N; // obtain the number of char:binCode
    scanf("%d", &N);
    char charCode[256]; // create space for the char:binCode lines
    char c; // get rid of the garbage at the end of lines and stuff...
    for (int i = 0; i < N; i++){ // Obtain the char:binCode lines N times
        c = getchar(); // get the '\n' of the previous line
        c = getchar(); // get the actual character of the char:binCode line
        scanf("%s", charCode); // get the binCode of the line
        insert(&root, charCode, c); // insert the leaf into the tree
    }
    char msg[256]; // create space for the encoded message
    scanf("%s", msg); // get the encoded message
    traverse(&root, &root, msg); // traverse the tree with the encoded message
    deltree(root); // free up space used
}
