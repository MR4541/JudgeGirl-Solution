#include<stdio.h>

#define MLE OJ判定問題，all testdata is AC

#define MY_CC 6
#define AVERAGE_CC 13.82

/*
對於1/2/3分別開dis紀錄當前距離
maxdis, secdis, maxfrom, secfrom紀錄最/次遠距離、開始點
記住只有newdis > maxdis才需要往後推
而new = maxdis/secdis則是覆蓋from
*/

//登記紀錄
void Record(int newdis, int nowpos, int *maxdis, int *maxfrom, int *secdis, int *secfrom){
    if(newdis > *maxdis){ //push
        *secdis = *maxdis; *secfrom = *maxfrom;
        *maxdis = newdis; *maxfrom = nowpos-newdis; 
    }else if(newdis == *maxdis){ //replace max
        *maxfrom = nowpos-newdis;
        //因為後輸入的值pos一定比較大，可直接覆蓋
    }else if(newdis >= *secdis){ //replace sec（<max >sec也要考慮）
        *secfrom = nowpos-newdis;
        *secdis = newdis;
    }
    return;
}

int main(){
    int num;
    int dis1 = -1, maxdis1 = 0, maxfrom1 = -1, secdis1 = 0, secfrom1 = -1;
    int dis2 = -1, maxdis2 = 0, maxfrom2 = -1, secdis2 = 0, secfrom2 = -1;
    int dis3 = -1, maxdis3 = 0, maxfrom3 = -1, secdis3 = 0, secfrom3 = -1; 
    int nowpos = 0; //現在是第幾個數
    while (scanf("%d", &num) != EOF){
        //if(num == -1) break;/////////////////////////////////////////////////////////
        
        dis1 += 1*(dis1 >= 0);
        dis2 += 1*(dis2 >= 0); //還沒第一次遇到2之前都不會觸發
        dis3 += 1*(dis3 >= 0); 

        if(num == 1){
            Record(dis1, nowpos, &maxdis1, &maxfrom1, &secdis1, &secfrom1); 
            //因為dis1原始是-1，不會觸發改動所以不用處理
            dis1 = 0; //重置
        }else if(num == 2){
            Record(dis2, nowpos, &maxdis2, &maxfrom2, &secdis2, &secfrom2); 
            dis2 = 0; //重置
        }else{ //num ==3
            Record(dis3, nowpos, &maxdis3, &maxfrom3, &secdis3, &secfrom3); 
            dis3 = 0; //重置
        }
        //printf("pos: %d dis: %d/%d/%d maxdis: %d/%d/%d\n", nowpos,dis1,dis2,dis3,maxdis1,maxdis2,maxdis3);
        nowpos++;
    }
    printf("%d %d %d\n", secdis1, secfrom1, secfrom1+secdis1);
    printf("%d %d %d\n", secdis2, secfrom2, secfrom2+secdis2);
    printf("%d %d %d\n", secdis3, secfrom3, secfrom3+secdis3);
}