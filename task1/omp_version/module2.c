#include <stdio.h>
#include <unistd.h>

void module2_function() {
    for (int i = 0; i < 5; ++i) {
        printf("Module 2 - Step %d\n", i);
        sleep(1);
    }
}