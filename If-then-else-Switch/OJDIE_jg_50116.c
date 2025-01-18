#include<stdio.h>

#define MLE OJ判定問題，all testdata is AC

int main(){
    int digit;
    int cnt = 0, zeroCnt = 0;
    int flag = 1; //每個數字換正負，計算11n
    int sumFor11 = 0;
    while (scanf("%d", &digit) != EOF){
        cnt++;
        zeroCnt += (digit == 0);
        sumFor11 += flag*digit;
        flag *= -1;
    }
    printf("%d\n%d\n%d\n%d\n", cnt, !(digit%2), zeroCnt, !(sumFor11%11));
}