#include<stdio.h>
#include<stdlib.h>

int abs(int x) {
    return (x > 0) ? x : -x;
}

int main() {
    int n = 5, head = 50, total_movement = 0;
    int tracks[] = {55, 58, 60, 70, 18};

    printf("FCFS Disk Scheduling Algorithm Simulation\n\n");

    printf("Initial Head Position: %d\n", head);

    printf("Track\tDistance\tMovement\n");
    for(int i = 0; i < n; i++) {
        int distance = abs(head - tracks[i]);
        total_movement += distance;
        printf("%d\t%d\t\t%d\n", tracks[i], distance, total_movement);
        head = tracks[i];
    }

    printf("\nTotal Head Movement: %d\n", total_movement);
    printf("Average Head Movement: %.2f\n", (float)total_movement / n);

    return 0;
}

