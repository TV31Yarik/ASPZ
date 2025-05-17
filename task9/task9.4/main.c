#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Виконується команда whoami:\n");
    system("whoami");

    printf("\nВиконується команда id:\n");
    system("id");

    return 0;
}
