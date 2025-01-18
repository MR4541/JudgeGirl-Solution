#include<stdio.h>
#include<string.h>

#define MY_CC 3 //ifdef不算在CC
#define AVERAGE_CC 3.22

typedef struct Node {
    char *val;
    struct Node *left, *right;
} Node;

int solve(Node* node, int* values){
    if(strcmp(node->val, "!") == 0){
        return !solve(node->left, values);
    }else if (strcmp(node->val, "&&") == 0){
        return solve(node->left, values) && solve(node->right, values); 
    }else if (strcmp(node->val, "||") == 0){
        return solve(node->left, values) || solve(node->right, values); 
    }else{ //alphabet
        return values[node->val[0] - 'A'];
    }
}

void evaluateTree(Node *root, int *values){
    int ret =  solve(root, values);
    #ifdef LOWER
        if(ret) printf("true\n");
        else printf("false\n");
    #endif
    #ifdef UPPER
        if(ret) printf("TRUE\n");
        else printf("FALSE\n");
    #endif
}