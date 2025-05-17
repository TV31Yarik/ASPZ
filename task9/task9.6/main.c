#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Вміст домашнього каталогу:\n");
    system("ls -l ~");

    printf("\nДекілька файлів з /usr/bin:\n");
    system("ls -l /usr/bin | head -5");

    printf("\nДекілька файлів з /etc:\n");
    system("ls -l /etc | head -5");

    const char *paths[] = {"/etc/passwd", "/usr/bin/ls", "/etc/shadow"};
    for (int i = 0; i < 3; i++) {
        printf("\nПеревірка прав для: %s\n", paths[i]);
        printf("Доступ на читання: %s\n", (access(paths[i], R_OK) == 0) ? "дозволено" : "заборонено");
        printf("Доступ на запис: %s\n", (access(paths[i], W_OK) == 0) ? "дозволено" : "заборонено");
        printf("Доступ на виконання: %s\n", (access(paths[i], X_OK) == 0) ? "дозволено" : "заборонено");
    }

    return 0;
}