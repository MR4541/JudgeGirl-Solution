#include<stdio.h>

//#define MLE OJ判定問題，all testdata is AC
//天哪他修好了

#define MY_CC 1
#define AVERAGE_CC 2.22
/*m n-1 m-1 n-2 ...*/

int main(){
    int n,m,num;
    scanf("%d%d%d", &n,&m,&num);
    int nowlayerCnt=1; //每跑完一行一列加一
    int need = m, dir = 1;//1是橫 -1是直
    int nowpos = 1;
    while (num >= nowpos+need){
        nowpos += need;
        nowlayerCnt += (dir==-1);
        dir -= 2*dir;
        need = (dir>0)*(m+1-nowlayerCnt) + (dir<0)*(n-nowlayerCnt);
    }
    //用nowlayer, dir, num-nowpos算
    int x = nowlayerCnt, y = nowlayerCnt; //坐標是1base
    //位在橫行    
    y += (dir==1)*(num-nowpos);
    //位在直行
    x += (dir==-1)*(num-nowpos+1); //因為(x,y)是在直行開始的上面一格
    printf("%d %d\n", x, y);
    
}