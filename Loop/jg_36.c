#include<stdio.h>

int main(){
    int y, m, firstD;
    scanf("%d%d%d", &y, &m, &firstD);
    if((m<1 || m>12) || (firstD<0 || firstD>6)){
        printf("invalid\n");
        return 0;
    }
    int mtd[13] = {-1, 31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31};
    mtd[2] += ((y%4==0 && y%100!=0) || y%400 == 0 );//判斷潤年
    printf(" Su Mo Tu We Th Fr Sa\n=====================\n");
    int currD = 0; //用來輸出日期
    int cnt = 0; //計算該行已經輸出幾次，每七次就換行
    while(currD < mtd[m]){
        if(firstD > 0){
            firstD --; //例如第一天是thur=4，星期日、一、二、三都會是空格
            printf("   ");
            cnt++;
            continue;
        }
        if(cnt >= 7){
            printf("\n");
            cnt = 0;
        }
        currD++;
        printf("%3d", currD); //3d強制規定輸出寬度3
        cnt++;
    }
    printf("\n=====================\n");
}