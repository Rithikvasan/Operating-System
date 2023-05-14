#include <stdio.h>
#include <stdlib.h>
int main()
{
    int partitions[6] = { 300, 600, 350, 200, 750, 125 };
    int processes[5] = { 115, 500, 358, 200, 375 };
    int n = 6, m = 5; 
    int allocation[m];

    for (int i = 0; i < m; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int best_idx = -1;
        for (int j = 0; j < n; j++) {
            if (partitions[j] >= processes[i]) {
                if (best_idx == -1) {
                    best_idx = j;
                } else if (partitions[j] < partitions[best_idx]) {
                    best_idx = j;
                }
            }
        }
        if (best_idx != -1) {
            allocation[i] = best_idx;
            partitions[best_idx] -= processes[i];
        }
    }
    printf("Process No.\tProcess Size\tPartition No.\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t\t%d\t\t", i+1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i]+1);
        } else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}

