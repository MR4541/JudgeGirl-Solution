#include <stdio.h>

#define MAX(a, b) ((a) - ((a) - (b)) * ((a) < (b)))

int max(int *iptr[], int n){
    int ret = *iptr[0];
    for(int i = 1; i < n; i++){
        ret = MAX(ret, *iptr[i]);
    }
    return ret;
}

//////////////////////////////////////////////
// int main() {
//     int n, i;
//     int array[100];
//     int *iptr[100];
//     scanf("%d", &n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &(array[(i + 3) % n]));
//         iptr[i] = &(array[(i + 3) % n]);
//     }
//     printf("%d\n", max(iptr, n));
//     return 0;
// }