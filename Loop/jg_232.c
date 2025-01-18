#include<stdio.h>

int main(){
    int year, yearFirstD;
    scanf("%d%d", &year, &yearFirstD);
    int mtd[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //潤年再手動改
    if(((year%4==0&&year%100!=0) || (year%400==0)) || (year%1000==0)){ //潤年直接改mtd（因為year固定）
        mtd[2] = 29;
    }
    int n, m, d, dayPassed;
    scanf("%d", &n);
    for(int _ = 0; _ < n; _++){
        scanf("%d%d", &m, &d);
        if((m<1)||(m>12)){ //month error
            printf("-1\n");
        }else if((d>mtd[m])||(d<1)){ //day error
            printf("-2\n");
        }else{
            dayPassed = 0; //初始化
            for(int i = 1; i < m; i++){
                dayPassed += mtd[i];
            }
            dayPassed += d;
            printf("%d\n", (dayPassed+yearFirstD-1)%7);
        }
    }
}