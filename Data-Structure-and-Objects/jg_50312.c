#include<stdio.h>
#include <stdlib.h>
#include <time.h>  
struct node{
    struct node *next_node;
};
 
// void printList(struct node* head, struct node* newHead){
//     printf("\nList: ");
//     while (head != NULL){
//         printf("%p ", head);
//         head = head->next_node;
//     }
//     printf("\nNewList: ");
//     while (newHead != NULL){
//         printf("%p ", newHead);
//         newHead = newHead->next_node;
//     }
//     printf("\n");
// }

// head -> .. -> prev -> smallest -> next
// new_head -> ... -> tmp

// head -> .. -> prev -> next
// new_head -> ... -> tmp -> smallest
struct node *sort_list(struct node *head){
    struct node *head_prev = (struct node*)malloc(sizeof(struct node));
    head_prev->next_node = head; //head前一個
    struct node *new_head_prev =  (struct node*)malloc(sizeof(struct node));
    new_head_prev->next_node = NULL; //new head前一個node
    struct node *tmp_new = new_head_prev;

    struct node *min_prev;
    struct node *min; //找出記憶體位置最小的node
    struct node *tmp_prev;
    struct node *tmp;
    while(head_prev->next_node != NULL){
        // printList(head_prev->next_node, new_head_prev->next_node);/////////////////////////////////////
        min_prev = head_prev; min = head_prev->next_node;
        tmp_prev = head_prev; tmp = head_prev->next_node;
        while(tmp != NULL){
            if(tmp < min){
                min = tmp;
                min_prev = tmp_prev;
                // printf("update min %p -> %p | min_prev %p -> %p\n", min, min->next_node, min_prev, min_prev->next_node);
            }
            tmp_prev = tmp;
            tmp = tmp->next_node;
        }
        //remove min from list
        // printf("min->next %p\n", min->next_node);//////////////////////////////////////////////////////
        min_prev->next_node = min->next_node;
        //insert min to newlist
        tmp_new->next_node = min;
        tmp_new = tmp_new->next_node;
        tmp_new->next_node = NULL;
    }
    // printf("empty %d\n", new_head_prev->next_node == NULL);
    return new_head_prev->next_node;
}