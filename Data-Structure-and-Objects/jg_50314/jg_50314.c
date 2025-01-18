#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    char data;
};

struct node* genNode(char data){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

// void printInOrder(struct node* root){
//     if(root == NULL) return;
//     printInOrder(root->left);
//     printf("val = %c\n", root->data);
//     printInOrder(root->right);
// }

//code[n][n]
void build_tree(char **code, char* str, struct node* root, int n){
    root->data = '?'; root->left = root->right = NULL; 
    for(int i = 0; i < n; i++){
        struct node* now = root;
        for(int j = 0; j < n; j++){
            if(code[i][j] == '.'){ //left
                if(now->left == NULL){
                    now->left = genNode('?');
                }
                now = now->left;
            }else{ //right
                if(now->right == NULL){
                    now->right = genNode('?');
                }
                now = now->right;
            }
        }
        now->data = str[i];
    }
    // printInOrder(root);
}

char ask(char* code, struct node* root){
    while(*code != '\0'){
        if(*code == '.'){ //left
            if(root->left == NULL)
                return 'E';
            root = root->left;
        }else{ //right
            if(root->right == NULL)
                return 'E';
            root = root->right;
        }
        code++;
    }
    return root->data;
}