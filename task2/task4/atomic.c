#include <stdio.h>
#include <stdatomic.h>
#include <pthread.h>

atomic_int counter = 0;  

void* thread_func(void* arg) {
    atomic_fetch_add(&counter, 1);  
    printf("Atomic counter: %d\n", counter);
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