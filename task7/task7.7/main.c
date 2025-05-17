#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    char ans[4];
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".c")) {
            printf("Знайдено: %s. Додати дозвіл на читання для інших? (y/n): ", entry->d_name);
            fgets(ans, sizeof(ans), stdin);
            if (ans[0] == 'y') {
                chmod(entry->d_name, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
                printf("Дозвіл змінено.\n");
            }
        }
    }

    closedir(dir);
    return 0;
}
