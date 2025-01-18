#include<stdio.h>
#include<stdlib.h>
 
#define MY_CC 4
#define AVERAGE_CC 3.44

struct Node{
    int data;
    struct Node *left,*right;
    struct Node *next_clockwise,*pre_clockwise;
};
 
void find_path(struct Node *root){
    if(root == NULL) return;
    struct Node *L = root->left; find_path(root->left); // L_1
    struct Node *R = root->right; find_path(root->right); // R_1
    if(L != NULL && R != NULL){
        //root to Rn
        struct Node* Rn = R->pre_clockwise;
        struct Node* Rn_1 = Rn->pre_clockwise;
        root->next_clockwise = Rn;
        Rn->pre_clockwise = root;
        //Rn_1 to L2
        struct Node* L2 = L->next_clockwise;
        Rn_1->next_clockwise = L2;
        L2->pre_clockwise = Rn_1;
        //L1 to root
        L->next_clockwise = root;
        root->pre_clockwise = L;
    }else if(L != NULL){
        //L to root
        struct Node* L2 = L->next_clockwise;
        L->next_clockwise = root;
        root->pre_clockwise = L;
        //root to L2
        L2->pre_clockwise = root;
        root->next_clockwise = L2; 
    }else if(R != NULL){
        //root to Rn
        struct Node* Rn = R->pre_clockwise;
        struct Node* Rn_1 = Rn->pre_clockwise;
        root->next_clockwise = Rn;
        Rn->pre_clockwise = root;
        //Rn-1 to root
        root->pre_clockwise = Rn_1;
        Rn_1->next_clockwise = root;
    }else{
        root->next_clockwise = root;
        root->pre_clockwise = root;
    }
}