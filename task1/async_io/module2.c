#include <aio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void module2_function() {
    int fd = open("module2_output.txt", O_WRONLY | O_CREAT, 0644);
    const char* msg = "Hello from module 2\n";

    struct aiocb cb;
    memset(&cb, 0, sizeof(cb));
    cb.aio_fildes = fd;
    cb.aio_buf = (void*)msg;
    cb.aio_nbytes = strlen(msg);

    aio_write(&cb);
    while (aio_error(&cb) == EINPROGRESS);

    close(fd);
}
