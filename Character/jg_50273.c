#include<stdio.h>
#include<string.h>

#define MY_CC 4
#define AVERAGE_CC 6.1

void search(char prev[], char now[], int *perimeter){
    int prevlen = strlen(prev);
    int nowlen = strlen(now);
    for(int i = 0; i < prevlen; i++){
        for(int j = 0; j < nowlen; j++){
            if(prev[i] == now[j]){
                *perimeter += i-j;
                return;
            }
        }
    }
}

int main(){
    char first[1002], prev[1002], now[1002];
    scanf("%s", first);
    strcpy(prev, first);
    int perimeter = 0;
    while (scanf("%s", now) != EOF){
        // if(now[0] == '-') break;//////////////////////
        search(prev, now, &perimeter);
        strcpy(prev, now);
    }
    strcpy(now, first);
    search(prev, now, &perimeter);
    printf("%d\n", perimeter);
}