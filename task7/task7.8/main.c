#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    char ans[4];
    struct stat st;

    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &st) == 0 && S_ISREG(st.st_mode)) {
            printf("Видалити файл %s? (y/n): ", entry->d_name);
            fgets(ans, sizeof(ans), stdin);
            if (ans[0] == 'y') {
                if (remove(entry->d_name) == 0)
                    printf("Файл видалено.\n");
                else
                    perror("remove");
            }
        }
    }

    closedir(dir);
    return 0;
}
