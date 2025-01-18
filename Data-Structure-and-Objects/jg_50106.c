#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MY_CC 2

typedef struct Node{
    char name[16];
    int height;
    int weight;
    struct Node *left, *right;
} Node;
 
Node *genNode(char name[16], int height, int weight){
    Node *new = (Node*)malloc(sizeof(Node));
    strcpy(new->name, name);
    new->height = height;
    new->weight = weight;
    new->left = new->right = NULL;
    return new;
}

Node *insert(Node* root, char name[16], int height, int weight){
    if(root == NULL) return genNode(name, height, weight);
#ifdef HEIGHT //even.in
    if(height < root->height){
        root->left = insert(root->left, name, height, weight);
    }else{
        root->right = insert(root->right, name, height, weight);
    }
#endif
#ifdef WEIGHT //odd.in
    if(weight < root->weight){
        root->left = insert(root->left, name, height, weight);
    }else{
        root->right = insert(root->right, name, height, weight);
    }
#endif
    return root;
}

Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]){
    Node* root = NULL; 
    for(int i = 0; i < N; i++){
        root = insert(root, name[i], height[i], weight[i]);
    }
    return root;
}

//////////////////////////////////////////////////////////////////////////////
// #define MAXN 1024
// char name[MAXN][16];
// int height[MAXN];
// int weight[MAXN];
 
// void PrintBSTree( Node *root ){
//     if (root == NULL)
//         return;
//     printf("%s\n", root->name);
//     PrintBSTree(root->left);
//     PrintBSTree(root->right);
//     return;
// }
 
// int main(){
//     int N;
//     scanf("%d", &N);
//     for (int i=0; i<N; i++)
//         scanf("%s %d %d", name[i], &height[i], &weight[i]);
 
//     Node *tree = ConstructBSTree( N, name, height, weight );
 
//     PrintBSTree( tree );
//     return 0;
// }