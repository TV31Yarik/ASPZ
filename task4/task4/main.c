#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr1 = malloc(128);
    if (!ptr1) {
        perror("malloc ptr1");
        return 1;
    }
    printf("ptr1 = %p\n", ptr1);

    free(ptr1); 

    void *ptr2 = malloc(128);
    if (!ptr2) {
        perror("malloc ptr2");
        return 1;
    }
    printf("ptr2 = %p\n", ptr2);

    if (ptr1 == ptr2) {
        printf("malloc повернув ту саму адресу після free()\n");
    } else {
        printf("malloc повернув іншу адресу\n");
    }

    free(ptr2);
    return 0;
}
