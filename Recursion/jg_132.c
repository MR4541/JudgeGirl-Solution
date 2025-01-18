#include<stdio.h>

//#define DEBUG

void Draw(int i, int N, int C, int adjMat[20][20], int colors[20], int* complete){ //return can draw or not
    // for(int _ = 0; _ < N; _++) printf("%d ", colors[_]);////////////////////////////////////////////////////////
    // printf("\n");//////////////////////////////
    if(*complete == 1) return;
    if(i == N){ //end
        for(int _ = 0; _ < N; _++) printf("%d\n", colors[_]);
        *complete = 1;

#ifdef DEBUG
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(adjMat[j][i] && colors[i]==colors[j])
                    printf("!!!! j %d i %d\n", j, i);
            }
        }
#endif

        return;
    }
    //把所有可以塗的都試試看
    int canDrawFlag;
    for(int color = 1; color <= C; color ++){
        canDrawFlag = 1;
        for(int u = 0; u < i; u++){
            if(adjMat[u][i] && color == colors[u]){ //u<i
                canDrawFlag = 0;
                break;
            }
        }
        if(canDrawFlag){
            colors[i] = color;
            Draw(i+1, N, C, adjMat, colors, complete);
            colors[i] = 0; //restore
        }
    }
}

int main(){
    int N, C, P;
    scanf("%d%d%d", &N, &C, &P);
    int adjMat[20][20] = {{0}}; //whether i is connect to j
    int u, v;
    for(int i = 0; i < P; i++){
        scanf("%d%d", &u, &v); 
        //make u < v
        if(u > v) u ^= v ^= u ^= v;
        adjMat[u][v] = 1; //另一邊用不到
    }
    
#ifdef DEBUG
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }
#endif
    
    int colors[20] = {0}; //0未塗色
    colors[0] = 1;
    int complete = 0; //has any ans?
    Draw(1, N, C, adjMat, colors, &complete);
    if(complete == 0){
        printf("no solution.\n");
    }


}