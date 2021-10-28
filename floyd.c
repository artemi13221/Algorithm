#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int graph[][5] = {
        { 0, 1, 9999, 1, 5 },
        { 9, 0, 3, 2, 9999 },
        { 9999, 9999, 0, 4, 9999 },
        { 9999, 9999, 2, 0, 3 },
        { 3, 9999, 9999, 9999, 0 }
    };

    int i, j, k;
    int P[5][5] = { 0 };

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    P[i][j] = k;
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}