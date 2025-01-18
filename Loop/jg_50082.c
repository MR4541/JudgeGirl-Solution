#include<stdio.h>

#define MAX(a, b) ((a) - ((a)-(b))*((b)>(a))) 
/*
變數：curr/prev_A/B_ready完成該任務AB段的時間
每loop：
currA = MAX(任務開始時間, prevA) + needTimeA
currB = MAX(currA, prevB) + needTimeB
*/

int main(){
    int prevA = 0, prevB = 0; //前次任務AB機器完成時間
    int needA, needB, arrivalTime; //需花費AB時間、任務抵達時間
    int currA, currB; //當前該項任務AB機器完成時間（最後push給prev）
    while (scanf("%d%d%d", &arrivalTime, &needA, &needB) != EOF){
        currA = MAX(arrivalTime, prevA) + needA;
        currB = MAX(currA, prevB) + needB;
        printf("%d\n", currB);
        prevA = currA; prevB = currB;
    }
    
}