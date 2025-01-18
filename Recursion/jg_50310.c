#include<stdio.h>

typedef struct {
    int sh, sm; //start hour, minute
    int eh, em; //end
    int cap, day; //students enrolled, day of week
} Lecture;

//存解、比較用
typedef struct{
    int timesum;
    int lec_cnt;//存了幾堂課
    int lec_room_cnt[8];//每間教室存了幾堂
}Solution;

int timeLen(Lecture* a){
    return 60*(a->eh - a->sh) + a->em - a->sm + 1;
}

int noOverlap(Lecture* a, Lecture* b) {
    if(a->day != b->day) return 1;
    int t1 = (a->eh*60 + a->em) - (b->sh*60 + b->sm);
    int t2 = (b->eh*60 + b->em) - (a->sh*60 + a->sm);
    return t1*t2 < 0;
}

int firstBetter(Solution* now, Solution* max, int n){
    if(now->timesum > max->timesum) return 1;
    if(now->timesum < max->timesum) return 0;
    for(int i = 0; i < n; i++){
        if(now->lec_room_cnt[i] > max->lec_room_cnt[i]) return 1;
        if(now->lec_room_cnt[i] < max->lec_room_cnt[i]) return 0;
    }
    // printf("firstBetter() : compare no result!\n");
    return 0;
}

//嘗試不放第index課、或把它放到可以放的所有教室，然後index++直到把所有課放完，並與當前max比較
void recur(int i, int n, Lecture* lec, int roomCap[8], int roomlec[8][40], int roomleccnt[8], Solution* max, Solution* now, int day, int daylec[6][10], int remaintime[6][10]) {
    // printf("day %d nowtimesum %d\n", day, now->timesum);////////////////////
    if(now->timesum + remaintime[day][i] < max->timesum){
        // printf("Cut!\n");//////////////////////
        return; //cut
    }
    if(i >= daylec[0][day]){ //calculate result and max()
        if(firstBetter(now, max, n)) *max = *now; //update max
        return;
    }
    //嘗試把第i課不放or放到可以放的任何教室
    //try assign to each room
    int canputflag;
    int nowlec_i = daylec[day][i];
    for(int room = 0; room < n; room++){
        if(lec[nowlec_i].cap > roomCap[room]) continue;
        canputflag = 1;
        for(int j = 0; j < roomleccnt[room]; j++){
            if(!noOverlap(&lec[nowlec_i], &lec[roomlec[room][j]])){
                canputflag = 0;
                // printf("break\n");//////////////////////////
                break;
            }
        }
        if(canputflag){
            now->timesum += timeLen(&lec[nowlec_i]);
            now->lec_room_cnt[room]++;
            roomlec[room][roomleccnt[room]] = nowlec_i;
            roomleccnt[room]++;
            recur(i+1, n, lec, roomCap, roomlec, roomleccnt, max, now, day, daylec, remaintime);
            //restore
            now->timesum -= timeLen(&lec[nowlec_i]);
            now->lec_room_cnt[room]--;
            roomleccnt[room]--;
        }
    }
    //not assign to any
    recur(i+1, n, lec, roomCap, roomlec, roomleccnt, max, now, day, daylec, remaintime);    
    return;
}

void calremain(int daylec[6][10], int remaintime[6][10], Lecture* lec){
    int tmp;
    for(int day = 1; day <= 5; day++){
        tmp = 0;
        for(int i = daylec[0][day]-1; i >= 0; i--){
            tmp += timeLen(&lec[daylec[day][i]]);
            remaintime[day][i] = tmp;
        //     printf("tmp %d\n", tmp);///////////////////////////////
        }
    }
    return;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int roomCap[8];
    for(int i = 0; i < n; i++)
        scanf("%d", &roomCap[i]);
    Lecture lec[40]; //5天＊8節課
    //把每天課分開處理
    int daylec[6][10] = {0}; //[0]存1~5各有多少課、[1]~[5]存每天的課
    int remaintime[6][10] = {0}; //到day, i時，全取後面還有多少時長
    for(int i = 0; i < m; i++){
        scanf("%d%d%d%d%d%d", &lec[i].sh, &lec[i].sm, &lec[i].eh, &lec[i].em, &lec[i].cap, &lec[i].day);
        daylec[lec[i].day][daylec[0][lec[i].day]] = i;
        daylec[0][lec[i].day]++;
    }
    calremain(daylec, remaintime, lec);

    // for(int day = 1; day <= 5; day++){
    //     printf("Day %d: ", day);
    //     for(int i = 0; i < daylec[0][day]; i++) printf("(%d,%5d)", daylec[day][i], remaintime[day][i]);
    //     printf("\n");
    // }

    int roomlec[8][40]; //存分配到課程的index
    int roomleccnt[8] = {0}; //每間教室已經有多少課了
    Solution max = {0, 0 ,{0,0,0,0,0,0,0,0}}, tmp = {0, 0 ,{0,0,0,0,0,0,0,0}};
    recur(0, n, lec, roomCap, roomlec, roomleccnt, &max, &tmp, 1, daylec, remaintime);
    // for(int i = 0; i < n; i++) printf("%d ", roomleccnt[i]);//////////////////////////////
    tmp = max;
    // printf("%d\n", maxsum);
    recur(0, n, lec, roomCap, roomlec, roomleccnt, &max, &tmp, 2, daylec, remaintime);
    // for(int i = 0; i < n; i++) printf("%d ", roomleccnt[i]);//////////////////////////////
    tmp = max;
    // printf("%d\n", maxsum);
    recur(0, n, lec, roomCap, roomlec, roomleccnt, &max, &tmp, 3, daylec, remaintime);
    // for(int i = 0; i < n; i++) printf("%d ", roomleccnt[i]);//////////////////////////////
    tmp = max;
    // printf("%d\n", maxsum);
    recur(0, n, lec, roomCap, roomlec, roomleccnt, &max, &tmp, 4, daylec, remaintime);
    // for(int i = 0; i < n; i++) printf("%d ", roomleccnt[i]);//////////////////////////////
    tmp = max;
    // printf("%d\n", maxsum);
    recur(0, n, lec, roomCap, roomlec, roomleccnt, &max, &tmp, 5, daylec, remaintime);
    // for(int i = 0; i < n; i++) printf("%d ", roomleccnt[i]);//////////////////////////////
    printf("%d\n", max.timesum);
    for(int i = 0; i < n; i++) max.lec_cnt += max.lec_room_cnt[i];
    printf("%d\n", max.lec_cnt);
    for(int i = 0; i < n; i++) printf("%d\n", max.lec_room_cnt[i]);
}