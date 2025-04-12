#include <stdio.h>
#include <time.h>
#include <limits.h>

int main() {
    printf("Розмір time_t: %zu байт\n", sizeof(time_t));
    
    if (sizeof(time_t) == 4) {
        time_t max = (1UL << 31) - 1;  
        printf("32-бітний time_t закінчиться: %s", ctime(&max));
    } else {
        printf("64-бітний time_t закінчиться через мільярди років\n");
    }
    
    return 0;
}