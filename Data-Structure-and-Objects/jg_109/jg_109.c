#include<stdio.h>

struct node {
    struct node *left;
    struct node *right;
    int data;
};

void dfs(struct node *node, int arr[], int depth){
    arr[depth-1] = node->data;
    if(node->left == NULL && node->right == NULL){
        for(int i = 0; i < depth; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }else if(node->left == NULL){
        dfs(node->right, arr, depth+1);
    }else if(node->right == NULL){
        dfs(node->left, arr, depth+1);
    }else{
        dfs(node->left, arr, depth+1);
        dfs(node->right, arr, depth+1);
    }
}

void print_all_paths(struct node *root){
    int arr[1002], n = 1;
    dfs(root, arr, 1);
}

// ////////////////////////////////////////////////////////////////////////
// void print_all_paths(struct node *root);
 
// struct node *insert_bs_tree(struct node *root, int data)
// {
//     struct node *current;
//     if (root == NULL)
//     {
//         current = (struct node *)malloc(sizeof(struct node));
//         assert(current != NULL);
//         current->data = data;
//         current->left = NULL;
//         current->right = NULL;
//         return current;
//     }
 
//     if (data < root->data)
//         root->left = insert_bs_tree(root->left, data);
//     else
//         root->right = insert_bs_tree(root->right, data);
//     return root;
// }
 
// int main(void)
// {
//     int n;
//     struct node *root = NULL;
 
//     while (scanf("%d", &n) != EOF)
//         root = insert_bs_tree(root, n);
 
//     print_all_paths(root);
// }