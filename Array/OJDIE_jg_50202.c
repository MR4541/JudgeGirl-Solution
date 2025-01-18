#include<stdio.h>

#define MY_CC 4
#define AVERAGE_CC 7.93

#define MLE OJ判定問題，all testdata is AC（90%MLE，且花費記憶體數小於前二十用戶）

#define MAX(a, b) ((a) - ((a) - (b)) * ((a) < (b)))

int main(){
    int h, w, k;
    scanf("%d%d%d", &h, &w, &k);
    int arr[h][w];
    for(int index = 0; index < h*w; index++)
        scanf("%d", &arr[index/w][index%w]);

    int maxsum = 0;
    int dj, tmpsum;//壓memory
    //中心範圍為：i=k-1 ~ h-k, j=k-1 ~ w-k
    for(int i = k-1; i <= h-k; i++){
        for(int j = k-1; j <= w-k; j++){
            //計算總和
            tmpsum = arr[i][j-k+1]+arr[i][j+k-1];//四個尖角只會算到一次
            tmpsum += arr[i-k+1][j]+arr[i+k-1][j];
            //printf("i:%d, %d | j:%d, %d\n", i-k+1, i+k-1, j-k+1, j+k-1);////////////////////////////////
            //printf("%d\n", tmpsum);///////////////////////////////////////////
            for(int di = 1; di <= k-2; di++){ //di=1~k-2
                dj = k-1-di;
                tmpsum += arr[i+di][j+dj] + arr[i+di][j-dj];
                tmpsum += arr[i-di][j+dj] + arr[i-di][j-dj];
                //printf("i %d di %d j %d dj %d\n", i,di,j,k-1-di);///////////////////////////    
            }
            maxsum = MAX(maxsum, tmpsum);
        }
    }
    printf("%d\n", maxsum);
}