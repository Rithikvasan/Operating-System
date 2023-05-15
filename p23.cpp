#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5, i, j, pos = 50, diff, sum = 0;
    int tracks[] = {55, 58, 60, 70, 18};
    int visited[n], order[n];
    //initialize visited array to 0
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    //sort the tracks in ascending order
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (tracks[j] > tracks[j+1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j+1];
                tracks[j+1] = temp;
            }
        }
    }
    //find the index of the track that is closest to the current position
    for (i = 0; i < n; i++) {
        if (tracks[i] > pos) {
            diff = i;
            break;
        }
    }
    //add tracks to the order array in the appropriate order
    j = 0;
    for (i = diff; i < n; i++) {
        order[j++] = tracks[i];
        visited[i] = 1;
    }
    for (i = diff-1; i >= 0; i--) {
        order[j++] = tracks[i];
        visited[i] = 1;
    }
    //calculate the total head movement
    for (i = 0; i < n-1; i++) {
        sum += abs(order[i] - order[i+1]);
    }
    //print the order of the tracks and the average head movement
    printf("Order of tracks: ");
    for (i = 0; i < n; i++) {
        printf("%d ", order[i]);
    }
    printf("\nAverage head movement: %.2f\n", (float)sum/n);
    return 0;
}

