#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int is_sorted(int *arr, size_t n) {
    for (size_t i = 1; i < n; i++) {
        if (arr[i-1] > arr[i]) return 0;
    }
    return 1;
}
void print_array(int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void generate_random_array(int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void generate_sorted_array(int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = i;
    }
}
void generate_reverse_sorted_array(int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void generate_equal_array(int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = 42;
    }
}

int main() {
    srand(time(NULL));

    int *arr = malloc(sizeof(int) * ARRAY_SIZE);
    if (!arr) {
        perror("malloc");
        return 1;
    }

    struct {
        const char *name;
        void (*generator)(int *, size_t);
    } tests[] = {
        {"Random array", generate_random_array},
        {"Sorted array", generate_sorted_array},
        {"Reverse sorted array", generate_reverse_sorted_array},
        {"Equal elements array", generate_equal_array}
    };

    size_t test_count = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < test_count; i++) {
        tests[i].generator(arr, ARRAY_SIZE);

        clock_t start = clock();
        qsort(arr, ARRAY_SIZE, sizeof(int), compare_ints);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        int sorted = is_sorted(arr, ARRAY_SIZE);

        printf("%s: time=%.3f sec, sorted=%s\n",
               tests[i].name, time_taken, sorted ? "YES" : "NO");
    }

    free(arr);
    return 0;
}
