#include<stdio.h>

void prepare_array(int buffer[], int *array[], int row, int column[]){
    int iSum = 0;
    for(int i = 0; i < row; i++){
        array[i] = &(buffer[iSum]);
        iSum += column[i];
    }
}

///////////////////////////////////////////
int main() {
    int row = 4;
    int column[4] = {10, 20, 30, 10};
    int *array[50];
    int buffer[10000];
    prepare_array(buffer, array, row, column);
    for (int i = 0; i < 4; i++)
     for (int j = 0; j < column[i]; j++)
       array[i][j] = i * 100 + j;
       //array[i]會跳到指定的buffer[index]，就可以實現攤平成一維功能
    return 0;
}