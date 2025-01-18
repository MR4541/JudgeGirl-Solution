#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int tmp;
    int m0 = 0, m1 = 0, m2 = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        tmp = tmp%3;
        switch(tmp){
            case 0:
                m0++;
                break;
            case 1:
                m1++;
                break;
            case 2:
                m2++;
                break;
        }
    }
    printf("%d %d %d", m0, m1, m2);
}