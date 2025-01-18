#include<stdio.h>
#include<stdint.h>
#define ARRAYSIZE 1000

typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;
 
int numBitChanges(GiantUnsignedInt *giantNum){
    int ret = (giantNum->array[0]>>63) != (giantNum->array[giantNum->n-1]%2); 
    int prev = giantNum->array[0] >> 63, now;
    for(int i = 0; i < giantNum->n; i++){
        for(int t = 63; t >= 0; t--){
            now = (giantNum->array[i] >> t) & 1;
            ret += (prev != now);
            prev = now;
        }
    }
    return ret;
}