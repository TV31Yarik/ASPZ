#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

struct sbar {
    int id;
};

int main() {
    struct sbar *ptr = calloc(1000, sizeof(struct sbar));
    if (!ptr) {
        perror("calloc failed");
        return 1;
    }

    printf("Allocated 1000 elements at %p\n", ptr);

    size_t new_count = 500;
    struct sbar *newptr = reallocarray(ptr, new_count, sizeof(struct sbar));
    
    if (!newptr) {
        perror("reallocarray failed");
        free(ptr);
        return 1;
    }

    printf("Resized to %zu elements at %p\n", new_count, newptr);
    free(newptr);
    return 0;
}