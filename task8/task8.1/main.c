#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    int flags = fcntl(pipefd[1], F_GETFL);
    fcntl(pipefd[1], F_SETFL, flags | O_NONBLOCK);

    char buffer[70000]; 
    memset(buffer, 'A', sizeof(buffer));

    ssize_t nbytes = sizeof(buffer);
    ssize_t count = write(pipefd[1], buffer, nbytes);

    printf("Requested to write %zd bytes\n", nbytes);
    if (count == -1) {
        perror("write error");
    } else {
        printf("Actually written %zd bytes\n", count);
        if (count < nbytes) {
            printf("Partial write happened!\n");
        }
    }

    close(pipefd[0]);
    close(pipefd[1]);
    return 0;
}
