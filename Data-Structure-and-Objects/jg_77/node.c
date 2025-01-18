#include<stdio.h>
#include<stdlib.h>
#include "node.h"

int getListLen(struct node* head){
    int len = 0;
    while (head != NULL){
        head = head->next;
        len++;
    }
    return len;
}

struct node* nextNode(struct node *node, unsigned int step){
    while(step > 0 && node!=NULL){
        // printf("Node p : %p\n", node);
        node = node->next;
        step--;
    }
    // printf("Node p : %p\n", node);
    return node;
}

struct node *getNode(struct node *head, unsigned int i){
    if(head == NULL) return NULL;
    int len = getListLen(head); //ex: len = 5, i = 2 : go next 2 = len - i - 1 times
    // printf("len %d\n", len);
    if(i >= len) return NULL; //invalid i
    return nextNode(head, len - i - 1);
}

///////////////////////////////////////////////////
// struct node *genNode(struct node *next){
//     struct node* new = (struct node*)malloc(sizeof(struct node));
//     new->next = next;
//     return new;
// }

// int main(){
//     int num;
//     struct node* head = NULL;
//     for(int i = 0; i < 5; i++){
//         head = genNode(head);
//     }
//     printf("%p\n", getNode(head, 5));
// }