#include<stdio.h>

#define MY_CC 1
#define AVERAGE_CC 3.46

#define ABS(x) ((x) - 2*(x)*((x)<0))
#define MIN(a, b) ((a) - ((a)-(b))*((a)>(b)))

int TimeToSec(int time){
    int sec = time%100;
    time /= 100; sec += (time%100)*60;
    time /= 100; sec += (time%100)*3600;
    return sec;
}

int main(){
    int time, prevtime,diff;
    int min = 100000; //>86400
    scanf("%d", &prevtime);
    while (scanf("%d", &time) != EOF){
        diff = ABS(TimeToSec(time) - TimeToSec(prevtime));
        min = MIN(diff, min);
        //printf("diff %d min %d\n", diff, min);////////////////////////////////
        prevtime = time;
    }
    printf("%d\n", min);
}