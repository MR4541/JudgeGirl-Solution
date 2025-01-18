#include<stdio.h>
#include<stdbool.h>

int main(){
    int n;
    int pt[8]; //四個點(x,y) x是偶數
    int squLen[6]; //0-3是邊長 4-5是對角線
    int c23, c34; //外積
    int tmpx, tmpy;
    bool rightFlag, equalFlag;
    scanf("%d", &n);
    for(int _ = 0; _ < n; _++){
        for(int i = 0; i < 8; i++) scanf("%d", &pt[i]);
        /*
        依序排序點方法：
        有異號就swap：第1-2 2-3 1-2的向量外積
        六種情況：
        234 v
        432 342 324 234 v
        243 234 v
        342 324 234 v
        423 243 234 v
        324 234 v
        */  
        c23 = (pt[2]-pt[0])*(pt[5]-pt[1]) - (pt[3]-pt[1])*(pt[4]-pt[0]);//外積v12*v13
        if (c23<0){ //swap1
            tmpx = pt[2]; pt[2] = pt[4]; pt[4] = tmpx;
            tmpy = pt[3]; pt[3] = pt[5]; pt[5] = tmpy;
        }
        c34 = (pt[4]-pt[0])*(pt[7]-pt[1]) - (pt[5]-pt[1])*(pt[6]-pt[0]);//v13*v14
        if (c34<0){ //swap2
            tmpx = pt[6]; pt[6] = pt[4]; pt[4] = tmpx;
            tmpy = pt[7]; pt[7] = pt[5]; pt[5] = tmpy;
        }
        c23 = (pt[2]-pt[0])*(pt[5]-pt[1]) - (pt[3]-pt[1])*(pt[4]-pt[0]);//外積v12*v13
        if (c23<0){ //swap3
            tmpx = pt[2]; pt[2] = pt[4]; pt[4] = tmpx;
            tmpy = pt[3]; pt[3] = pt[5]; pt[5] = tmpy;
        }


        //處理邊長
        for(int i = 0; i < 3; i++) //0,1,2
            squLen[i] = (pt[2*i]-pt[2*i+2])*(pt[2*i]-pt[2*i+2]) + (pt[2*i+1]-pt[2*i+3])*(pt[2*i+1]-pt[2*i+3]);
        squLen[3] = (pt[0]-pt[6])*(pt[0]-pt[6]) + (pt[1]-pt[7])*(pt[1]-pt[7]); //邊長
        squLen[4] = (pt[0]-pt[4])*(pt[0]-pt[4]) + (pt[1]-pt[5])*(pt[1]-pt[5]);//對角13，對應邊01/23
        squLen[5] = (pt[2]-pt[6])*(pt[2]-pt[6]) + (pt[3]-pt[7])*(pt[3]-pt[7]);//對角24，對應邊12/30

        //開始判斷形狀
        equalFlag = true;
        rightFlag = false;
        for(int i = 0; i < 3; i++) //0>123 1>23 2>3
            for(int j = i+1; j < 4; j++)
                if(squLen[i] != squLen[j]) equalFlag = false;

        if(((squLen[4] == squLen[0]+squLen[1])&&(squLen[4] == squLen[2]+squLen[3])) && ((squLen[5] == squLen[2]+squLen[1])&&(squLen[5] == squLen[0]+squLen[3])))
            rightFlag = true;

        /*for(int i = 0; i < 8; i++) printf("%d ",pt[i]);
            printf("\n");
        for(int i = 0; i < 6; i++) printf("%d ",squLen[i]); */////////////////////

        if(rightFlag){
            if(equalFlag){
                printf("square\n");
            }else{
                printf("rectangle\n");
            }
        }else{
            if(equalFlag){
                printf("diamond\n");
            }else{
                printf("other\n");
            }
        }
    }
}