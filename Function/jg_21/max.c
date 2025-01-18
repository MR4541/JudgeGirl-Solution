#include"max.h"
int max(int array[5][5]){
    int max = array[0][0];
    for(int i = 0; i < 25; i++)
        max -= (max-array[i/5][i%5])*(array[i/5][i%5] > max);
    return max;
}