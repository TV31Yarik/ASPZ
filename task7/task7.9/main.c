#include <stdio.h>
#include <time.h>

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Приклад коду
    for (volatile int i = 0; i < 100000000; i++);

    clock_gettime(CLOCK_MONOTONIC, &end);

    long duration = (end.tv_sec - start.tv_sec) * 1000 +
                    (end.tv_nsec - start.tv_nsec) / 1000000;
    printf("Час виконання: %ld мс\n", duration);
    return 0;
}
