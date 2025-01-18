#include <stdio.h>
#include "snake.h"

int main () {
    int n, m;
    scanf("%d%d", &n, &m);

    int grid[n][n];
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            grid[x][y] = 0;
        }
    }

    int* pointers[m];
    
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == -1 && y == -1) {
            pointers[i] = &(grid[n - 1][n - 1]) + 1;
        } else if (x == -2 && y == -2) {
            pointers[i] = NULL;
        } else {
            pointers[i] = &(grid[x][y]);
        }
    }

    snake(&(grid[0][0]), n, pointers, m);

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }
}