#include<stdio.h>

int main(){
    int r,c;
    scanf("%d%d", &r, &c);
    int sum[100] = {0}, tmp; //減少記憶體用量
    for(int i = 0; i < r*c; i++){
        scanf("%d", &tmp);
        sum[i%c] += tmp;
    }
    for(int i = 0; i < c; i++)
        printf("%d\n", sum[i]/r);
}