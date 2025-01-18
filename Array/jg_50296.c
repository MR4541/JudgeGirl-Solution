#include<stdio.h>

#define MY_CC 9
#define AVERAGE_CC 8.7
 
int main(){
    int n;
    scanf("%d", &n);
    int edge[600][600];//600防止溢出
    if(n == 1){/////////////////////////////////
        printf("1 0\n");
        return 0;
    }
    for(int i = 0; i < n*n; i++)
        scanf("%d", &edge[i/n][i%n]);
    //edge[i][j]表i到j權重
 
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         printf("%d ", edge[i][j]);
    //     }
    //     printf("\n");
    // }
 
    int min_dist = 1000000000, dist, min_index = 0;
    int visited[600] = {0}; //1表示到過
    int tmp_best_w, tmp_best_i,from,to; //from=v, to=w
    //以每一點為起點開始嘗試走路
    for(int i = 0; i < n; i++){
        for(int _ = 0; _ < n; _++){
            visited[_] = 0;
        }
        dist = 0;
        visited[i] = 1;
        from = i;
        for(int _ = 0; _ < n-1; _++){ //嘗試走，總共n-1步
            tmp_best_w = 1000000000; tmp_best_i = 0;
            for(to = 0; to<n; to++){
                if(to==from || visited[to]==1) continue;
                if(edge[from][to]<=tmp_best_w){
                    //因to遞增，若==必定是成立
                    tmp_best_w = edge[from][to];
                    tmp_best_i = to;
                }
            }
            //走路
            //printf("from %d to %d dist %d\n", from, tmp_best_i, tmp_best_w);
            visited[tmp_best_i] = 1;
            from = tmp_best_i;
            dist += tmp_best_w;
        }
        dist += edge[tmp_best_i][i];//vn-1到v0
        if(dist <= min_dist){ //相同則取起點index大
            min_dist = dist;
            min_index = i;
        }
        //printf("i=%d end. tolDist=%d\n", i, dist);
    }
    printf("%d %d\n", min_index+1, min_dist); //output 1-base
}