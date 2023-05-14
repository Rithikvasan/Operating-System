#include<stdio.h>

#define N 5
#define M 3

int main() {
    int allocation[N][M] = {
        {1, 1, 2},
        {2, 1, 2},
        {3, 0, 1},
        {0, 2, 0},
        {1, 1, 2},
    };
    int max[N][M] = {
        {5, 4, 4},
        {4, 3, 3},
        {9, 1, 3},
        {8, 6, 4},
        {2, 2, 3},
    };
    int available[M] = {3, 2, 1};
    int need[N][M];

    printf("Process\tAllocation\tMax\tAvailable\tNeed\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%c%d\t%d\t\t%d\t\t", 'P', i, allocation[i][j], max[i][j]);
        }
        printf("%d\t%d\t%d\n", available[0], available[1], available[2]);
        printf("\t\t\t\t\t\t\t\t%d\t%d\t%d\n", need[i][0], need[i][1], need[i][2]);
    }

    return 0;
}

