#include<stdio.h>

#define MY_CC 2 //只能照著他的公式算不然會有誤差
#define AVERAGE_CC 1.95

int main(){
    int n;
    scanf("%d", &n);
    double aver = 0;
    double sigma = 0;
    double num[n];
    for(int i = 0; i < n; i++){
        scanf("%lf", &num[i]);
        aver += num[i];
    }
    aver /= n;
    for(int i = 0; i < n; i++){
        sigma += (num[i]-aver)*(num[i]-aver);
    }
    sigma /= n;
    printf("%lf\n%lf\n", aver, sigma);
}