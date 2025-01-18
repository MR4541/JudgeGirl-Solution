#include<stdio.h>

#define MY_CC 4
#define AVERAGE_CC 12.29

int main(){
    int r, c;
    int arr[502][502] = {{0}}; //輸入1-base
    scanf("%d%d", &r, &c);
    for(int i = 0; i < r*c; i++){
        scanf("%d", &arr[i/c + 1][i%c + 1]);
    }

    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j < c; j++)
    //         printf("%d ", arr[i][j]);
    //     printf("\n");
    // }

    int i, j; //邪惡壓CC
    int delflag; //是否要消除
    for(int index = 0; index < r*c; index++){
        i = index/c + 1; j = index%c + 1;
        delflag = (arr[i][j]==arr[i-1][j] && arr[i][j]==arr[i+1][j]); //直行
        arr[i][j]*=!delflag; arr[i-1][j]*=!delflag; arr[i+1][j]*=!delflag;
        delflag = (arr[i][j]==arr[i][j-1] && arr[i][j]==arr[i][j+1]); //橫行
        arr[i][j]*=!delflag; arr[i][j-1]*=!delflag; arr[i][j+1]*=!delflag;
        delflag = (arr[i][j]==arr[i-1][j] && arr[i][j]==arr[i][j-1]); //L1
        arr[i][j]*=!delflag; arr[i-1][j]*=!delflag; arr[i][j-1]*=!delflag;
        delflag = (arr[i][j]==arr[i-1][j] && arr[i][j]==arr[i][j+1]); //L2
        arr[i][j]*=!delflag; arr[i-1][j]*=!delflag; arr[i][j+1]*=!delflag;
        delflag = (arr[i][j]==arr[i+1][j] && arr[i][j]==arr[i][j-1]); //L3
        arr[i][j]*=!delflag; arr[i+1][j]*=!delflag; arr[i][j-1]*=!delflag;
        delflag = (arr[i][j]==arr[i+1][j] && arr[i][j]==arr[i][j+1]); //L4
        arr[i][j]*=!delflag; arr[i+1][j]*=!delflag; arr[i][j+1]*=!delflag;
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}