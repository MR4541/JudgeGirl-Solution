#include<stdio.h>

#define MY_CC 5
#define AVERAGE_CC 12.625

//判斷移動合法性
int invalid(int i1, int j1, int i2, int j2){
    int di = i2 - i1, dj = j2 - j1;
    return (((di&&dj)&&(di!=dj&&di!=-dj)) || !(di||dj));
}

void snake(int* first_element, int n, int* pointers[], int m){
    //first_element = &arr[0][0]
    if(pointers[0] == NULL) return;
    int previ = (pointers[0]-first_element)/n, prevj = (pointers[0]-first_element)%n;
    int i, j;
    int di, dj; //走路用
    for(int _ = 1; _ < m; _++){
        //printf("dist %d i %d j %d\n", i, j, pointers[_]-first_element);///////////////////////////////////
        if(pointers[_]==NULL || (pointers[_]-first_element >= n*n || pointers[_]-first_element < 0)) return;
        i = (pointers[_]-first_element)/n;
        j = (pointers[_]-first_element)%n;
        if(invalid(previ, prevj, i, j)) return;
        di = -(previ>i)+(previ<i);
        dj = -(prevj>j)+(prevj<j); //決定移動方向
        //把經過的點踩成一
        for( ; previ!=i || prevj!=j; previ+=di, prevj+=dj){
            *(first_element + (previ*n + prevj)) = 1; //arr[i][j] = 1
        }
        *(first_element + (i*n + j)) = 1;
    }
}

//////////////////////////////////////
// int main () {
//     int n, m;
//     scanf("%d%d", &n, &m);
 
//     int grid[n][n];
//     for (int x = 0; x < n; x++) {
//         for (int y = 0; y < n; y++) {
//             grid[x][y] = 0;
//         }
//     }
 
//     int* pointers[m];
 
//     for (int i = 0; i < m; i++) {
//         int x, y;
//         scanf("%d%d", &x, &y);
//         if (x == -1 && y == -1) {
//             pointers[i] = &(grid[n - 1][n - 1]) + 1;
//         } else if (x == -2 && y == -2) {
//             pointers[i] = NULL;
//         } else {
//             pointers[i] = &(grid[x][y]);
//         }
//     }
 
//     snake(&(grid[0][0]), n, pointers, m);
 
//     for (int x = 0; x < n; x++) {
//         for (int y = 0; y < n; y++) {
//             printf("%d ", grid[x][y]);
//         }
//         printf("\n");
//     }
// }