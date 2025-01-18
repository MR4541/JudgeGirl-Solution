#include <stdio.h>
#include <stdlib.h>  
#include <assert.h>

#define MY_CC 8
#define AVERAGE_CC 6.67

typedef struct listnode {
    int data;
    struct listnode *next;
    struct listnode *prev;
} ListNode;
 
typedef struct linkedlist{
    struct listnode *head;
    struct listnode *tail;
} LinkedList;
 
ListNode* genNode(int data, ListNode* next, ListNode* prev){
    ListNode* new = (ListNode*)malloc(sizeof(ListNode));
    assert(new != NULL);
    new->data = data;
    new->next = next;
    new->prev = prev;
    return new;
}

void insert(LinkedList *list, int data){
    //len == 0
    if(list->head == NULL){
        ListNode* new = genNode(data, NULL, NULL);
        list->head = new;
        list->tail = new; 
        return;
    }else{
        //next->prev < new < next
        ListNode* next = list->head;
        while(next != NULL && data > next->data){
            next = next->next;
        }
        if(next == list->head){ //變成新的head
            ListNode* new = genNode(data, next, NULL);
            next->prev = new;
            list->head = new;
        }else if(next == NULL){ //變成新的tail, 此時next變成null已無法使用
            ListNode* new = genNode(data, NULL, list->tail);
            list->tail->next = new;
            list->tail = new;
        }else{ //插在中間
            ListNode* new = genNode(data, next, next->prev);
            next->prev->next = new;
            next->prev = new;
        }
    }
}

void delete_head(LinkedList *list){
    //len > 0
    if(list->head != NULL){
        if(list->head->next == NULL){ //len = 1
            free(list->head);
            list->head = NULL; //free不會幫你改動已釋放的指針
            list->tail = NULL;
        }else{ //len > 1
            ListNode *next = list->head->next;
            free(list->head);
            list->head = NULL;
            next->prev = NULL;
            list->head = next;
        }
    }
}

void delete_tail(LinkedList *list){
    //len > 0
    if(list->tail != NULL){
        if(list->tail->prev == NULL){ //len = 1
            free(list->tail);
            list->tail = NULL;
            list->head = NULL;
        }else{ //len > 1
            ListNode *prev = list->tail->prev;
            free(list->tail);
            list->tail = NULL;
            prev->next = NULL;
            list->tail = prev;
        }
    }
}


////////////////////////////////////////////////////////////////////////////////
// #define INSERT 0
// #define DELETE_HEAD 1
// #define DELETE_TAIL 2
// void head_traverse(LinkedList *list){
//     ListNode *node = list -> head;
//     for(; node != NULL; node = node -> next)
//         printf("%d%c", node -> data, (node -> next == NULL) ? '\n' : ' ');
// }
 
// void tail_traverse(LinkedList *list){
//     ListNode *node = list -> tail;
//     for(; node != NULL; node = node -> prev)
//         printf("%d%c", node -> data, (node -> prev == NULL) ? '\n' : ' ');
// }
 
// int main(){
 
//     LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
//     list -> head = NULL;
//     list -> tail = NULL;
//     int func, val;
 
//     while(scanf("%d%d", &func, &val) != EOF){
//         switch (func){
//             case INSERT:
//                 insert(list, val);
//                 break;
//             case DELETE_HEAD:
//                 delete_head(list);
//                 break;
//             case DELETE_TAIL:
//                 delete_tail(list);
//                 break;
//         }
//     }
 
//     head_traverse(list);
//     tail_traverse(list);
 
//     return 0;
// }