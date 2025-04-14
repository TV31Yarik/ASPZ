#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void handle_request(int id) {
    char *data = malloc(1024);  
    if (!data) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    sprintf(data, "Request ID: %d", id);

    if (id % 10000 == 0) {
        printf("RARE EVENT: something went wrong on ID %d\n", id);
        return;  
    }

    free(data);
}

int main() {
    for (int i = 1; i <= 1000000; ++i) {
        handle_request(i);
    }

    printf("Done processing.\n");
    return 0;
} 