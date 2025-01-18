#include<stdio.h>

#define MY_CC 1
#define AVERAGE_CC 4.7

int QuaOf(int x, int y){
    return 1 + 2*(y<0) + ((x>0)^(y>0)); //^是位元XOR，記得用括弧包起來不然會先算四則
}

int Segment(int x1, int y1, int x2, int y2){
    int quaDiff = QuaOf(x1,y1)-QuaOf(x2,y2); //象限差
    int ret = 2 - (quaDiff==0); //同象限=1，其他=2
    ret += ((ret==2)&&(quaDiff%2==0))&&(x1*y2!=x2*y1); 
    //對角象限且不過原點y1/x1=y2/x2
    //printf("seg of (%d,%d)to(%d,%d) is %d\n", x1,y1,x2,y2,ret);
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    int x0,y0;
    scanf("%d%d", &x0, &y0);
    int prev_x, prev_y, x, y;
    scanf("%d%d", &prev_x, &prev_y); //p_1
    int segSum = Segment(prev_x, prev_y, x0, y0);
    for(int i = 2; i < n; i++){ //p_2 ~ p_n-1
        scanf("%d%d", &x, &y);
        segSum += Segment(x, y, prev_x, prev_y);
        segSum += Segment(x, y, x0, y0);
        prev_x = x; prev_y = y;
    }
    printf("%d\n", segSum);
}