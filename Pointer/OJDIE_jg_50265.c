#include<stdio.h>

#define MLE OJ判定問題，all testdata is AC

#define MY_CC 1
#define AVERAGE_CC 1.5

//#define MAXM 200 //200本地會爆

int calRectArea(int N, int M, int* ptrMat, int* ptrLeft[], int* ptrRight[]){
    int pl = ptrLeft[0]-ptrMat;
    int pr = ptrRight[0]-ptrMat;
    int x1 = pl/N, y1 = pl%N;
    int x2 = pr/N, y2 = pr%N;
    int prevx2 = x2, prevy2 = y2;
    int area = (x2-x1+1)*(y2-y1+1);
    for(int i = 1; i < M; i++){
        pl = ptrLeft[i]-ptrMat;
        pr = ptrRight[i]-ptrMat;
        x1 = pl/N, y1 = pl%N;
        x2 = pr/N, y2 = pr%N;
        area += (x2-x1+1)*(y2-y1+1);
        area -= (prevx2-x1+1)*(prevy2-y1+1);
        prevx2 = x2, prevy2 = y2;
    } 
    return area;
}

/////////////////////////////////////
// int main() {
//     int N, M;
//     scanf("%d%d", &N, &M);
 
//     int *ptrMatrix;
//     int matrix[N][N];
//     int *ptrLeft[MAXM];
//     int *ptrRight[MAXM];
//     int x, y, w, h;
 
//     ptrMatrix = &matrix[0][0];
//     for (int i = 0; i < M; i++) {
//         scanf("%d%d%d%d", &x, &y, &w, &h);
//         ptrLeft[i] = &matrix[x][y];
//         ptrRight[i] = &matrix[x + w - 1][y + h - 1];
//     }
//     int area = calRectArea(N, M, ptrMatrix, ptrLeft, ptrRight);
//     printf("%d\n", area);
// }