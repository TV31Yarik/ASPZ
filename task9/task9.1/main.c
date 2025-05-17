#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[512];
    int current_uid = getuid();
    int found_other_users = 0;
    
    fp = popen("getent passwd", "r");
    if (fp == NULL) {
        perror("Помилка відкриття потоку");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        char *saveptr;
        char *username = strtok_r(line, ":", &saveptr);
        strtok_r(NULL, ":", &saveptr); 
        char *uid_str = strtok_r(NULL, ":", &saveptr);

        if (uid_str == NULL) continue;

        int uid = atoi(uid_str);

        if (uid > 1000 && uid != current_uid) {
            found_other_users = 1;
            printf("Звичайний користувач: %s (UID=%d)\n", username, uid);
        }
    }

    pclose(fp);

    if (!found_other_users) {
        printf("Інших звичайних користувачів з UID > 1000 не знайдено.\n");
    }

    return 0;
}
