#include<stdio.h>
//#define DEBUG
/*
    開一個(D+2 * W+2)陣列，外圍一圈是「除2W+2D的餘數」編號2,3,4,...,2(W+D)-1,2(W+D),2(W+D)+1
    而內圈（範圍i=1-D, j=1-W）的0,1只會表示鏡子
    以單位向量開始走：
    1.遇到0繼續往前
    2.遇到1換方向
    3.遇到>1表示結束，輸出其值%2(W+D) (才能輸出0,1兩組)

    換方向(i, j)方法：
    (-1, 0) <-> (0, 1)
    (1, 0) <-> (0, -1)
    所以swap+變負號即可
*/
void printRes(int i, int j, int veci, int vecj, int iSize, int jSize, int cells[iSize][jSize]){
    /*起始點xy值, 起始xy方向向量, 矩陣大小, 矩陣
    一維陣列可以不用指定大小，其他都要
    單純陣列名即代表首元素的位址，所以呼叫時不用寫&cells
    */
    int tmp; //用來swap vecx,y
    
#ifdef DEBUG
    printf("%d goes to ", cells[i][j]);
#endif

    do{
        i += veci; j += vecj; //走路
        tmp =  veci;
        veci += -(veci+vecj)*(cells[i][j]); //cells = 1表示有鏡子，就改變方向
        vecj += -(vecj+tmp)*(cells[i][j]);
        
    } while (cells[i][j] <= 1); //要至少先走一步才能進入0,1區判斷

    printf("%d\n", cells[i][j]%(2*(iSize+jSize-4))); //==2w+2d
    return;
}


int main(){
    int w,d;
    scanf("%d%d", &w, &d);
    int cells[d+2][w+2];
    for(int i = 0; i <= d+1; i++)
        for(int j = 0; j <= w+1; j++){
            if (i == d+1) cells[i][j] = 2*(w+d)+j-1;
            else if (i == 0) cells[i][j] = 2*w+d-j;
            else if (j == w+1) cells[i][j] = w+d-i;
            else if (j == 0) cells[i][j] = 2*w+d+i-1;
            else scanf("%d", &cells[i][j]);
        }
    cells[0][0] = cells[d+1][0] = cells[0][w+1] = cells[d+1][w+1] = 0; //會由右至左兩個兩個執行（全部賦值為0）

#ifdef DEBUG
    for(int i = 0; i <= d+1; i++){
        for(int j = 0; j <= w+1; j++)
            printf("%3d ",cells[i][j]);
        printf("\n");
    }
#endif

    //處理完輸入了

    for(int j = 1; j <= w; j++)
        printRes(d+1, j, -1, 0, d+2, w+2, cells);

    for(int i = d; i >= 1; i--)
        printRes(i, w+1, 0, -1, d+2, w+2, cells);

    for(int j = w; j >= 1; j--)
        printRes(0, j, 1, 0, d+2, w+2, cells);

    for(int i = 1; i <= d; i++)
        printRes(i, 0, 0, 1, d+2, w+2, cells);
}