#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        perror("fork помилка");
        return 1;
    }

    if (pid == 0) {
        printf("Дочірній процес: pid = %d\n", pid);
    } else {
        printf("Батьківський процес: pid дочірнього = %d\n", pid);
    }

    return 0;
}
