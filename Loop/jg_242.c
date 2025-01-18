#include <stdio.h>
#include <stdbool.h>
#define lli long long
//#define DEBUG //註解掉這行可以讓所有ifdef - endif區間內的code不被編譯

/*
只掃每個圓心+-半徑聯集起來的範圍
紀錄先前掃的範圍，重複就跳掉
*/
int distTest(lli x, lli y, lli xC, lli yC, lli r){ //測試是否在圓內
    return ((x-xC)*(x-xC) + (y-yC)*(y-yC) <= r*r);
}


int main(){
    int n;
    scanf("%d", &n);
    lli x1,y1,r1, x2,y2,r2, x3,y3,r3;
    int cnt, inCircle, flag; //flag用來檢測當前點是否被重複計算
    for(int _ = 0; _ < n; _++){
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &x1,&y1,&r1, &x2,&y2,&r2, &x3,&y3,&r3);
        cnt = 0;
        for(lli x = x1-r1; x <= x1+r1; x++){ //跑第一個圓的範圍
            for(lli y = y1-r1; y <= y1+r1; y++){
                inCircle = distTest(x,y,x1,y1,r1) + distTest(x,y,x2,y2,r2) + distTest(x,y,x3,y3,r3);
                cnt += (inCircle%2) ; //如果是奇數就加一
#ifdef DEBUG
                if(inCircle%2) printf("(%d, %d)\n", x, y);
#endif
            }
        }
        for(lli x = x2-r2; x <= x2+r2; x++){ //跑第二個圓的範圍
            for(lli y = y2-r2; y <= y2+r2; y++){
                flag = !((x>=x1-r1 && x<=x1+r1) && (y>=y1-r1 && y<=y1+r1));
                inCircle = distTest(x,y,x1,y1,r1) + distTest(x,y,x2,y2,r2) + distTest(x,y,x3,y3,r3);
                cnt += ((inCircle%2)&&flag); //如果是奇數就加一，flag是0表示已經計算過，不跑
#ifdef DEBUG
                if(inCircle%2) printf("(%d, %d), %d\n", x, y, flag);
#endif
            }
        }
        for(lli x = x3-r3; x <= x3+r3; x++){ //跑第三個圓的範圍
            for(lli y = y3-r3; y <= y3+r3; y++){
                flag = !((x>=x1-r1 && x<=x1+r1) && (y>=y1-r1 && y<=y1+r1));
                flag *= !((x>=x2-r2 && x<=x2+r2) && (y>=y2-r2 && y<=y2+r2));
                inCircle = distTest(x,y,x1,y1,r1) + distTest(x,y,x2,y2,r2) + distTest(x,y,x3,y3,r3);
                cnt += ((inCircle%2)&&flag); //如果是奇數就加一，flag是0表示已經計算過，不跑
#ifdef DEBUG
                if(inCircle%2) printf("(%d, %d), %d\n", x, y, flag);
#endif
            }
        }
        printf("%d\n", cnt);
    }
}