#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
pthread_t threads[NUM_THREADS];

void* thread_func(void* arg) {
    printf("Task completed by thread\n");
    return NULL;
}

void create_thread_pool() {
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    create_thread_pool();
    return 0;
}



