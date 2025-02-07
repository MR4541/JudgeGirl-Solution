#include <stdio.h>
#include <stdlib.h>
#include "node.h"
 
struct node * merge(struct node *list1, struct node *list2){
    struct node* list3_head;
    if(list1->value < list2->value){
        list3_head = list1;
        list1 = list1->next;
    }else{
        list3_head = list2;
        list2 = list2->next;
    }
    struct node* now = list3_head;
    int flag = 0;
    while(list1 != NULL || list2 != NULL){
        // printf("now value %d\n", now->value);////////////////////////////
        if(list1 == NULL){ //add list 2
            now->next = list2;
            now = now->next;
            list2 = list2->next;
        }else if(list2 == NULL){ //add list 1
            now->next = list1;
            now = now->next;
            list1 = list1->next;
        }else if(list1->value < list2->value){ //add list 1
            now->next = list1;
            now = now->next;
            list1 = list1->next;
        }else{
            now->next = list2;
            now = now->next;
            list2 = list2->next;
        }
        if(flag == 0){ //set head->next
            list3_head->next = now;
            flag = 1;
        }
    }
    now->next = NULL;
    return list3_head;
}
//////////////////////////////////////////////////////////////////////  
 
// #define LEN 1000
 
// struct node * build(int v[], int n) {
//     struct node * head, * ptr;
//     int i;
 
//     if (!n)
//         return 0;
 
//     head = (struct node *) malloc(sizeof(struct node));
//     ptr = head;
//     head -> value = v[0];
//     for (i = 1; i < n; i++) {
//         ptr -> next = (struct node *) malloc(sizeof(struct node));
//         ptr = ptr -> next;
//         ptr -> value = v[i];
//     }
//     ptr -> next = 0;
//     return head;
// }
 
// void print(struct node * ptr) {
//     printf("%d", ptr -> value);
//     if (ptr -> next) {
//         putchar(' ');
//         print(ptr -> next);
//     }
// }
 
// int main() {
//     int n1, n2;
//     int v1[LEN], v2[LEN];
//     int i;
//     struct node * list1, * list2;
 
//     scanf("%d", &n1);
//     for (i = 0; i < n1; i++)
//         scanf("%d", &v1[i]);
//     scanf("%d", &n2);
//     for (i = 0; i < n2; i++)
//         scanf("%d", &v2[i]);
//     list1 = build(v1, n1);
//     list2 = build(v2, n2);
 
//     print(merge(list1, list2));
//     putchar('\n');
//     return 0;
// }