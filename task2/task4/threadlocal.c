#include <stdio.h>
#include <pthread.h>

__thread int counter = 0;  

void* thread_func(void* arg) {
    counter++;  
    printf("Thread-local counter: %d\n", counter);
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