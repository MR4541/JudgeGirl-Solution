#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ull;

int oneCnt(ull num){
    int cnt = 0;
    while(num > 0){
        cnt += (num&1);
        num >>= 1;
    }
    return cnt;
}

int compare(const void* a, const void* b){
    ull lla = *(ull*)a;
    ull llb = *(ull*)b;
    int acnt = oneCnt(lla);
    int bcnt = oneCnt(llb);
    return (acnt > bcnt) || (acnt == bcnt && lla > llb);
}

int main(void){
    int n = 0;
    ull arr[1000];
    while(scanf("%lld", &arr[n]) != EOF) n++;
    qsort(arr, n, sizeof(ull), compare);
    for(int i = 0; i < n; i++) printf("%lld\n", arr[i]);
}