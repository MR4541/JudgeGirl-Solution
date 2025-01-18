#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
 
struct Node
{
    int val;
    struct Node *nxt;
};
 
int split_cycle(struct Node *head, int A, int K){
    // printf("recur\n");
    int len = 1;
    struct Node* tmp = head;
    tmp = tmp->nxt;
    while(tmp != head){
        len++;
        tmp = tmp->nxt;
    }
    if(len <= K){
        tmp = head;
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += tmp->val;
            tmp = tmp->nxt;
        }
        return sum * A;
    }else{
        tmp = head; //a1
        for(int i = 0; i < (len+1)/2 - 1; i++){ //找到a[n+1/2]
            tmp = tmp->nxt;
        }
        struct Node* end = head;
        for(int i = 0; i < len-1; i++){
            end = end->nxt; //a_n
        }
        end->nxt = tmp->nxt;
        tmp->nxt = head;
        return split_cycle(head, A+1, K) + split_cycle(end, A+2, K);
    }
 
}
 
///////////////////////////////////////////////////////
// int main()
// {
//     int n, A, K;
//     scanf("%d %d %d\n", &n, &A, &K);
//     struct Node *a[n];
//     for (int i = 0; i < n; i++)
//     {
//         a[i] = (struct Node *)malloc(sizeof(struct Node));
//         scanf("%d", &a[i]->val);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         a[i]->nxt = a[(i + 1) % n];
//     }
//     int ans = split_cycle(a[0], A, K);
//     printf("%d\n", ans);
//     return 0;
// }