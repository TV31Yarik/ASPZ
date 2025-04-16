#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    printf("sizeof(size_t) = %lu байт\n", sizeof(size_t));
    printf("Максимальне значення size_t: %lu\n", (size_t)-1);
    return 0;
}