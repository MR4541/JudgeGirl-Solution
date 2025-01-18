#include<stdio.h>

int Sum(int i,int n,int sum){
    if(i>n) return sum;
    else return Sum(i+1, n, sum+i*i);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", Sum(1, n, 0));
}