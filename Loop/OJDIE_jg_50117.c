#include<stdio.h>

#define MLE OJ判定問題，all testdata is AC

int main(){
    int n, k;
    int r=0; //餘數
    int isZero = 1;
    scanf("%d", &k);
    scanf("%d", &n);//第一位是0就不輸出
    if(n >= k){
        printf("%d\n", n/k);
        isZero = 0;
    }
    r = n%k;
    while (scanf("%d", &n) != EOF){
        printf("%d\n", (10*r+n)/k);
        r = (10*r+n)%k;
        isZero = 0;
    }
    if(isZero) printf("0\n");
    
}