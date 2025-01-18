#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

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
    if(fHead->next == fTail)
        return;
    Node* headnxtnxt = fHead->next->next;
    free(fHead->next);
    headnxtnxt->prev = fHead;
    fHead->next = headnxtnxt;
}

void delete_tail(Node* fHead, Node* fTail){
    if(fTail->prev == fHead) 
        return;
    Node* tailprvprv = fTail->prev->prev;
    free(fTail->prev);
    tailprvprv->next = fTail;
    fTail->prev = tailprvprv;
}

void delete_all_char(Node* fHead, Node* fTail, char val){
    Node* cur = fHead->next;
    while (cur != fTail){
        if(cur->val == val){ //delete this node
            Node* curprv = cur->prev;
            Node* curnxt = cur->next;
            free(cur);
            curnxt->prev = curprv;
            curprv->next = curnxt;
            cur = curnxt;
        }else{
            cur = cur->next;
        }
    }
}

int size(Node* fHead, Node* fTail){
    int ret = 0;
    fHead = fHead->next;
    while(fHead != fTail){
        // printf("%c ", fHead->val); ///////////////////////////////////////////
        ret++;
        fHead = fHead->next;
    }
    // printf("total size: "); ///////////////////////////////////////////////
    return ret;
}

typedef unsigned long long llu;

char find(char* str, char alphaTable[26][8]){
    int idx = 0;
    while(idx < 26){
        if(strcmp(str, alphaTable[idx]) == 0)
            return 'a'+idx;
        idx++;
    }
    return '?';
}

// void print_llu_in(llu a){
//     int cnt = 0;
//     for(int i = 63; i >= 0; i--, cnt++) {
//         printf("%lld", (a>>i)&1);
//         if(cnt&1) printf(" ");
//     }
//     printf("\n"); 
// }

int main(void){
    char infile[24], outfile[24];
    scanf("%s%s", infile, outfile);
    FILE* fin = fopen(infile, "r");
    char table[26][8];
    char *inchars = (char*)malloc(sizeof(char)*4000000);
    int n_inchars = 0;

    llu inNum;
    int endFlag = 1;
    while(fscanf(fin, "%llu", &inNum)!=EOF && endFlag){
        // print_llu_in(inNum);///////////////////////////////////////////////////////////////////////
        for(int test = 62; test >= 0; test -= 2){
            int pattern = (inNum >> test) % 4;
            if(pattern == 0) inchars[n_inchars] = '.';
            else if(pattern == 1) inchars[n_inchars] = '-';
            else if(pattern == 2) inchars[n_inchars] = ' ';
            else{
                inchars[n_inchars] = '\0';
                endFlag = 0;
                break;
            }
            n_inchars++;
        }
    }
    fclose(fin);

    // printf("size: %d\n", n_inchars);
    // for(int i = 0; i < n_inchars; i++){
    //     printf("%c", inchars[i]);
    // }
    // printf("\n");

    Node *fHead, *fTail;
    initFakeEnd(&fHead, &fTail);

    char* tmp = strtok(inchars, " ");
    int N = 0;
    while(tmp != NULL){
        if(N <= 25){
            strcpy(table[N], tmp);
            // printf("table[%d] %s\n", N, table[N]);
        }else{
            // printf("%c ", find(tmp, table));
            insert_tail(fHead, fTail, find(tmp, table));
        }
        N++;
        tmp = strtok(NULL, " ");
    }
    // printf("N = %d\n", N);

    // printf("%d\n", size(fHead, fTail));

    /*
        start to process commands
    */
    int Q;
    scanf("%d", &Q);
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
        }
    }

    // printf("%d\n", size(fHead, fTail));
    
    FILE* fout = fopen(outfile, "w");
    fprintf(fout, "%d\n", size(fHead, fTail));
    fHead = fHead->next;
    while(fHead != fTail){
        free(fHead->prev);
        fprintf(fout, "%c\n", fHead->val);
        fHead = fHead->next;
    }
    free(fHead->prev); free(fHead);
}