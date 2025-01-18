#include<stdio.h>
//謝黃崇睿

#define MAX_M 256

int main(){
    int n, m; //玩家數、賓果大小
    scanf("%d%d", &n, &m);
    int board[10][MAX_M*MAX_M]; //m<=256  n<=10 ///////太大導致本地跑不了
    //例如m=10, num5在(2,3) => board[i][5] = 23
    //取出num k位址: (x,y) = (board[i][k]/m, board[i][k]%m)
    char name[10][64]; //length of name <= 64
    int row[10][MAX_M] = {{0}}; //存同一張圖第m行已經有幾個數字被劃
    int column[10][MAX_M] = {{0}}; //如果=m就表示連線成功
    int dia1[10] = {0}, dia2[10]= {0}; //對角線x=y, x+y=m-1 
    //input
    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%s", name[i]);
        for(int k = 0; k < m*m; k++){
            scanf("%d", &tmp);
            board[i][tmp] = k; //數字m在位置k
        }
    }

    int num;//賓果數字
    int flag = 0; //當回合有人true就改成1，然後return 0
    int tmpx, tmpy; //num的位置
    for(int _ = 0; _ < m*m && flag == 0; _++){ //最多會有m*m個數
        scanf("%d", &num);
        for(int i = 0; i < n; i++){
            tmpx = board[i][num]/m;
            tmpy = board[i][num]%m;
            row[i][tmpy]++;
            column[i][tmpx]++;
            if(tmpx == tmpy) dia1[i]++;
            if(tmpx + tmpy == m-1) dia2[i]++;
            if((row[i][tmpy]==m || column[i][tmpx]==m) || (dia1[i]==m || dia2[i]==m)){
                //連線成功
                if(flag == 0) printf("%d ", num); //首個人
                else printf(" "); //後面的只要跟前面隔開
                printf("%s", name[i]);
                flag = 1;
            }
        }
    }
    printf("\n");

}