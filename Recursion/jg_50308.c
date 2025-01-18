#include<stdio.h>

#define MY_CC 11
#define AVERAGE_CC 14.313

typedef struct {
    int sh, sm; //start hour, minute
    int eh, em; //end
    int cap, day; //students enrolled, day of week
} Lecture;

int noOverlap(Lecture* a, Lecture* b) {
    if(a->day != b->day) return 1;
    int t1 = (a->eh*60 + a->em) - (b->sh*60 + b->sm);
    int t2 = (b->eh*60 + b->em) - (a->sh*60 + a->sm);
    return t1*t2 < 0;
}

//嘗試不放第index課、或把它放到可以放的所有教室，然後index++直到把所有課放完，並與當前max比較
void recur(int i, int n, Lecture* lec, int roomCap[8], int roomlec[8][40], int roomleccnt[8], int* max, int day, int daylec[6][10]) {
    if(i >= daylec[0][day]){ //calculate result and max()
        int tmpTime = 0;
        Lecture* lecptr;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < roomleccnt[a]; b++) {
                lecptr = &lec[roomlec[a][b]];
                tmpTime += (lecptr->eh - lecptr->sh)*60 + (lecptr->em - lecptr->sm) + 1;
            }
        }
        *max = (*max > tmpTime)? *max : tmpTime;
        return;
    }
    //嘗試把第i課不放or放到可以放的任何教室
    recur(i+1, n, lec, roomCap, roomlec, roomleccnt, max, day, daylec); //不放這門課
    for (int a = 0; a < n; a++) { //可以放就放
        if (roomCap[a] < lec[daylec[day][i]].cap) continue; //坐不下
        int conflictFlag = 0;
        for (int b = 0; b < roomleccnt[a]; b++) { //跟先前的課衝堂都不行放
            if (!noOverlap(&lec[daylec[day][i]], &lec[roomlec[a][b]])) {
                conflictFlag = 1;
                break;
            }
        }
        if(!conflictFlag){ //putLec , recursion, restore(deleteLec)
            roomlec[a][roomleccnt[a]] = daylec[day][i];
            roomleccnt[a]++;
            recur(i+1, n, lec, roomCap, roomlec, roomleccnt, max, day, daylec);
            roomleccnt[a]--; //不用去清roomlec[a][cnt+1]
            //因為到這邊又恢復了原狀，所以不用處理i會同時被塞到好幾間教室的問題
        }
    }
    return;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    char unused[100]; //課名、教室名根本用不到
    int roomCap[8];
    for(int i = 0; i < n; i++)
        scanf("%s%d", unused, &roomCap[i]);
    Lecture lec[40]; //5天＊8節課
    //把每天課分開處理
    int daylec[6][10] = {0}; //[0]存1~5各有多少課、[1]~[5]存每天的課
    for(int i = 0; i < m; i++){
        scanf("%s%d%d%d%d%d%d", unused, &lec[i].sh, &lec[i].sm, &lec[i].eh, &lec[i].em, &lec[i].cap, &lec[i].day);
        daylec[lec[i].day][daylec[0][lec[i].day]] = i;
        daylec[0][lec[i].day]++;
    }

    // printf("%d %d %d %d %d\n", daylec[0][1], daylec[0][2], daylec[0][3], daylec[0][4], daylec[0][5]);
    // for(int i = 1; i <= 5; i++){
    //     for(int j = 0; j < daylec[0][i]; j++){
    //         printf("%d ", daylec[i][j]);
    //     }
    //     printf("\n");
    // }

    int roomlec[8][40]; //存分配到課程的index
    int roomleccnt[8] = {0}; //每間教室已經有多少課了
    int max = 0, maxsum = 0;
    recur(0, n, lec, roomCap, roomlec, roomleccnt, &max, 1, daylec);
    // for(int i = 0; i < n; i++) printf("%d ", roomleccnt[i]);//////////////////////////////
    maxsum += max; max = 0;
    // printf("%d\n", maxsum);
    recur(0, n, lec, roomCap, roomlec, roomleccnt, &max, 2, daylec);
    // for(int i = 0; i < n; i++) printf("%d ", roomleccnt[i]);//////////////////////////////
    maxsum += max; max = 0;
    // printf("%d\n", maxsum);
    recur(0, n, lec, roomCap, roomlec, roomleccnt, &max, 3, daylec);
    // for(int i = 0; i < n; i++) printf("%d ", roomleccnt[i]);//////////////////////////////
    maxsum += max; max = 0;
    // printf("%d\n", maxsum);
    recur(0, n, lec, roomCap, roomlec, roomleccnt, &max, 4, daylec);
    // for(int i = 0; i < n; i++) printf("%d ", roomleccnt[i]);//////////////////////////////
    maxsum += max; max = 0;
    // printf("%d\n", maxsum);
    recur(0, n, lec, roomCap, roomlec, roomleccnt, &max, 5, daylec);
    // for(int i = 0; i < n; i++) printf("%d ", roomleccnt[i]);//////////////////////////////
    maxsum += max;
    printf("%d\n", maxsum);
}