#include<stdio.h>
#include<stdlib.h>

#define MAXN 128
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *genNode(){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = 1;
    new->left = new->right = NULL;
    return new;
}

Node *construct(Node *root, char instruction[MAXN]){
    if(root == NULL) root = genNode();
    else root->data++;

    Node* now = root;
    for(int idx = 0; instruction[idx] != '\0'; idx++){
        if(instruction[idx] == 'L'){
            if(now->left == NULL) now->left = genNode();
            else now->left->data++;
            now = now->left;
        }else{
            if(now->right == NULL) now->right = genNode();
            else now->right->data++;
            now = now->right;
        }
    }
    return root;
}

int query(Node *root, char instruction[MAXN]){
    for(int idx = 0; instruction[idx] != '\n'; idx++){
        if(instruction[idx] == 'L'){
            if(root->left == NULL) return 0;
            else root = root->left;
        }else{
            if(root->right == NULL) return 0;
            else root = root->right;
        }
    }
    return root->data;
}