#include<stdio.h>

#define MY_CC 13
#define AVERAGE_CC 13.69

/*既然只會fold down，就把列編號反轉成 上n->下0，每次反轉後修改上界就好*/

int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    int arr[600][600] = {{0}};
    for(int index = 0; index < r*c; index++)
        scanf("%d", &arr[r-1-index/c][index%c]);

    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j < c; j++)
    //         printf("%d ", arr[i][j]);
    //     printf("\n");
    // }

    int type, k;
    while (scanf("%d%d", &type, &k) != EOF){
        //if(type == -1) break; /////////////////////////
        if(type == 1){ //fold down
            for(int i = 1; i <= k; i++){ //r-1 r-2 r-k || r-(k+1) r-(k+2) r-(2k)
                for(int j = 0; j < c; j++){
                    arr[r-(2*k+1-i)][j] += arr[r-i][j];
                }
            }
            r -= k;
        }
        if(type == 2){ //fold left
            for(int i = 0; i < r; i++){
                for(int j = 1; j <= k; j++){
                    arr[i][c-(2*k+1-j)] += arr[i][c-j];
                }
            }
            c -= k;
        }
        if(type == 3){ //fold diagonal
            for(int i = 0; i < k-1; i++){ 
                for(int j = 0; j < k-i-1; j++){
                    arr[r-k+i][c-k+j] += arr[r-1-j][c-1-i];
                    arr[r-1-j][c-1-i] = 0;
                }
            }
        }
    }

    for(int index = 0; index < r*c; index++){
        printf("%d ", arr[r-1-index/c][index%c]);
        if(index%c == c-1) printf("\n");
    }
}