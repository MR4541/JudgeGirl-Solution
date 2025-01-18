#include<stdio.h>

#define MY_CC 0
#define AVERAGE_CC 8.25

#define POS(a) ((a) * ((a) > 0))
#define NEG(a) ((a) * ((a) < 0))
#define MAX(a, b) ((a) - ((a) - (b)) * ((a) < (b)))
#define MIN(a, b) ((a) - ((a) - (b)) * ((a) > (b)))
 
void CalArea(int x1,int y1,int x2,int y2,int qua[5],int inverse){
    qua[1] += POS(x2-POS(x1))*POS(y2-POS(y1))*inverse;
    qua[2] += POS(NEG(x2)-x1)*POS(y2-POS(y1))*inverse;
    qua[3] += POS(NEG(x2)-x1)*POS(NEG(y2)-y1)*inverse;
    qua[4] += POS(x2-POS(x1))*POS(NEG(y2)-y1)*inverse;
}
 
int main(void){
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    scanf("%d%d%d%d%d%d%d%d",&ax1,&ay1,&ax2,&ay2,&bx1,&by1,&bx2,&by2);
    // printf("%d %d %d %d %d %d %d %d\n", ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    int qua[5] = {0};
    CalArea(ax1,ay1,ax2,ay2,qua,1);
    CalArea(bx1,by1,bx2,by2,qua,1);
    int cx1=MAX(ax1,bx1), cy1=MAX(ay1,by1);
    int cx2=MIN(ax2,bx2), cy2=MIN(ay2,by2);
    CalArea(cx1,cy1,cx2,cy2,qua,-1);
    printf("%d\n%d\n%d\n%d\n", qua[1], qua[2], qua[3], qua[4]);
}