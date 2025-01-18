#include<stdio.h>

int findPath(int i, int j, int board[13][13]){
    if(i < 0 || j < 0 || board[i][j] == 0) return 0;
    if(i == 0 && j == 0) return 1;
    return findPath(i-1, j, board) + findPath(i, j-1, board);
}

int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    int board[13][13];
    for(int i = r-1; i >= 0; i--)
        for(int j = 0; j < c; j++)
            scanf("%d", &board[i][j]);
    printf("%d\n", findPath(r-1, c-1, board));
}