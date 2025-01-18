#include <stdio.h>
#include <assert.h>
 
void snake(const int *ptr_array[100][100], int m){
    //先計算出index（蛇形）對應的i,j，然後bubble sort
    int i1, j1, i2, j2;
    int *tmp;
    for(int i = 0; i < m*m-1; i++)
        for(int index = 0; index < m*m - i - 1; index++){
            i1 = index/m; i2 = (index+1)/m; //列數
            j1 = index%m + (i1&1)*(m-1-2*(index%m));
            j2 = (index+1)%m + (i2&1)*(m-1-2*((index+1)%m));
            //i1&1 等價於 i1%2 == 1
            //i1奇數：倒著數回來

            //printf("%d %d, %d %d\n", i1,j1,i2,j2);

            //swap
            if(*ptr_array[i1][j1] > *ptr_array[i2][j2]){
                //printf("SWAP %d, %d\n", *ptr_array[i1][j1], *ptr_array[i2][j2]);
                tmp = ptr_array[i1][j1];
                ptr_array[i1][j1] = ptr_array[i2][j2];
                ptr_array[i2][j2] = tmp;
            }
        }
}

/////////////////////////////////////////////////////////
// int main()
// {
//   int array[100][100], check[100][100];
//   const int *ptr_array[100][100];
//   int i, j, m;
 
//   scanf("%d", &m);
//   for (i = 0; i < m; i++)
//     for (j = 0; j < m; j++) {
//       ptr_array[i][j] = &(array[i][j]);
//       scanf("%d", &(array[i][j]));
//       check[i][j] = array[i][j];
//     }
 
//   snake(ptr_array, m);
 
//   for (i = 0; i < m; i++) {
//     for (j = 0; j < m; j++) {
//       assert(check[i][j] == array[i][j]);
//       assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
//       printf("%d ", *(ptr_array[i][j]));
//     }
//     printf("\n");
//   }
 
//   return 0;
// }