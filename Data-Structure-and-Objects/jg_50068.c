#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int label;
    struct Node *left, *right;
} Node;

void traversal(Node *root, int N, int command[]){
    Node* path[5002] = {root}; int path_n = 1; //存從root到當前路徑
    Node* cur = root;
    for(int i = 0; i < N; i++){
        if(command[i] == 0){
            printf("%d\n", cur->label);
            return;
        }else if(command[i] == 1){
            printf("%d\n", cur->label);
        }else if(command[i] == 2){
            if(path_n == 1){ //invalid
                printf("%d\n", cur->label);
                return;
            }
            cur = path[path_n - 2];
            path_n--;
        }else if(command[i] == 3){
            if(cur->left == NULL){ //invalid
                printf("%d\n", cur->label);
                return;
            }
            path[path_n] = cur->left;
            cur = cur->left;
            path_n++;
        }else if(command[i] == 4){
            if(cur->right == NULL){ //invalid
                printf("%d\n", cur->label);
                return;
            }
            path[path_n] = cur->right;
            cur = cur->right;
            path_n++;
        }else{ //sibling
            if(path_n == 1 || path[path_n - 2]->left == NULL || path[path_n - 2]->right == NULL){ //invalid
                printf("%d\n", cur->label);
                return;
            }
            if(cur == path[path_n - 2]->left){
                cur = path[path_n - 2]->right;
                path[path_n - 1] = cur;
            }else{
                cur = path[path_n - 2]->left;
                path[path_n - 1] = cur;
            }
        }
    } 
}

// ////////////////////////////////////////////////////////////////////////////
// #define MAX 1000 
 
// Node* newNode(int label, Node *l, Node *r) {
//     Node *u = (Node *) malloc(sizeof(Node));
//     u->label = label, u->left = l, u->right = r;
//     return u;
// }
 
// int main() {
//     Node *root = newNode(
//             6,
//             newNode(
//                 3,
//                 newNode(1, 
//                         NULL, 
//                         newNode(2, NULL, NULL)
//                         ),
//                 newNode(5, 
//                         newNode(4, NULL, NULL), 
//                         NULL
//                         )                
//             ),
//             newNode(
//                 7,
//                 NULL,
//                 NULL                
//             )
//     );
 
//     int N, command[MAX];
//     scanf("%d", &N);
//     for(int i = 0; i < N; i++) {
//         scanf("%d", &command[i]);        
//     }
//     traversal(root, N, command);
//     return 0;
// }