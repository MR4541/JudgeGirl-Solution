#include<stdio.h>

/*
    axcy         cxcy
        dxdy/bxby
    axay         cxay
*/

int main(){
    int ax,ay,bx,by,cx,cy,dx,dy;
    scanf("%d%d%d%d%d%d%d%d", &ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
    int peri = 2*(cx+cy-ax-ay);
    int area = (cx-ax)*(cy-ay) - (cx-bx)*(by-ay) - (dx-ax)*(cy-dy);
    printf("%d\n%d\n", peri, area);
}