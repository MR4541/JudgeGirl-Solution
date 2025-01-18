#include<stdio.h>

const int dx[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
const int dy[] = {0, -1, 1, 0, 1, -1, 0, 1, -1};

int check(int board[11][11]){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(board[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

//如果board 1,1 到 i-2, 9及 i-1, 1~j-2有不是0的，表示前面配置一定錯，剪枝
int cutcheck(int i, int j, int board[11][11]){
    for(int a = 1; a <= i-2; a++){
        for(int b = 1; b <= 9; b++){
            if(board[a][b] != 0) return 1; //board!=0
        }
    }
    for(int b = 1; b <= j-2; b++)
        if(i >= 2 && board[i-1][b] != 0) return 1;/////////////
    return 0;
}

void putmine(int a, int b, int board[11][11]){
    for(int i = 0; i < 9; i++)
        board[a+dx[i]][b+dy[i]] --; 
}

void rmvmine(int a, int b, int board[11][11]){
    for(int i = 0; i < 9; i++)
        board[a+dx[i]][b+dy[i]] ++; 
}

//由1,1嘗試到9,9
void try(int i, int j, int board[11][11], int mine[11][11], int* compflag){
    // printf("i %d j %d cutcheck %d | ", i, j, cutcheck(i, j, board));////////////
    if(*compflag == 1 || cutcheck(i, j, board)) return;
    if(check(board)){
        for(int a = 1; a <= 9; a++){
            for(int b = 1; b <= 8; b++){
                printf("%d ", mine[a][b]);
            }
            printf("%d\n", mine[a][9]);
        }
        *compflag = 1;
        return;
    }
    if(i == 10) return;
    int nexti = (j == 9)? i+1 : i;
    int nextj = (j == 9)? 1 : j+1;
    try(nexti, nextj, board, mine, compflag);
    mine[i][j] = 1;
    putmine(i, j, board);

    // if(i == 9 && j == 9){
    //     for(int a = 1; a <= 9; a++){
    //         for(int b = 1; b <= 9; b++)
    //             printf("%d ", board[a][b]);
    //         printf("\n");
    //     }
    // }

    try(nexti, nextj, board, mine, compflag);
    mine[i][j] = 0;
    rmvmine(i, j, board);
    return;
}

int main(){
    int board[11][11] = {{0}};
    int mine[11][11] = {{0}};
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
            scanf("%d", &board[i][j]);
    int compflag = 0;
    try(1, 1, board, mine, &compflag);
    if(compflag == 0)
        printf("no solution\n");
}