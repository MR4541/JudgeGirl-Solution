#include <stdio.h>

int main(){
    int n, i;
    scanf("%d%d", &n, &i);
    int ans;
    switch (i)
    {
    case 1:
        ans = n;
        break;
    case 2:
        ans = n*n;
        break;
    case 3:
        ans = n*n*n;
        break;
    case 4:
        ans = n*n*n*n;
        break;
    case 5:
        ans = n*n*n*n*n;
        break;
    default:
        printf("error!");
        return 0;
    }
    printf("%d\n", ans);
}