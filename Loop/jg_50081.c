#include<stdio.h>

int main(){
    int X, Y;
    scanf("%d%d", &X, &Y);
    int ins, cho, x = 0, y = 0;
    printf("0\n0\n");
    while (scanf("%d", &ins) != EOF)
    {
        cho = ins % 5;
        switch (cho)
        {
        case 1:
            if(x+ins >= X) break;
            x += ins;
            printf("%d\n%d\n", x, y);
            break;
        case 2:
            if(x-ins < 0) break;
            x -= ins;
            printf("%d\n%d\n", x, y);
            break;
        case 3:
            if(y+ins >= Y) break;
            y += ins;
            printf("%d\n%d\n", x, y);
            break;
        case 4:
            if(y-ins < 0) break;
            y -= ins;
            printf("%d\n%d\n", x, y);
            break;
        }
    }
    
}