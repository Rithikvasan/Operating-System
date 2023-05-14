#include<stdio.h>

int main() {
    int n = 3, total_time = 0, total_waiting_time = 0, total_turnaround_time = 0;
    int arrival_time[] = {0, 0, 0};
    int burst_time[] = {2, 4, 8};
    int completion_time[] = {0, 0, 0};
    int waiting_time[] = {0, 0, 0};
    int turnaround_time[] = {0, 0, 0};

    printf("First Come First Serve (FCFS) Scheduling Algorithm Simulation\n\n");

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        completion_time[i] = total_time + burst_time[i];
        total_time += burst_time[i];
        waiting_time[i] = arrival_time[i] - 0;
        turnaround_time[i] = completion_time[i] - 0;
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, arrival_time[i], burst_time[i], completion_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);

    return 0;
}

