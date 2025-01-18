#include<stdio.h>

int main(){
    int n, m;
    int md[7];
    int cnt = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < 7; i++){
        md[6-i] = m%10;
        m /= 10;  
    }
    for(int i = 0; i < 6; i++){
        if(n == md[i]*10 + md[i+1]) cnt++;
    }
    printf("%d\n", cnt);
}