#include<stdio.h>

int main(){
    int a, b;
    scanf("%d", &a);
    int f[a];
    for(int i = a-1; i >= 0; i--)
        scanf("%d", &f[i]);
    scanf("%d", &b);
    int g[b];
    for(int i = b-1; i >= 0; i--)
        scanf("%d", &g[i]);

    int fg[200] = {0};
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            fg[i+j] += f[i]*g[j];
        }
    }
    for(int i = a+b-2; i >= 0; i--){
        printf("%d", fg[i]);
        if(i == 0) printf("\n");
        else printf(" ");
    }
}