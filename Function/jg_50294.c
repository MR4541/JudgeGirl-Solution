#include<stdio.h>
 
#define MY_CC 5
#define AVERAGE_CC 9.2

#define MAX(a, b) ((a) - ((a)-(b)) * ((b)>(a)))
 
int main(){
    int n,a,b;
    scanf("%d%d%d", &n, &a, &b);
    int isDown = 1; //是否在下行
    int num;
    int upCnt = 0, downCnt = 0, maxCnt = 0; //連續數
    int upPrev = -1, downPrev = -1; //前一個數（-1應該會爛）/////////////
    for(int _ = 0; _ < n; _++){
        for(int i = 0; i < 2*a-b; i++){
            scanf("%d", &num);
            isDown = (i < b || ((i-b)%4 == 0 || (i-b)%4 == 3));
            //printf("%d ", isDown);//////////////////////////
 
            if(isDown){
                if(num == downPrev){
                    downCnt++;
                }else{
                    maxCnt = MAX(maxCnt, downCnt);
                    downCnt = 1;
                }
                downPrev = num;
            }else{
                if(num == upPrev){
                    upCnt++;
                }else{
                    maxCnt = MAX(maxCnt, upCnt);
                    upCnt = 1;
                }
                upPrev = num;
            }
        }
        maxCnt = MAX(maxCnt, upCnt);
        upCnt = 0; //因為b!=0所以一定會斷
    }
    maxCnt = MAX(maxCnt, downCnt);
    maxCnt = MAX(maxCnt, upCnt);
    printf("%d\n", maxCnt);
}