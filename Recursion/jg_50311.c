#include<stdio.h>

#define MY_CC 10
#define AVERAGE_CC 12


/*
每個教室附近至少一個助教 = 
助教可以顧到附近的教室 且 所有助教必須相連 （差想法） = 
每個助教可以顧到附近教室且顧不到自己的教室 （好想法）
*/

typedef struct {
    int cnt;
    unsigned agentPlace; // & 1 << i 表示i有放agent
}Solution;

int allCovered(int n, unsigned covered){
    return covered == (1u << (n+1)) - 2;
}

int firstBetter(Solution* now, Solution* best, int n){
    if(best->cnt == 0 || (best->cnt > now->cnt)) return 1;
    if((best->cnt < now->cnt)) return 0;
    for(int i = 1; i <= n; i++){
        if((now->agentPlace&(1u<<i)) == 1 && (best->agentPlace&(1u<<i)) == 0)
            return 1;
    }
    return 0;
}

// void printSol(int n, Solution* sol){
//     printf("cnt = %d, ", sol->cnt);
//     for(int i = 1; i <= n; i++)
//         if(sol->agentPlace & (1u<<i))
//             printf("%d ", i);
//     printf("\n");
// }

void solve(int i, int n, unsigned adjGraph[20], unsigned covered, Solution* now, Solution* best){
    // printf("i %d coverd %x\n", i, covered);
    if(allCovered(n, covered)){
        // printf("all coverd\n");
        // printf("best: "); printSol(n, best);
        // printf("now : "); printSol(n, now);
        if(firstBetter(now, best, n)){ //now is better
            *best = *now;
            // printf("best Updated\n");
        }
        return;
    }
    if(i>n) return;
    //先放再不放，一定會先搜到字典序最小的解
    unsigned new_covered = covered | adjGraph[i];
    now->agentPlace |= 1u << i; //add i
    now->cnt ++;
    solve(i+1, n, adjGraph, new_covered, now, best); //put at i
    now->agentPlace ^= 1u << i; //del i
    now->cnt --;
    solve(i+1, n, adjGraph, covered, now, best); //dont put at i
    return;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    unsigned adjGraph[20] = {0}; // & 1<<i 表示有沒有連到i
    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v); //1-base
        adjGraph[u] += 1u << v;
        adjGraph[v] += 1u << u;
    }

    // for(int i = 1; i <= n; i++){
    //     for(int test = 1; test <= n; test ++) printf("%d", (adjGraph[i]&(1u<<test)) != 0);
    //     printf("\n");
    // }

    unsigned covered = 0; //= 1 << (u+1) - 2表示all covered
    Solution now = {0, 0};
    Solution best = {0, 0};
    solve(1, n, adjGraph, covered, &now, &best);
    printf("%d\n", best.cnt);
    for(int i = 1; i <= n; i++){
        if(best.agentPlace & (1u<<i))
            printf("%d ", i);
    }
    printf("\n");
}