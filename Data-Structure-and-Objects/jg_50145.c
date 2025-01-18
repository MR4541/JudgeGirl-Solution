#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node
{
    char c;
    struct Node *next;
}Node;

//檢查是否為pattern起點
int isSame(Node* node, Node* pattern){
    while(pattern != NULL){
        if(node == NULL || node->c != pattern->c) return 0;
        pattern = pattern->next;
        node = node->next;
    }
    return 1;
}

int len(Node* head){
    int ret = 0;
    while (head != NULL){
        ret++;
        head = head->next;
    }
    return ret;
}

void substring(Node* text, Node* pattern){
    int idx = 0; //start idx
    while(text != NULL){
        if(isSame(text, pattern)){
            int len_p = len(pattern);
            printf("%d\n", (2*idx + len_p - 1)*len_p/2);
            return;
        }
        idx++;
        text = text->next;
    }
}

void subsequence(Node* text, Node* pattern){
    int ret = 0, idx = 0;
    while(text != NULL){
        if(text->c == pattern->c){
            ret += idx;
            pattern = pattern->next;
        }
        if(pattern == NULL){
            printf("%d\n", ret);
            return;
        }
        idx++;
        text = text->next;
    }
}


// //////////////////////////////////////////////////////////////// 
// Node* insert(Node* root, char c)
// {
//     if(root == NULL){
//         root = (Node*)malloc(sizeof(Node));
//         root->c = c;
//         root->next = NULL;
//         return root;
//     }
//     root->next = insert(root->next, c);
//     return root;
// }
// int main(int argc, char const *argv[])
// {
//     char tmp = '\n';
//     int N, M, i, act;
//     Node *text = NULL, *pattern = NULL, *cur = NULL;
 
//     scanf("%d%d", &act, &N);
//     while(isspace(tmp)) scanf("%c", &tmp);
//     text = insert(text, tmp);
//     cur = text;
//     for(i = 0; i < N-1; i++){
//         scanf("%c", &tmp);
//         cur->next = insert(cur->next, tmp);
//         cur = cur->next;
//     }
 
//     scanf("%d", &M);
//     tmp = '\n';
//     while(isspace(tmp)) scanf("%c", &tmp);
//     pattern = insert(pattern, tmp);
//     cur = pattern;
//     for(i = 0; i < M-1; i++){
//         scanf("%c", &tmp);
//         cur->next = insert(cur->next, tmp);
//         cur = cur->next;
//     }
//     if (!act)
//         substring(text, pattern);
//     else
//         subsequence(text, pattern);
//     return 0;
// }