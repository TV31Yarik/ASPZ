#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    const char *filename = "output.txt";
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd);
        exit(1);
    }

    if (pid == 0) {
        const char *child_msg = "Це повідомлення з дочірнього процесу\n";
        write(fd, child_msg, strlen(child_msg));
        close(fd);
        exit(0);
    } else {
        const char *parent_msg = "Це повідомлення з батьківського процесу\n";
        write(fd, parent_msg, strlen(parent_msg));
        wait(NULL);
        close(fd);
    }

    return 0;
}