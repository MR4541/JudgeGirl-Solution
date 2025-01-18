#include<stdio.h>
#include<stdint.h>

#define MY_CC 2
#define AVERAGE_CC 2.2

int main(void){
    int n;
    scanf("%d", &n);
    uint64_t num;
    for(int _ = 0; _ < n; _++){
        scanf("%llu", &num);
        for(int i = 0; i < 12; i++){
            printf("%c", 'a'+(num%32));
            num >>= 5;
        }
    }
    printf("\n");
}