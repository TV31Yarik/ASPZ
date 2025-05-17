#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *filename = "tempfile.txt";
    FILE *f;

    f = fopen(filename, "w");
    if (f == NULL) {
        perror("Не вдалося створити файл");
        return 1;
    }
    fprintf(f, "Це тимчасовий файл.\n");
    fclose(f);
    printf("Файл '%s' створено звичайним користувачем.\n", filename);

    printf("Зміна прав доступу та власника за допомогою sudo...\n");
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "sudo chown root:root %s && sudo chmod 600 %s", filename, filename);
    int result = system(cmd);
    if (result != 0) {
        printf("Не вдалося змінити власника або права доступу. Переконайтесь, що маєте права sudo.\n");
        return 1;
    }

    printf("Спроба прочитати файл...\n");
    f = fopen(filename, "r");
    if (f == NULL) {
        perror("Помилка читання");
    } else {
        char buffer[100];
        fgets(buffer, sizeof(buffer), f);
        printf("Зміст файлу: %s", buffer);
        fclose(f);
    }

    printf("Спроба записати у файл...\n");
    f = fopen(filename, "a");
    if (f == NULL) {
        perror("Помилка запису");
    } else {
        fprintf(f, "Додаємо ще рядок.\n");
        fclose(f);
        printf("Запис виконано успішно.\n");
    }

    printf("Видаляємо файл...\n");
    result = remove(filename);
    if (result != 0) {
        perror("Не вдалося видалити файл");
    } else {
        printf("Файл видалено.\n");
    }

    return 0;
}
