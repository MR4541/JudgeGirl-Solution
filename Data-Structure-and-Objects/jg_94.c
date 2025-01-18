#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;

Node* readTree(char** input){
    //如果現在讀到的是另一個子樹
    if(**input == '('){
        (*input)++;
        Node* root = (Node*)malloc(sizeof(Node));
        //處理左邊
        root->left = readTree(input);
        
        while(**input == ',') (*input)++;
        //處理右邊
        root->right = readTree(input);

        if(**input == ')') (*input)++;
        //總結
        root->data = root->left->data + root->right->data;
        return root;
    }else{ //如果讀到的是數字
        int num = 0;
        while(isdigit(**input)){
            num = num*10 + (**input - '0');
            (*input)++;
        }
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = num;
        node->left = node->right = NULL;
        return node;
    }   
}

void printPreOrder(Node* node){
    if(node == NULL) return;
    printf("%d\n", node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
    return;
}

void printTree(Node* node, int HLHRflag){
    if(node == NULL) return;
    if(HLHRflag){
        printf("%d\n", node->data);
        printTree(node->left, 0);
        printf("%d\n", node->data);
        printTree(node->right, 0);        
    }else{
        printf("%d\n", node->data);
        printTree(node->right, 1);
        printf("%d\n", node->data);
        printTree(node->left, 1);
    }
}

void freeTree(Node* node){
    if(node==NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main(void){
    char input[5000];
    scanf("%s", input);
    char* cptr = input;
    Node* root = readTree(&cptr);
    // printPreOrder(root);
    printTree(root, 1);
    freeTree(root);
}