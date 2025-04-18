#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *str = malloc(13 * sizeof(char)); 
  
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    snprintf(str, 13, "Hello world!");

    printf("%s\n", str);

    free(str);
    str = NULL; 

    return 0;
}