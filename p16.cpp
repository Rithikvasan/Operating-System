#include <stdio.h>
float findAvgWaitingTime(int n, int bt[])
{
    int wt[n], i;
    float avg_wt = 0;

    wt[0] = 0;

    for (i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }


    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
    }
    avg_wt /= n;

    return avg_wt;
}

// Function to calculate average turnaround time
float findAvgTurnaroundTime(int n, int bt[])
{
    int wt[n], tat[n], i;
    float avg_tat = 0;

    wt[0] = 0;

    for (i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    for (i = 0; i < n; i++) {
        avg_tat += tat[i];
    }
    avg_tat /= n;

    return avg_tat;
}
int main()
{
    int n = 3;
    int burst_time[] = {10, 15, 25};

    float avg_waiting_time = findAvgWaitingTime(n, burst_time);
    float avg_turnaround_time = findAvgTurnaroundTime(n, burst_time);

    printf("Average Waiting Time = %0.2f\n", avg_waiting_time);
    printf("Average Turnaround Time = %0.2f\n", avg_turnaround_time);

    return 0;
}


