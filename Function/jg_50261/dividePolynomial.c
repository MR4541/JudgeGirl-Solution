#include<stdio.h>

#define MY_CC 5
#define AVERAGE_CC 6.5

//f[0]=n f[i]=x^(n+1-i)
void dividePolynomial(int f[], int g[]){
    int quo_n = f[0]-g[0]; //商式degree
    int q[2002]={0}; //商式（降冪）
    for(int i = 1; i <= quo_n+1; i++){
        q[i] = f[i] / g[1];
        for(int j = 1; j <= g[0]+1; j++){
            f[i+j-1] -= q[i]*g[j];
        }
    // for(int k = 1; k <= f[0]+1; k++) printf("%d ", f[k]);////////////////////////////////
    // printf("\n");
    }

    
    int rem_n = -1, flag = 0, cnt = 1; //遇到首個不為0,flag=1
    for(int i = quo_n+1; i <= f[0]+1; i++){ //把g = f(換成餘數)
        if(f[i]==0 && !flag) continue;
        flag = 1;
        //printf("f[i] i = %d f[i] = %d\n", i, f[i]); /////////////////
        g[cnt] = f[i];
        cnt++;
        rem_n += 1;
    }
    g[1] *= (rem_n!=-1); g[0] = rem_n*(rem_n!=-1); //若rem_n==-1則={0,0}

    f[0] = quo_n;
    for(int i = 1; i <= quo_n+1; i++){
        f[i] = q[i];
    }
    return;
}

/////////////////////////////////////

// void readPolynomial(int p[]) {
//     scanf("%d", &p[0]);
//     for (int i = 1; i<=p[0]+1; i++)
//         scanf("%d", &p[i]);
// }
 
// void printPolynomial(int p[]) {
//     for (int i = 0; i<=p[0]; i++)
//         printf("%d ", p[i]);
//     printf("%d", p[p[0]+1]);
// }
 
// int main() {
//     int n, f[2002], g[2002];
//     scanf("%d", &n);
//     while (n--) {
//         readPolynomial(f);
//         readPolynomial(g);
 
//         dividePolynomial(f, g);
 
//         printPolynomial(f);
//         printf("\n");
//         printPolynomial(g);
//         if (n) printf("\n");
//     }
//     return 0;
// }