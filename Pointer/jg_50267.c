#include <stdio.h>

#define MY_CC 3
#define AVERAGE_CC 3.56

int hash(int x, int a, int b, int c){
    return (a*x + b)%c;
}

void count_collision(int *ptr[], int A[], int n, int a, int b, int c){
    for(int i = 0; i < c; i++)
        A[i] = 0;
    for(int i = 0; i < n; i++){
        //printf("hash(%d) = %d, ", i, hash(i,a,b,c));////////////////////////
        ptr[i] = A + hash(i, a, b, c);
        *(ptr[i]) += 1; //A[hash]++
        //printf("index of A: %d\n", ptr[i] - A);///////////////
    }
    //最後要把A每個元素-1，才是collision而非指到次數
    for(int i = 0; i < c; i++)
        A[i] -= (A[i]!=0);
}

// // ///////////////////////////////////
// int main()
// {
//     int n;
//     int a, b, c;
//     scanf("%d", &n);
//     scanf("%d%d%d", &a, &b, &c);
 
//     int *ptr[n];
//     int A[c];
 
//     count_collision(ptr, A, n, a, b, c);
 
//     for(int i = 0; i < c; i++) printf("%d ", A[i]);
//     printf("\n");
//     for(int i = 0; i < n; i++) printf("%d ", ptr[i] - A);
 
//     return 0;   
// }