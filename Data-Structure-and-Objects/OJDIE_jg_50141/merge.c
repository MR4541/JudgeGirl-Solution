#include <stdio.h>
#include <stdlib.h>

#define MLE OJ判定問題，all testdata is AC

typedef struct node {
    int data;
    struct node *next;
}Node;

int findNode(Node* list[], int K, int from, int dir){ //回傳from以後dir方向第一個非null的idx
    int idx = from + dir;
    while(idx >= 0 && idx < K){
        if(list[idx] != NULL)
            return idx;
        idx += dir;
    }
    return -1; //not found
}

Node *merge(Node *list[], int K){
    int cur_idx = findNode(list, K, -1, 1); //這樣才會從0開始找
    Node* head = list[cur_idx];
    Node* cur = head;
    list[cur_idx] = list[cur_idx]->next; //pop
    
    int dir = 1; //每一round會正負反轉
    cur_idx = findNode(list, K, cur_idx, dir);
    while(1){
        while(cur_idx != -1){ //該列還沒到底
            cur->next = list[cur_idx];
            cur = cur->next;
            list[cur_idx] = list[cur_idx]->next;
            cur_idx = findNode(list, K, cur_idx, dir);
        }
        dir *= -1;
        cur_idx = findNode(list, K, (dir==1)? -1 : K, dir);//下一輪的起始node，一樣要多退一格才能搜到0, K-1
        if(cur_idx == -1) //沒有下一行了
            break;
        cur->next = list[cur_idx];
        cur = cur->next;
        list[cur_idx] = list[cur_idx]->next;
        cur_idx = findNode(list, K, cur_idx, dir);
    }

    cur->next = NULL;
    return head;
}



///////////////////////////////////////////////////////////////////////////////////////// 
// int main () {
//         int K;
//         scanf("%d", &K);
//         Node *list[K];
//         for (int i = 0; i < K; i++) {
//                 int N;
//                 scanf("%d", &N);
//                 if (N == 0) {
//                         list[i] = NULL;
//                         continue;
//                 }
//                 list[i] = (Node *)malloc(sizeof(Node));
//                 scanf("%d", &(list[i]->data));
//                 list[i]->next = NULL;
//                 Node *previous = list[i];
//                 for (int j = 1; j < N; j++) {
//                         previous->next = (Node *)malloc(sizeof(Node));
//                         scanf("%d", &(previous->next->data));
//                         previous->next->next = NULL;
//                         previous = previous->next;
//                 }
//         }
//         Node *result = merge(list, K);
//         while (result) {
//                 printf("%d", result->data);
//                 result = result->next;
//                 printf("%c", result ? ' ' : '\n');
//         };
//         return 0;
// }