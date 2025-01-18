#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MY_CC 13
#define AVG_CC 17.3125

typedef struct node{
    char val;
    struct node* prev;
    struct node* next;
}Node;

Node* genNode(char val, Node* prev, Node* next){
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = val;
    new->prev = prev;
    new->next = next;
    return new;
}

void initFakeEnd(Node** fHead, Node** fTail){
    *fHead = genNode('\0', NULL, NULL);
    *fTail = genNode('\0', *fHead, NULL);
    (*fHead)->next = *fTail;
}

void insert_head(Node* fHead, Node* fTail, char val){
    Node* headnxt = fHead->next;
    Node* new = genNode(val, fHead, headnxt);
    headnxt->prev = new;
    fHead->next = new;
}

void insert_tail(Node* fHead, Node* fTail, char val){
    Node* tailprv = fTail->prev;
    Node* new = genNode(val, tailprv, fTail);
    tailprv->next = new;
    fTail->prev = new;
}

void delete_head(Node* fHead, Node* fTail){
    if(fHead->next == fTail){
        printf("0\n");
        return;
    }else{
        printf("1 %c\n", fHead->next->val);
    }
    Node* headnxtnxt = fHead->next->next;
    free(fHead->next);
    headnxtnxt->prev = fHead;
    fHead->next = headnxtnxt;
}

void delete_tail(Node* fHead, Node* fTail){
    if(fTail->prev == fHead){
        printf("0\n");
        return;
    }else{
        printf("1 %c\n", fTail->prev->val);
    }
    Node* tailprvprv = fTail->prev->prev;
    free(fTail->prev);
    tailprvprv->next = fTail;
    fTail->prev = tailprvprv;
}

void delete_all_char(Node* fHead, Node* fTail, char val){
    Node* cur = fHead->next;
    int cnt = 0;
    while (cur != fTail){
        if(cur->val == val){ //delete this node
            Node* curprv = cur->prev;
            Node* curnxt = cur->next;
            free(cur);
            curnxt->prev = curprv;
            curprv->next = curnxt;
            cur = curnxt;
            cnt++;
        }else{
            cur = cur->next;
        }
    }
    if(cnt == 0) printf("0\n");
    else printf("%d %c\n", cnt, val);
}

int size(Node* fHead, Node* fTail){
    int ret = 0;
    fHead = fHead->next;
    while(fHead != fTail){
        // printf("%c ", fHead->val);
        ret++;
        fHead = fHead->next;
    }
    // printf("total size: ");
    return ret;
}

int main(void){
    int Q;
    scanf("%d", &Q);
    Node *fHead, *fTail;
    initFakeEnd(&fHead, &fTail);
    assert(fHead->next == fTail);
    assert(fTail->prev == fHead);
    int ins; char c;
    while(Q--){
        scanf("%d", &ins);
        switch(ins){
            case 1:
                scanf(" %c", &c);
                insert_head(fHead, fTail, c);
                break;
            case 2:
                scanf(" %c", &c); //1_c，所以要空白
                insert_tail(fHead, fTail, c);
                break;
            case 3:
                delete_head(fHead, fTail);
                break;
            case 4:
                delete_tail(fHead, fTail);
                break;
            case 5:
                scanf(" %c", &c);
                delete_all_char(fHead, fTail, c);
                break;
            case 6:
                printf("%d\n", size(fHead, fTail));
                break;
        }
    }
}