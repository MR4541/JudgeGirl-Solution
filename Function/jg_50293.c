#include<stdio.h>

#define MY_CC 5
#define AVERAGE_CC 8.2

/*
存第一組power, cnt，最後再跟last接看看
*/

int main(){
    int nowPower, prevPower, Cnt = 0; //當前/前一人power，現在連續第幾
    int maxSum, maxPower, maxCnt; //最大power組的資料
    int firstPower, firstCnt = 0; //紀錄第一組值、連續，當currCnt第一次斷掉就更新到firstCnt（判斷是否為0）
    int n;
    scanf("%d", &n);
    scanf("%d", &prevPower);
    Cnt = 1; //第一組先算連續
    firstPower = prevPower; //之後不會再改值
    maxSum = prevPower; maxPower = prevPower; maxCnt = 1; //先把第一組設為最大
    for(int i = 1; i < n; i++){ //跑n-1次
        if(prevPower*Cnt>maxSum || (prevPower*Cnt==maxSum && maxPower>prevPower)){ //更新最大值
            //一輪的prev等於上一輪的now
            maxPower = prevPower; maxSum = prevPower*Cnt; maxCnt = Cnt;
        }

        scanf("%d", &nowPower);
        if(nowPower == prevPower){ //和上一位同一組
            Cnt++; //連續
        }else{ //不同組
            firstCnt += (Cnt)*(firstCnt == 0); //斷第一次後更新first
            Cnt = 1; //重置
        }

        prevPower = nowPower; //Push
    }
    
    //處理最後一組：如果arr[0]==arr[-1]把cnt加上去
    if(firstPower == prevPower){
        Cnt += firstCnt; //first初始值設0，這樣假設整桌都一樣，因為不會更新到firstCnt就是+0，不會爛掉
    }
    //最後檢測一次
    if(prevPower*Cnt>maxSum || (prevPower*Cnt==maxSum && maxPower>prevPower)){ //更新最大值
        //一輪的prev等於上一輪的now
        maxPower = prevPower; maxSum = prevPower*Cnt; maxCnt = Cnt;
    }

    printf("%d %d\n", maxPower, maxCnt);
}