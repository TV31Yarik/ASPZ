#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    long max_processes = sysconf(_SC_CHILD_MAX); 
    if (max_processes == -1) {
        perror("Не вдалося отримати максимальну кількість процесів");
        exit(1);
    }

    printf("Максимальна кількість запущених процесів: %ld\n", max_processes);

    for (long i = 0; i < max_processes + 10; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            exit(0);
        } else if (pid < 0) {
            printf("Помилка: не вдалося створити процес %ld\n", i + 1);
            break;
        }
    }

    while (wait(NULL) > 0);

    return 0;
}
