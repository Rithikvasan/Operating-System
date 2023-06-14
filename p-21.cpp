#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (philosopher_number + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS
#define RIGHT (philosopher_number + 1) % NUM_PHILOSOPHERS

pthread_mutex_t mutex;
pthread_cond_t condition[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];

void test(int philosopher_number) {
    if (state[philosopher_number] == HUNGRY &&
        state[LEFT] != EATING &&
        state[RIGHT] != EATING) {
        state[philosopher_number] = EATING;
        sleep(2); // Simulate eating
        printf("Philosopher %d is now eating.\n", philosopher_number);
        pthread_cond_signal(&condition[philosopher_number]);
    }
}

void take_forks(int philosopher_number) {
    pthread_mutex_lock(&mutex);
    state[philosopher_number] = HUNGRY;
    printf("Philosopher %d is now hungry.\n", philosopher_number);
    test(philosopher_number);
    while (state[philosopher_number] != EATING) {
        pthread_cond_wait(&condition[philosopher_number], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}

void put_forks(int philosopher_number) {
    pthread_mutex_lock(&mutex);
    state[philosopher_number] = THINKING;
    printf("Philosopher %d is now thinking.\n", philosopher_number);
    test(LEFT);
    test(RIGHT);
    pthread_mutex_unlock(&mutex);
}

void* philosopher(void* arg) {
    int philosopher_number = *(int*)arg;

    while (1) {
        // Simulate thinking
        sleep(rand() % 3 + 1);

        take_forks(philosopher_number);

        // Simulate eating
        sleep(rand() % 3 + 1);

        put_forks(philosopher_number);
    }
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_numbers[NUM_PHILOSOPHERS];

    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_cond_init(&condition[i], NULL);
        philosopher_numbers[i] = i;
        state[i] = THINKING;
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_numbers[i]);
    }

    // Sleep for a certain time to allow philosophers to dine
    sleep(10);

    // Cancel threads and clean up
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_cancel(philosophers[i]);
        pthread_join(philosophers[i], NULL);
        pthread_cond_destroy(&condition[i]);
    }
    pthread_mutex_destroy(&mutex);

    return 0;
}

