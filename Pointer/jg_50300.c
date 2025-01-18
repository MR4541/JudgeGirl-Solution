#include<stdio.h>
 
#define MY_CC 3
#define AVERAGE_CC 7.82

//使num1 < num2
void sort(int *num1, int *num2){
    int flag = *num1 > *num2;
    int tmp = *num1;
    *num1 -= (*num1 - *num2)*flag;
    *num2 -= (*num2 - tmp)*flag;
}
 
void paintOne(int *start, int x1, int y1, int z1, int x2, int y2, int z2,
    int W, int H){
 
    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++)
            for(int k = z1; k <= z2; k++)
                *(start + (i*W*H + j*H + k)) = 1;
    return;
}
 
//只塗外殼
void paintSurface(int *start, int *p1, int *p2, int L, int W, int H){
    int d1 = p1-start, d2 = p2-start;
    int x1 = d1/W/H, y1 = (d1%(W*H)/H), z1 = d1%H;
    int x2 = d2/W/H, y2 = (d2%(W*H)/H), z2 = d2%H;
    sort(&x1, &x2); sort(&y1, &y2); sort(&z1, &z2);
    //printf("p1(%d %d %d), p2(%d %d %d)\n", x1,y1,z1,x2,y2,z2);///////////
    //塗六個面
    paintOne(start, x1, y1, z1, x2, y2, z1, W, H);
    paintOne(start, x1, y1, z1, x2, y1, z2, W, H);
    paintOne(start, x1, y1, z1, x1, y2, z2, W, H);
    paintOne(start, x2, y1, z1, x2, y2, z2, W, H);
    paintOne(start, x1, y2, z1, x2, y2, z2, W, H);
    paintOne(start, x1, y1, z2, x2, y2, z2, W, H);
}
 
 
//////////////////////////////////////
// int main() {
//     int L, W, H;
//     scanf("%d%d%d", &L, &W, &H);
 
//     int cuboid[L][W][H];
//     for (int i = 0; i < L; i++) {
//         for (int j = 0; j < W; j++) {
//             for (int k = 0; k < H; k++) {
//                 cuboid[i][j][k] = 0;
//             }
//         }
//     }
 
//     int n;
//     scanf("%d", &n);
 
//     while (n--) {
//         int x1, x2, y1, y2, z1, z2;
//         scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
//         paintSurface(&cuboid[0][0][0], &cuboid[x1][y1][z1], &cuboid[x2][y2][z2], L, W, H);
//     }
 
//     for (int i = 0; i < L; i++) {
//         for (int j = 0; j < W; j++) {
//             for (int k = 0; k < H; k++) {
//                 printf("%d", cuboid[i][j][k]);
//             }
//             printf("\n");
//         }
//         printf("\n");
//     }
 
//     return 0;
// }