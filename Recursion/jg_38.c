#include<stdio.h>

#define MIN(a, b) ((a) - ((a) - (b)) * ((a) > (b)))

//各種還剩幾個、還有缺多少magic power
int canfind(int D, int a, int b, int c, int A, int B, int C){
    // printf("%d %d %d\n", a, b, c);
    if((D < 0 || a < 0) || (b < 0 || c < 0))
        return 0;
    if(D == 0)
        return 1;
    return canfind(D-A,a-1,b,c,A,B,C) || 
        (canfind(D-B,a,b-1,c,A,B,C) || canfind(D-C,a,b,c-1,A,B,C));
}

int main(){
    int n;
    scanf("%d", &n);
    int D, a, b, c, A, B, C;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d%d%d%d", &D,&a,&b,&c,&A,&B,&C);
        if(A==0) a=0; else a=MIN(a, D/A); //減少不必要的遞回
        if(B==0) b=0; else b=MIN(b, D/B);
        if(C==0) c=0; else c=MIN(c, D/C);
        if(canfind(D, a, b, c, A, B, C))
            printf("yes\n");
        else
            printf("no\n");
    }
}