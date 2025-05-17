#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    char buffer[100];
    ssize_t bytes_read;

    int fd = open("testfile.txt", O_RDONLY);
    if (fd < 0) {
        perror("Помилка відкриття файлу");
        return 1;
    }

    bytes_read = read(fd, buffer, 100);

    if (bytes_read < 0) {
        perror("Помилка читання");
        close(fd);
        return 1;
    }

    printf("Запрошено 100 байтів, прочитано %zd байтів\n", bytes_read);

    close(fd);
    return 0;
}
