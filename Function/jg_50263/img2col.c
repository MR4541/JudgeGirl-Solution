#include<stdio.h>

#define MAXH 100 //.h裡面有還是要define
#define MAXW 100
#define MAXK 10

#define MY_CC 3
#define AVERAGE_CC 3.8

void img2col(int h, int w, int k, int imgMatrix[MAXH][MAXW], int colMatrix[MAXK * MAXK][MAXW * MAXH]){
    int jsize = w-k+1, isize = h-k+1;
    for(int i = 0; i < isize; i++){
        for(int j = 0; j < jsize; j++){
            for(int index = 0; index < k*k; index++)
                colMatrix[index][j+jsize*i] = imgMatrix[i+index/k][j+index%k];
        }
    }
    return;
}

//////////////////////////////
// int main() {
//     int imgHeight, imgWidth;
//     int colHeight, colWidth;
//     int windowSize;
//     int imgMat[MAXH][MAXW];
//     int colMat[MAXK * MAXK][MAXW * MAXH];
 
//     scanf("%d%d", &imgHeight, &imgWidth);
//     scanf("%d", &windowSize);
 
//     colHeight = windowSize * windowSize;
//     colWidth = (imgWidth - windowSize + 1) * (imgHeight - windowSize + 1);
 
//     for (int i = 0; i < imgHeight; i++)
//         for (int j = 0; j < imgWidth; j++)
//             scanf("%d", &imgMat[i][j]);
 
//     img2col(imgHeight, imgWidth, windowSize, imgMat, colMat);
 
//     for (int i = 0; i < colHeight; i++) {
//         for (int j = 0; j < colWidth; j++)
//             printf("%d ", colMat[i][j]);
//         printf("\n");
//     }
// }