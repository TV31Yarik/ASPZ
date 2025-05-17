#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    unsigned char data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};

    const char* filename = "testfile.bin";
    int fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (write(fd, data, sizeof(data)) != sizeof(data)) {
        perror("write");
        close(fd);
        return 1;
    }

    if (lseek(fd, 3, SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    unsigned char buffer[4];
    ssize_t bytes_read = read(fd, buffer, 4);
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    printf("Bytes read: ");
    for (int i = 0; i < bytes_read; i++) {
        printf("%u ", buffer[i]);
    }
    printf("\n");

    close(fd);

    unlink(filename);

    return 0;
}
