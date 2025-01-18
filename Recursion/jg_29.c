#include<stdio.h>

int findPath(int i, int j){
    if(i < 0 || j < 0) return 0;
    if(i == 0 || j == 0) return 1;
    return findPath(i-1, j) + findPath(i, j-1);
}

int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    printf("%d\n", findPath(r-1, c-1));
}