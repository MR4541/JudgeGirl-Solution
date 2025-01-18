#include<stdio.h>
#include<stdlib.h>
 
#define MLE OJ判定問題，all testdata is AC

typedef struct node{
    struct node* rightPtr;
    struct node* downPtr;
}NODE;

int calArea(NODE* head){
    int sum = 0, width = 0; //計算每一橫行有多少block
    NODE* rightPathNode = head->rightPtr;
    width++;
    NODE* downPathNode = head->downPtr;
    while(rightPathNode->rightPtr != NULL){ //走到下一個往下的地方為止
        rightPathNode = rightPathNode->rightPtr;
        width++;
    }
    //結算第一層
    sum += width; //兩點距離還是width，不用歸零
    rightPathNode = rightPathNode->downPtr; //現在down, right在同一層
    while(1){ //=0表示兩點交匯，也就是end
        //right跟down都走到下一個要往下的地方
        while(rightPathNode->rightPtr != NULL){
            rightPathNode = rightPathNode->rightPtr;
            width++;
        }
        while (downPathNode->rightPtr != NULL){
            downPathNode = downPathNode->rightPtr;
            width--;
        }
        if(width == 0) //right = down
            return sum;
        sum += width;
        rightPathNode = rightPathNode->downPtr;
        downPathNode = downPathNode->downPtr;
    }
}

//////////////////////////////////////////////////////////
// NODE* initList(NODE* pos, int len){
//     NODE* tail = pos;
//     char direction;
//     for(int i = 0; i < len-1; i++){
//         scanf("%c", &direction);
//         getchar();
//         NODE* pNew = (NODE*) malloc(sizeof(NODE));
//         pNew->downPtr = NULL;
//         pNew->rightPtr = NULL;
//         if(direction == 'r'){
//             pos->rightPtr = pNew;
//             pos = pos->rightPtr;
//         }
//         else{
//             pos->downPtr = pNew;
//             pos = pos->downPtr;
//         }
//         if(i == len-3)
//             tail = pos;
//     }
//     return tail;
// }
 
// int main(){
//     int len;
 
//     NODE* head = (NODE*) malloc(sizeof(NODE));
 
//     scanf("%d\n", &len);
//     getchar();
//     NODE *pos;
//     char direction;
//     scanf("%c", &direction);
//     head->rightPtr = (NODE*) malloc(sizeof(NODE));
//     pos = head->rightPtr;
//     pos->downPtr = NULL;
//     pos->rightPtr = NULL;
//     NODE* tailR = initList(pos, len);
 
//     head->downPtr = (NODE*) malloc(sizeof(NODE));
//     pos = head->downPtr;
//     pos->downPtr =NULL;
//     pos->rightPtr = NULL;
//     scanf("%c", &direction);
//     getchar();
//     NODE* tailD = initList(pos, len);
//     free(tailD->rightPtr);
//     tailD->rightPtr = tailR->downPtr;
 
//     printf("%d", calArea(head));
// }