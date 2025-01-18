#include<stdio.h>
#include<stdint.h>
#define ARRAYSIZE 1000
 
#define MAX(a, b) ((a) - ((a) - (b)) * ((a) < (b))) 

#define MY_CC 3
#define AVERAGE_CC 3.5

typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;
 
int numZeroBits(GiantUnsignedInt *giantNum){
    int ret = 0, cnt = 0;
    for(int i = 0; i < giantNum->n; i++){
        for(uint64_t test = 1ull << 63; test>0; test >>=1){
            if((test & giantNum->array[i]) == 0){
                cnt++;
            }else{
                ret = MAX(ret, cnt);
                cnt = 0;
            }
        }
        ret = MAX(ret, cnt);
    }
    return ret;
}