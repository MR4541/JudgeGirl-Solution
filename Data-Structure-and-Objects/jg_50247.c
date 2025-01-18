#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXTOK 500002

#define AVERAGE_CC 4
#define MY_CC 4

typedef struct Node
{
    char* val;
    struct Node *left, *right;
} Node;

Node* genNode(char* val, Node* left, Node* right){
    Node* new = (Node*)malloc(sizeof(Node));
    new->left = left;
    new->right = right;
    new->val = val;
    return new;
}

//2D-arr parser
Node* build(char* parser[], int reset_i){
    //**parser = parser[0][0] = *parser[0], *parser = parser[0]
    static int i = 0;
    if(reset_i == 1) i = 0; //可能要建多個樹

    if(isalpha(*parser[i])){
        i++; // 'A'.next
        return genNode(parser[i-1], NULL, NULL);
    }else if(*parser[i] == '!'){
        i++; // '!'.next
        Node* left = build(parser, 0);
        return genNode("!", left, NULL);
    }else{ // '('
        i++; // '('.next
        Node* left = build(parser, 0);
        char* opr = parser[i]; i++; // <left> opr <right>
        Node* right = build(parser, 0);
        i++; // ')'.next
        return genNode(opr, left, right);
    }
}

Node* buildTree(char* expr){
    //parser = 當前字串
    char* parser[MAXTOK] = {strtok(expr, " ")};
    int n = 1;
    while(parser[n-1] != NULL){
        parser[n] = strtok(NULL, " ");
        n++;
    }
    n--; //parser[prev_n] = NULL
    // for(int i = 0 ; i < n; i++) printf("%s-", parser[i]); printf("\n");
    int i = 0;
    return build(parser, 1);
}

// ////////////////////////////////////////////////////////////
// void printfInOrder(Node* node, int depth){
//     if(node == NULL){
//         printf("(NULL, %d), ", depth);
//         return;
//     }
//     printfInOrder(node->left, depth+1);
//     printf("(%s, %d), ", node->val, depth);
//     printfInOrder(node->right, depth+1);
//     if(depth == 1) printf("\n");
// }

// void mainPrintPreOrder(Node* node){
//     if(node == NULL){
//         printf("NULL ");
//         return;
//     }
//     printf("%s ", node->val);
//     mainPrintPreOrder(node->left);
//     mainPrintPreOrder(node->right);
// }

// void freeTree(Node* node){
//     if(node == NULL) return;
//     freeTree(node->left);
//     freeTree(node->right);
//     free(node);
// }

// int main(void){
//     char arr[MAXTOK*2];
//     int idx = 0;
//     while (scanf("%c", &arr[idx]) != EOF){
//         if(arr[idx] == '\n'){
//             arr[idx] = '\0';
//             // printf("arr %s\n", arr);
//             Node* root = buildTree(arr);
//             mainPrintPreOrder(root);
//             printf("\n");
//             freeTree(root);
//             idx = 0;
//             continue;
//         }
//         idx++;
//     }
// }