#include <stdio.h>

int main(){
    int W,L,w,l;
    scanf("%d%d%d%d", &L, &W, &l, &w);
    int wcnt = W / w;
    int lcnt = L / l;
    printf("%d\n%d\n", wcnt * lcnt, W*L - w*l*wcnt*lcnt);
}