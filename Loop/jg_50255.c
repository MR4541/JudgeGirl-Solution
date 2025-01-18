#include<stdio.h>
#define MIN(a, b) ((a) - ((a) - (b)) * ((a) > (b)))

#define MY_CC 2
#define AVERAGE_CC 6.88

int main(){
    int ax,ay, bx,by, cx,cy, dx,dy;
    int distA, distB, distC, mindist;
    int cnt = 0;
    while (scanf("%d%d%d%d%d%d%d%d", &ax,&ay, &bx,&by, &cx,&cy, &dx,&dy) != EOF){
        distA = (ax-dx)*(ax-dx) + (ay-dy)*(ay-dy);
        distB = (bx-dx)*(bx-dx) + (by-dy)*(by-dy);
        distC = (cx-dx)*(cx-dx) + (cy-dy)*(cy-dy);
        mindist = MIN(distA, MIN(distB, distC));
        if(cnt > 0) printf(" ");
        printf("%d", (distA==mindist)+2*(distB==mindist)+3*(distC==mindist)
        +(distA==mindist&&distB==mindist)+(distB==mindist&&distC==mindist)+(distA==mindist&&distC==mindist)
        -9*(distA==mindist&&(distB==mindist&&distC==mindist)));
        cnt++;
    }
    printf("\n");
}