#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

void BubbleSort(uint64_t input, uint64_t output[63]){
    uint64_t now = input;
    uint64_t tmp;
    for(int i = 62; i >= 0; i--){
        for(int j = 62; j >= 62-i; j--){ //檢查63 62, 62 61, ..
            tmp = (now << 62-j) >> 62; //如果是2就要swap
            if(tmp == 2){
                now -= (uint64_t)1 << j;//減掉低位(i<<62)就swap好了
            }
        }
        output[62-i] = now;
    }
}

