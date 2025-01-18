#include<stdio.h>

#define MY_CC 3
#define AVERAGE_CC 3

int main(){
    int x1,y1,r1,x2,y2,r2;
    scanf("%d%d%d%d%d%d", &x1,&y1,&r1,&x2,&y2,&r2);
    int x, y;
    int flag; //0:out 1:on 2+:in
    while (scanf("%d%d", &x,&y) != EOF){
        flag = 2*((x-x1)*(x-x1)+(y-y1)*(y-y1) < r1*r1);
        flag += 2*((x-x2)*(x-x2)+(y-y2)*(y-y2) < r2*r2);
        flag += ((x-x1)*(x-x1)+(y-y1)*(y-y1) == r1*r1 || (x-x2)*(x-x2)+(y-y2)*(y-y2) == r2*r2);
        if(flag == 0){
            printf("Out\n");
        }else if(flag == 1){
            printf("On\n");
        }else{
            printf("In\n");
        }
    }
    
}