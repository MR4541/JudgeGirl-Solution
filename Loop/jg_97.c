#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int prk[n][3]; //存x, y, capacity; prk = parking
    int prked[n]; //每個地方停了幾輛車
    for(int i = 0; i < n; i++) prked[i] = 0;
    /*
    想法：每一輪就run一次找最小的，tmp紀錄當前選擇index, distance, minx, miny
    優先級：distance > minx > miny
    換句話說就是dist變大、minx變大、miny變大其中一個都直接continue
    停完bike把capacity-1
    */
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &prk[i][0], &prk[i][1], &prk[i][2]);
    }
    int m;
    scanf("%d", &m);
    int tmpx, tmpy, nowIndex = -1, nowDist, nowMinX, nowMinY, tmpDist, flag = 0;//flag = 1表示確定他是更好選擇
    for(int i = 0; i < m; i++){
        scanf("%d%d", &tmpx, &tmpy);
        for(int j = 0; j < n; j++){ //依次檢查第j個停車場
            if(prked[j]==prk[j][2]) continue; //已經停滿了，直接下一位

            if(nowIndex == -1){ //還沒有紀錄:直接登錄上去
                nowIndex = j; nowMinX = prk[j][0]; nowMinY = prk[j][1];
                nowDist = ((tmpx>prk[j][0])? tmpx-prk[j][0]:prk[j][0]-tmpx) + ((tmpy>prk[j][1])? tmpy-prk[j][1]:prk[j][1]-tmpy);
                continue;
            }
            tmpDist = ((tmpx>prk[j][0])? tmpx-prk[j][0]:prk[j][0]-tmpx) + ((tmpy>prk[j][1])? tmpy-prk[j][1]:prk[j][1]-tmpy);
            flag = 0; //確定他是否比當前更好
            if(tmpDist < nowDist){
                flag = 1; //比序1
            }else if(tmpDist == nowDist){
                if(prk[j][0] < nowMinX){
                    flag = 1; //比序2
                }else if(prk[j][0] == nowMinX){
                    if(prk[j][1] < nowMinY) flag = 1; //比序3
                }
            }
            //printf("%d\n", flag); ///////////////////////////////////
            if (flag){ //true才登錄上去
                //printf("index=%d, nowdist=%d, x %d-%d, y %d-%d\n%dth distance: %d\n",nowIndex,nowDist, tmpx,prk[j][0],tmpy,prk[j][1], j, tmpDist); /////
                nowIndex = j; nowMinX = prk[j][0]; nowMinY = prk[j][1];
                nowDist = tmpDist;
            }
        }
        prked[nowIndex]++;
        //printf("best parking: %d\n", nowIndex);/////
        nowIndex = -1; flag = 0; //初始化
        /*for(int k = 0; k < n; k++){ 
            printf("%d ",prked[k]);
        }printf("\n");*///
    }
    for(int k = 0; k < n; k++) {
        printf("%d\n", prked[k]);
    }
}