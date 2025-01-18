#include <stdio.h>
#include <stdbool.h>
#include "lock.h"
 
int main(void){
    int m, n;
    scanf("%d%d", &m, &n);
    int lockSeq[100][3];
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &lockSeq[i][0], &lockSeq[i][1], &lockSeq[i][2]);
    }
    Locks* locks = init(lockSeq, n);
    int maxUnlocked = -1, maxI = -1;
    bool lights[20];
    for(int i = 0; i < (1<<m); i++){
        for(int j = 0; j < m; j++)
            lights[j] = (i & (1<<j)) != 0;
        int tmpUnlocked = numUnlocked(locks, lights, m);
        if(tmpUnlocked > maxUnlocked){
            maxUnlocked = tmpUnlocked;
            maxI = i;
        }
    }

    //print result
    for(int i = 0; i < m; i++)
        printf("%d", (maxI & (1<<i))!=0);
    printf("\n%d\n%d\n", maxUnlocked, maxI);
}

////////////////////////////////////////////////////////////////////////// 
// #define SENSORNUM 3
 
// int main() {
//   int m, n;
//   scanf("%d%d", &m, &n);
//   bool lights[m];
//   int lockSeq[n][SENSORNUM];
//   for(int i = 0; i < m; i++) {
//     int tmp;
//     scanf("%d", &tmp);
//     lights[i] = (tmp == 1);
//   }
//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < SENSORNUM; j++) {
//       scanf("%d", &lockSeq[i][j]);
//     }
//   }
//   Locks *locks = init(lockSeq, n);
//   printf("%d\n", numUnlocked(locks, lights, m));
//   return 0;
// }