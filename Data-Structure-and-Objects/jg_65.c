#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

typedef struct node{
    int value;
    char opr;
    struct node *left, *right;
}Node;

typedef struct var{
    char name[36];
    int value;
}Var;

int VarValue(int var_n, Var* table, char name[]){
    while(var_n > 0){
        if(strcmp(table->name, name) == 0)
            return table->value;
        var_n--;
        table++;
    }
    printf("Not Found\n");
    return -1;
}

Node* parser(char** input, int var_n, Var* table){
    if(**input == '('){ //sub-tree
        (*input) += 2; //"( "
        Node* node = (Node*)malloc(sizeof(Node));
        node->opr = **input;
        (*input) += 2; //"<opr> "
        node->left = parser(input, var_n, table); //"<left_tree>"
        (*input) += 1; //" "
        node->right = parser(input, var_n, table); //"<right_tree>"
        (*input) += 2; //" )"
        if(node->opr == '+') node->value = node->left->value + node->right->value;
        else if(node->opr == '-') node->value = node->left->value - node->right->value;
        else if(node->opr == '*') node->value = node->left->value * node->right->value;
        else if(node->opr == '/') node->value = node->left->value / node->right->value;
        return node;
    }else{ //var or int
        if(isdigit(**input)){ //int
            int num = 0;
            while(isdigit(**input)){
                num = num*10 + (**input - '0');
                (*input)++;
            }
            Node* node = (Node*)malloc(sizeof(Node));
            node->value = num; node->opr = '\0';
            node->left = node->right = NULL;
            return node; 
        }else{ //var
            char name[36]; int len = 0;
            while(**input != ' '){
                name[len] = **input;
                len++;
                (*input)++;
            }
            name[len] = '\0';
            Node* node = (Node*)malloc(sizeof(Node));
            node->value = VarValue(var_n, table, name); node->opr = '\0';
            node->left = node->right = NULL;
            return node; 
        }
    }
}

int main(){
    char input[1004]; int n = 0;
    do{
        scanf("%c", &input[n]);
        n++;
    } while(input[n-1] != '\n');
    input[n-1] = '\0';
    // printf("%s\n", input);
    Var table[50];
    int var_n = 0;
    while(scanf("%s = %d", table[var_n].name, &table[var_n].value) != EOF) var_n++;

    // for(int i = 0; i < var_n; i++){
    //     printf("re: %s = %d\n", table[i].name, table[i].value);
    // }
    char* cptr = input;
    Node* root = parser(&cptr, var_n, table);
    printf("%d\n", root->value);
}