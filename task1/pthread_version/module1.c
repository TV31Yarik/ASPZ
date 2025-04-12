#include <stdio.h>
#include <unistd.h>

void module1_function() {
    for (int i = 0; i < 5; ++i) {
        printf("Module 1 - Step %d\n", i);
        sleep(1);
    }
}