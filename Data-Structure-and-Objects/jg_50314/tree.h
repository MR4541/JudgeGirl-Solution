#include <stdio.h>
struct node {
    struct node *left;
    struct node *right;
    char data;
};
void build_tree(char **code, char* str, struct node* root, int n);
char ask(char* code,struct node* root);