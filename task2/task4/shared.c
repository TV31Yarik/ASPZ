#include <stdio.h>
#include <pthread.h>

int counter = 0;  
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  

void* thread_func(void* arg) {
    pthread_mutex_lock(&mutex);
    counter++;  
    pthread_mutex_unlock(&mutex);
    printf("Counter: %d\n", counter);
    return NULL;
}

int main() {
    pthread_t threads[5];
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}