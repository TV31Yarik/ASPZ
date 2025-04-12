#include <stdio.h>
#include <pthread.h>
#include "module1.h"
#include "module2.h"

void* run_module1(void* arg) {
    module1_function();
    return NULL;
}

void* run_module2(void* arg) {
    module2_function();
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, run_module1, NULL);
    pthread_create(&t2, NULL, run_module2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}