#include <stdio.h>

#define MY_CC 1
#define AVERAGE_CC 3.67

void Turing_Machine(int *head, int K){
    int currState = 0, tapeVal, moveDir, tableType;//tableType計算當前是12種的哪一種
    for(int _ = 0; _ < K; _++){
        tapeVal = *head; //讀取當前tape上值
        tableType = currState*4 + tapeVal; //0~11
        //moveDir 1是R, -1是L
        moveDir = (tableType<=3 || (tableType==5 || (tableType==7 || tableType==10)));
        moveDir -= (tableType==4 || (tableType==6 || tableType==9));
        *head = (*head + currState) % 4;//write tape
        head = head + moveDir; //move head
        currState = (tableType%2==0) + (tableType<=4) + (tableType==6);
    }
}

////////////////////////////////////
// int main()
// {
//     int n, p, K;
//     scanf("%d%d%d", &n, &p, &K);
//     int tape[n];
//     for(int i = 0; i < n; i++) scanf("%d", &tape[i]);
 
//     int *head = &tape[p];
//     Turing_Machine(head, K);
 
//     for(int i = 0; i < n; i++) printf("%d ", tape[i]);
 
//     return 0;
// }