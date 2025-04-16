#include <stdio.h>
#include <stdlib.h>

int main() {
    int xa = 1000000;
    int xb = 1000000;
    int num = xa * xb; 

    printf("num = %d\n", num);
    void *ptr = malloc(num);

    if (ptr == NULL) {
        printf("malloc повернув NULL (можливо через переповнення)\n");
    } else {
        printf("malloc виділив пам'ять\n");
        free(ptr);
    }

    return 0;
}