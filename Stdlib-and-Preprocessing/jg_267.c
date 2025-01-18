#include<stdio.h>
#include<stdlib.h>

typedef struct dot{
    int x, y, dist;
}Dot;

#define MAXN 100000

int compare(const void* a, const void* b){
    Dot* p1 = (Dot*)a;
    Dot* p2 = (Dot*)b;
    if(p1->dist != p2->dist) return p1->dist > p2->dist;
    if(p1->x != p2->x) return p1->x > p2->x;
    return p1->y > p2->y;
}

int distance(Dot* a, Dot* b){
    return (a->x-b->x)*(a->x-b->x) + (a->y-b->y)*(a->y-b->y);
}

int main(){
    int n = 0;
    Dot p[MAXN];
    while(scanf("%d%d", &p[n].x, &p[n].y) != EOF){
        p[n].dist = p[n].x*p[n].x + p[n].y*p[n].y;
        n++;
    }
    qsort(p, n, sizeof(Dot), compare);

    int sum = p[0].dist;
    for(int i = 1; i < n; i++){
        sum += distance(p+i-1, p+i);
    }
    printf("%d\n", sum);
}