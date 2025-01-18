#include<stdio.h>
#include<stdlib.h>

typedef struct Date{
    int y;
    char m, d; //要用char/short，不然就是malloc，不然記憶體不夠存100000*3int
}Date;

int compare(const void* a, const void* b){
    Date* da = (Date*)a;
    Date* db = (Date*)b;
    if(da->y != db->y) return da->y > db->y;
    if(da->m != db->m) return da->m > db->m;
    return da->d > db->d;
}

int main(void){
    int n;
    scanf("%d\n", &n);
    Date arr[1000000];
    for(int i = 0; i < n; i++) scanf("%d%d%d", &arr[i].y, &arr[i].m, &arr[i].d);
    qsort(arr, n, sizeof(Date), compare);
    for(int i = 0; i < n; i++) printf("%d %d %d\n", arr[i].y, arr[i].m, arr[i].d);
}