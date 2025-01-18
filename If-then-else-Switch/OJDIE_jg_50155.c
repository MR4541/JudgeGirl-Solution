#include<stdio.h>

#define MLE OJ判定問題，all testdata is AC

/*
特例，a=e b=f c=g時輸出0其餘都正常跑
*/

#define MIN(a, b) ((a) - ((a)-(b))*((a)>(b)))

int main(){
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d", &a,&b,&c,&d,&e,&f,&g);
    int newD = 0;//最後深度
    if((a==e && (b==f && c<=g)) || d==0){
        printf("0\n");
        return 0;
    }else if(a*b*d >= (a*b-e*f)*g){ //水可以沒過鐵快
        newD = g;
        newD += (a*b*d - (a*b-e*f)*g)/a/b;
    }else{ //水不夠沒過鐵塊
        newD = a*b*d/(a*b-e*f);
    }

    printf("%d\n", MIN(newD, c));
}