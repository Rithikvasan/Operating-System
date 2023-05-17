#include <stdio.h>

#define MAX_PARTITIONS 5

// Structure to represent a memory partition
struct Partition {
    int id;
    int size;
    int allocated;
};

// Function to allocate memory using the first-fit algorithm
void firstFit(struct Partition partitions[], int numPartitions, int processSize) {
    int i, j;
    for (i = 0; i < numPartitions; i++) {
        if (!partitions[i].allocated && partitions[i].size >= processSize) {
            // Allocate memory for the process
            partitions[i].allocated = 1;
            printf("Process of size %d KB allocated to Partition %d\n", processSize, partitions[i].id);
            return;
        }
    }
    // If no suitable partition found
    printf("Process of size %d KB cannot be allocated\n", processSize);
}

int main() {
    struct Partition partitions[MAX_PARTITIONS] = {
        {1, 40, 0},
        {2, 10, 0},
        {3, 30, 0},
        {4, 60, 0},
    };
    int numPartitions = 4;

    int processSizes[] = {100, 50, 30, 120, 35};
    int numProcesses = sizeof(processSizes) / sizeof(processSizes[0]);

    printf("Initial Memory Partitions:\n");
    printf("---------------------------\n");
    for (int i = 0; i < numPartitions; i++) {
        printf("Partition %d: %d KB\n", partitions[i].id, partitions[i].size);
    }
    printf("\n");

    printf("Memory Allocation:\n");
    printf("------------------\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d: %d KB\n", i+1, processSizes[i]);
        firstFit(partitions, numPartitions, processSizes[i]);
    }
    printf("\n");

    printf("Final Memory Partitions:\n");
    printf("-------------------------\n");
    for (int i = 0; i < numPartitions; i++) {
        printf("Partition %d: %d KB\n", partitions[i].id, partitions[i].size);
    }

    return 0;
}

