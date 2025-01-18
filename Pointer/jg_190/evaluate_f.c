#include<stdio.h>

int f(x, y){
    return 4*x - 6*y;
}

int evaluate_f(int *iptr[], int n, int *index){
    int maxF = f(*(iptr[0]), *(iptr[0]+1));
    *index = 0;
    //printf("%d %d\n", *(iptr[0]), *(iptr[0]+1));
    for(int i = 1; i < n; i++){
        if(maxF < f(*(iptr[i]), *(iptr[i]+1))){
            maxF = f(*(iptr[i]), *(iptr[i]+1));
            *index = i;
        }
    }
    return maxF;
}

//////////////////////////////////
// int main(){
//   int a[] = { 9, 7 };
//   int b[] = { 3, 2 };
//   int c[] = { 3, 2 };
//   int d[] = { 9, 7 };
//   int *iptr[] = { a, b, c, d };
//   int max, index;
//   max = evaluate_f(iptr, 4, &index);
//   printf("%d %d\n", max, index);
// }