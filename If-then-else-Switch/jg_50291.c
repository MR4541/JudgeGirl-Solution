#include<stdio.h>

int main(){
    int x1,y1,qua1, x2,y2,qua2, x3,y3,qua3;
    scanf("%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3);
    qua1 = (x1 && y1)*(1 + 2*(y1 < 0) + ((x1<0)^(y1<0))); //一行判斷象限
    qua2 = (x2 && y2)*(1 + 2*(y2 < 0) + ((x2<0)^(y2<0)));
    qua3 = (x3 && y3)*(1 + 2*(y3 < 0) + ((x3<0)^(y3<0)));
    //printf("%d %d %d\n", qua1, qua2, qua3);
    int edges = 0;
    int sub = qua1-qua2;
    edges += (sub==0)*1 + (sub%2!=0)*2  + (!(sub%2)&&sub)*(2+(x1*y2 != x2*y1)); //邊數
    sub = qua3-qua2;
    edges += (sub==0)*1 + (sub%2!=0)*2  + (!(sub%2)&&sub)*(2+(x3*y2 != x2*y3));
    sub = qua1-qua3;
    edges += (sub==0)*1 + (sub%2!=0)*2  + (!(sub%2)&&sub)*(2+(x1*y3 != x3*y1));

    printf("%d\n",edges); 



    x1,y1,qua1, x2,y2,qua2, x3,y3,qua3;
    scanf("%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3);
    qua1 = (x1 && y1)*(1 + 2*(y1 < 0) + ((x1<0)^(y1<0))); //一行判斷象限
    qua2 = (x2 && y2)*(1 + 2*(y2 < 0) + ((x2<0)^(y2<0)));
    qua3 = (x3 && y3)*(1 + 2*(y3 < 0) + ((x3<0)^(y3<0)));
    //printf("%d %d %d\n", qua1, qua2, qua3);
    edges = 0;
    sub = qua1-qua2;
    edges += (sub==0)*1 + (sub%2!=0)*2  + (!(sub%2)&&sub)*(2+(x1*y2 != x2*y1)); //邊數
    sub = qua3-qua2;
    edges += (sub==0)*1 + (sub%2!=0)*2  + (!(sub%2)&&sub)*(2+(x3*y2 != x2*y3));
    sub = qua1-qua3;
    edges += (sub==0)*1 + (sub%2!=0)*2  + (!(sub%2)&&sub)*(2+(x1*y3 != x3*y1));

    printf("%d\n",edges); 
}