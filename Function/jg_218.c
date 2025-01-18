#include<stdio.h>

int C(int a,int b){
    int ret=1;
    for(int i = 1; i <= b; i++){
        ret*=a+1-i;
        ret/=i;
    }
    return ret;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for(int i = 0; i <= m; i++)
        sum += C(n, i);
    printf("%d\n", sum);
}