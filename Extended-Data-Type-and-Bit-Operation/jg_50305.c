#include<stdio.h>
#include<stdint.h>
 
#define MY_CC 23
#define AVERAGE_CC 30

#define ull unsigned long long int
#define HEIGHT 75000
 
int main(){
    int n;
    scanf("%d", &n);
    ull num[HEIGHT+2];
    for(int i = 0; i < HEIGHT; i++){
        scanf("%llu", &num[i]);
    }
    //row ---
    int rowcnt = 0;
    int tmp;
    for(int i = 0; i < HEIGHT; i++){
        tmp = 0;
        for(ull test = 1ull << 63; test > 0; test >>= 1){
            // printf("%d", (num[i]&test)!=0);////////////////////////////////
            if(num[i]&test){
                tmp++;
            }else{
                if(tmp >= n) rowcnt += tmp-n+1;
                tmp = 0;
            }
        }
        if(tmp >= n) rowcnt += tmp-n+1;
        // printf("\n");////////////////////
    }
    //column ---
    int colcnt = 0;
    for(ull test = 1ull << 63; test > 0; test >>= 1){
        tmp = 0;
        for(int i = 0; i < HEIGHT; i++){
            if(num[i]&test){
                tmp++;
            }else{
                if(tmp >= n) colcnt += tmp-n+1;
                tmp = 0;
            }
        }
        if(tmp >= n) colcnt += tmp-n+1;
    }
    //diagonal ---
    int diagcnt = 0;
    int di;
    for(int i = -63; i < HEIGHT; i++){
        tmp = 0;
        di = 0;
        for(ull test = 1ull << 63; test > 0; test >>= 1){
            if((i+di >= HEIGHT) || (i+di < 0)){
                di++;
                continue;
            }else if(num[i+di]&test){
                tmp++;
            }else{
                if(tmp >= n) diagcnt += tmp-n+1;
                tmp = 0;
            }
            di++;
        }
        if(tmp >= n) diagcnt += tmp-n+1;
    }
    //antidiagonal ---
    int antidiagcnt = 0;
    ull test;
    for(int i = -63; i < HEIGHT; i++){
        tmp = 0;
        di = 0;
        test = 1;
        for(int _ = 0; _ < 64; test <<= 1, _++){
            if((i+di >= HEIGHT) || (i+di < 0)){
                di++;
                continue;
            }else if(num[i+di]&test){
                // printf("i+di %d test %d\n", i+di, test);
                tmp++;
            }else{
                if(tmp >= n) antidiagcnt += tmp-n+1;
                tmp = 0;
            }
            di++;
        }
        if(tmp >= n) antidiagcnt += tmp-n+1;
    }
    printf("%d\n%d\n%d\n%d\n", rowcnt, colcnt, diagcnt, antidiagcnt);
}