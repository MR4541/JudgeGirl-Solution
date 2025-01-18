#include<stdio.h>
#include<stdlib.h>

// #define H24

typedef struct Time {
    int hour;
    int minute;
    int second;
} Time;
 
void initTime(Time *time){
    time->hour = 0;
    time->minute = 0;
    time->second = 0;
}
void setTime(Time *time, int hour, int minute, int second){
    time->hour = hour;
    time->minute = minute;
    time->second = second;
}
void addTime(Time *time, int hour, int minute, int second){
    int secs = 3600*(hour+time->hour) + 60*(minute+time->minute) + second+time->second;
    secs %= 86400; //in case of overflow
    time->hour = secs / 3600;
    time->minute = (secs / 60) % 60;
    time->second = secs % 60;
}
void printTime(Time *time){
    #ifdef H24
        printf("%02d:%02d:%02d\n", time->hour, time->minute, time->second);
    #else
        if(time->hour == 0) printf("12am:%02d:%02d\n", time->minute, time->second);
        else if(time->hour == 12) printf("12pm:%02d:%02d\n", time->minute, time->second);
        else if(time->hour > 12) printf("%02dpm:%02d:%02d\n", time->hour - 12, time->minute, time->second);
        else printf("%02dam:%02d:%02d\n", time->hour, time->minute, time->second);
    #endif
}

// int main(){
//     Time *a = (Time*)malloc(sizeof(Time));
//     initTime(a);
//     printTime(a);
//     setTime(a, 12, 3, 20);
//     printTime(a);
//     addTime(a, 12, 3, 40);
//     printTime(a);
// }