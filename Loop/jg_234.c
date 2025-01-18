#include<stdio.h>
#define lli long long
/*
暴力硬搜x
要由小到大找d,e,f，又f(x)=0時x= -d/e/f
所以x從最大開始掃
*/

int main(){
    lli a,b,c;
    scanf("%lld%lld%lld", &a,&b,&c); //lld是long long的格式
    lli result;
    int cnt = 0;
    for(lli i = 100000; i >= -100000; i--){
        result = i*i*i + a*i*i + b*i + c;
        //printf("res %lld\n", result);///////////////////////////////
        if(result == 0){
            //printf("here\n");
            printf("%lld", -i);
            cnt ++;
            if(cnt < 3){
                printf(" ");
                result = 3*i*i + 2*a*i + b; //二重根檢驗
                if(result == 0){
                    printf("%lld", -i);
                    cnt ++;
                    if(cnt < 3){
                        printf(" ");
                        if(6*i + 2*a == 0){
                            printf("%lld", -i); //三重根檢驗
                            return 0;
                        }
                    }
                }
            }else
                return 0;
        }
    }
}