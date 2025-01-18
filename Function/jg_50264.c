#include<stdio.h>

#define MY_CC 7
#define AVERAGE_CC 9.9

#define MAXNM 200 //200本地會爆

int OutShadow(int px, int py, int x, int y, int L, int W){
    return (px<x||px>=x+L)||(py<y||py>=y+W);
}

void PrintEclipse(int N, int M, int sun[MAXNM][MAXNM], int x, int y, int L, int W){
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            printf("%d ", sun[i][j]*OutShadow(i,j,x,y,L,W));
        }
        printf("\n");
    }
}

int main(void){
    int N,M,L,W;
    scanf("%d%d%d%d",&N,&M,&L,&W);
    int x,y, s,k; //init shadow, step len/num
    scanf("%d%d%d%d", &y,&x,&s,&k); //y水平向
    int sun[MAXNM][MAXNM];
    for(int index = 0; index < N*M; index++)
        scanf("%d", &sun[N-1-index/M][index%M]);
    
    //shadow是否有遮擋到sun
    int flag=(x<=N-1&&y<=M-1) && (x+L-1>=0&&y+W-1>=0); 
    int keepflag = 1;

    if(flag){
        PrintEclipse(N,M,sun,x,y,L,W);
        keepflag = 0;
    }
    for(int _ = 0; _ < k && (flag || keepflag); _++){
        x-=s; y-=s;
        flag=(x<=N-1&&y<=M-1) && (x+L-1>=0&&y+W-1>=0);
        if(flag){
        //printf("Here\n");
            if(!keepflag) printf("\n"); //第一次觸發不印
            PrintEclipse(N,M,sun,x,y,L,W);
            keepflag = 0; //一旦flag觸發一次，只要之後沒有觸發flag就會斷掉for
        }
    }
}