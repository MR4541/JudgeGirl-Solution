#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;

int compareFunc(const void *a, const void *b){
    return ((int*)a)[1] > ((int*)b)[1];
}

Node* genNode(int data, Node* right, Node* left){
    Node* new = (Node*)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->right = right;
    new->left =left;
    return new;
}

Node* insertTree(int data, Node* node, int depth){
    if(depth == 1) //insert here
        return genNode(data, NULL, NULL);
    if(data < node->data){ //insert at left
        node->left = insertTree(data, node->left, depth-1);
    }else{
        node->right = insertTree(data, node->right, depth-1);
    }
    return node;
}

void printInOrder(Node* node){
    if(node == NULL) return;
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

int distance(Node* root, int a, int b){
    if(a > b){
        int t = a; a = b; b = t; 
    }
    //如果root->data在a,b之間表示他們在左右子樹，才能算兩者到當前root距離相加
    while(1){
        if(root->data < a){ //a,b在右子樹
            root = root->right;
            continue;
        }
        if(root->data > b){ //a,b在左子樹
            root = root->left;
            continue;
        }
        break;
    }
    Node* tmp = root;
    int ret = 0;
    while(tmp->data != a){
        if(tmp->data < a) tmp = tmp->right;
        else tmp = tmp->left;
        ret++;
    }
    tmp = root;
    while(tmp->data != b){
        if(tmp->data < b) tmp = tmp->right;
        else tmp = tmp->left;
        ret++;
    }
    return ret;
}

int main(void){
    int n;
    scanf("%d", &n);
    int input[1002][2];
    for(int i = 0; i < n; i++) scanf("%d%d", &input[i][0], &input[i][1]);
    qsort(input, n, 2*sizeof(int), compareFunc);
    // for(int i = 0; i < n; i++) printf("%d %d\n", input[i][0], input[i][1]);
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        root = insertTree(input[i][0], root, input[i][1]);
    }
    // printInOrder(root);
    int m, a, b;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        printf("%d\n", distance(root, a, b));
    }
}