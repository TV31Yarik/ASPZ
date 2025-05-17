#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    FILE *f;
    int res;

    f = fopen("myfile.txt", "w");
    if (!f) {
        perror("Не вдалося створити файл");
        return 1;
    }
    fprintf(f, "Це файл, створений користувачем\n");
    fclose(f);
    printf("Файл створено.\n");

    printf("Копіювання файлу в домашній каталог користувача...\n");
    res = system("sudo cp myfile.txt /home/$(whoami)/copy.txt");
    if (res != 0) {
        printf("Не вдалося скопіювати файл\n");
        return 1;
    }

    system("sudo chown root:root /home/$(whoami)/copy.txt");
    system("sudo chmod 600 /home/$(whoami)/copy.txt");
    printf("Файл скопійовано, права доступу змінено.\n");

    char path[256];
    snprintf(path, sizeof(path), "/home/%s/copy.txt", getenv("USER"));

    printf("Спроба змінити файл...\n");
    f = fopen(path, "a");
    if (!f) {
        perror("Не вдалося відкрити файл для запису");
    } else {
        fprintf(f, "Додані дані\n");
        fclose(f);
        printf("Файл змінено (неочікувано!)\n");
    }

    printf("Спроба видалити файл...\n");
    res = remove(path);
    if (res == 0)
        printf("Файл видалено\n");
    else
        perror("Не вдалося видалити файл");

    return 0;
}
