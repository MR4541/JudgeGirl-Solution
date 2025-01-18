#include<stdio.h>

#define POS(a) ((a) * ((a) > 0))
#define MAX(a, b) ((a) - ((a) - (b))*((a) < (b)))
#define MIN(a, b) ((a) - ((a) - (b))*((a) > (b)))
#define MAX3(a, b, c) (MAX((a), MAX((b), (c))))
#define lli long long

lli Area(lli x1, lli y1, lli x2, lli y2){
    return POS(x2-x1)*POS(y2-y1);
}

int main(){
    lli ax1,ay1,ax2,ay2, bx1,by1,bx2,by2, cx1,cy1,cx2,cy2;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",
        &ax1,&ay1,&ax2,&ay2, &bx1,&by1,&bx2,&by2, &cx1,&cy1,&cx2,&cy2);
    lli sum = Area(ax1,ay1,ax2,ay2) + Area(bx1,by1,bx2,by2) + Area(cx1,cy1,cx2,cy2);
    sum -= Area(MAX(ax1,bx1),MAX(ay1,by1),MIN(ax2,bx2),MIN(ay2,by2));
    sum -= Area(MAX(cx1,bx1),MAX(cy1,by1),MIN(cx2,bx2),MIN(cy2,by2));
    sum -= Area(MAX(ax1,cx1),MAX(ay1,cy1),MIN(ax2,cx2),MIN(ay2,cy2));
    sum += Area(MAX3(ax1,bx1,cx1), MAX3(ay1,by1,cy1), -MAX3(-ax2,-bx2,-cx2), -MAX3(-ay2,-by2,-cy2));
    printf("%lld\n", sum);
}