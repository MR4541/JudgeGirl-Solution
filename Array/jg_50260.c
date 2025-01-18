#include<stdio.h>
#include<stdlib.h>

#define MY_CC 4
#define AVERAGE_CC 14.4

#define MAX(a, b) ((a) - ((a) - (b)) * ((a) < (b)))

int Check(int n, int grid[n][n], int x, int y, int dx, int dy){
    int ret = 0;
    while (((x>=0&&y>=0) && (x<n&&y<n)) && grid[x][y] == 1)
    {
        ret++;
        x+=dx;
        y+=dy;
    }
    return ret;
    
}

int MinToMax(const void* a, const void* b){
    return (((int*)a)[0] > ((int*)b)[0] || ( ((int*)a)[0] == ((int*)b)[0] && ((int*)a)[1] > ((int*)b)[1]));
}

//題目圖的方向代號跟範例相反
int main(){
    int n;
    scanf("%d", &n);
    int grid[n][n];
    for(int i = 0; i < n*n; i++) //偷壓
        scanf("%d", &grid[i/n][i%n]);
    
    // for(int i= 0; i<n;i++){
    //     for(int j=0;j<n;j++)
    //         printf("%d ", grid[i][j]);
    //     printf("\n");
    // }

    int m;
    scanf("%d", &m);
    int center[m][2];
    int plusx, plusy, minusx, minusy; //臂長
    int orien; //方向
    // -x+y -x-y +x-y +x+y 
    // 0    1    2    3     
    for(int i = 0; i < m; i++){
        scanf("%d%d", &center[i][0], &center[i][1]);
    }
    qsort(center, m, 2*sizeof(int), MinToMax);
    for(int i = 0; i < m; i++){
        plusx = Check(n, grid, center[i][0], center[i][1], 1, 0);
        minusx = Check(n, grid, center[i][0], center[i][1], -1, 0);
        plusy = Check(n, grid, center[i][0], center[i][1], 0, 1);
        minusy = Check(n, grid, center[i][0], center[i][1], 0, -1);
        orien = 2*(plusx > 1) + (minusy*minusx == 1) + (plusx*plusy == 1);
        printf("%d %d %d\n", orien, MAX(plusx, minusx), MAX(plusy, minusy)); //vertical是x
        //printf("+y %d -y %d +x %d -x %d\n", plusy, minusy, plusx, minusx);////////////////////
    }
}