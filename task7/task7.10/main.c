#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float random_float_0_1() {
    return rand() / (float)RAND_MAX;
}

float random_float_0_n(float n) {
    return random_float_0_1() * n;
}

int main() {
    srand(time(NULL));

    printf("0.0 до 1.0: %.3f\n", random_float_0_1());
    printf("0.0 до 10.0: %.3f\n", random_float_0_n(10.0));

    return 0;
}
