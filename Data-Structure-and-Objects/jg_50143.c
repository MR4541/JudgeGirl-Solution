#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
 
Node *genNode(int val, Node* left, Node* right){
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->left = left;
    new->right = right;
    return new;
}

Node *treeAND(Node *root1, Node *root2){
    if(root1 == NULL || root2 == NULL) return NULL;
    return genNode(root1->val * root2->val, treeAND(root1->left, root2->left), treeAND(root1->right, root2->right));
}

Node *treeOR(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL) return NULL;
    else if(root1 == NULL) return root2;
    else if(root2 == NULL) return root1;
    else return genNode(root1->val + root2->val, treeOR(root1->left, root2->left), treeOR(root1->right, root2->right));
}