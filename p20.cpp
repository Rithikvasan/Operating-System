#include <stdio.h>

int main() {
    int n = 6, m = 5, i, j, max, maxIndex;
    int partitions[] = {300, 600, 350, 200, 750, 125};
    int processes[] = {115, 500, 358, 200, 375};
    int allocation[m];
    for (i = 0; i < m; i++) {
        allocation[i] = -1;
    }

    for (i = 0; i < m; i++) {
        max = -1;
        maxIndex = -1;
        for (j = 0; j < n; j++) {
            if (partitions[j] >= processes[i] && partitions[j] > max) {
                max = partitions[j];
                maxIndex = j;
            }
        }
        if (maxIndex != -1) {
            allocation[i] = maxIndex;
            partitions[maxIndex] -= processes[i];
        }
    }

    printf("Process\tSize\tPartition\n");
    for (i = 0; i < m; i++) {
        printf("%d\t%d\t", i+1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i]+1);
        } else {
            printf("Not allocated\n");
        }
    }
    return 0;
}

