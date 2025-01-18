#include<stdio.h>

void fill_array(int *ptr[], int n){
    //先把*ptr[i]指到的arr[j]都填上i
    for(int i = 0; i < n; i++) *ptr[i] = i;
    //bubble-sort ptr的位置（由小到大）
    int *tmp;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n-i-1; j++){
            if(ptr[j] > ptr[j+1]){ //swap
                tmp = ptr[j]; ptr[j] = ptr[j+1]; ptr[j+1] = tmp;
            }
        }
    //把兩兩被指向點區間的值填上
    for(int i = 0; i < n; i++){
        for(int j = 1; j < ptr[i+1]-ptr[i]; j++){ //1 ~ ptr[i+1]-ptr[i] - 1
            *(ptr[i] + j)   =   *ptr[i] + *ptr[i+1]; 
            //arr[index + j]
        }
    }
}

////////////////////////////////////////
// int main() {
//     int arr[100] = {    };
//     int *ptr[100];
//     int n = 6, m = 0;
//     int A[100] = {0, 5, 6, 9, 3, 12};
//     for (int i = 0; i < n; i++) {
//         ptr[i] = &arr[A[i]];
//         if (A[i] > m)    m = A[i];
//     }
//     fill_array(ptr, n);
//     for (int i = 0; i <= m; i++)
//         printf("%d%c", arr[i], " \n"[i==m]);
//     return 0;
// }