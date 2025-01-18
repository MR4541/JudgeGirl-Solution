#include <stdio.h>
#include <assert.h>

#define MY_CC 1
#define AVERAGE_CC 3.11

#define MAX 500 //500會爆

/*等於翻轉+翻行
j = i
i = j1-1-n
*/

void rotate(int *P[MAX][MAX], int n){
    int i, j;
    int *beginArr = P[0][0];
    for(int index = 0; index < n*n; index++){
        i = index/n; j = index%n;
        P[i][j] = beginArr + ((n-1-j)*MAX + i);
    }
}

// ////////////////////////////////////////////// 
// int main() {
//     int array[MAX][MAX], check[MAX][MAX];
//     int *P[MAX][MAX];
 
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i<n; i++) {
//         for (int j = 0; j<n; j++) {
//             P[i][j] = &array[i][j];
//             scanf("%d", &array[i][j]);
//             check[i][j] = array[i][j];
//         }
//     }
 
//     rotate(P, n);
 
//     for (int i = 0; i<n; i++) {
//         for (int j = 0; j<n; j++) {
//             assert(check[i][j] == array[i][j]);
//             printf("%d ", *(P[i][j]));
//         }
//         printf("\n");
//     }
 
//     return 0;
// }