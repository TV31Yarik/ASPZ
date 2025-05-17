#include <stdio.h>
#include <stdlib.h>

void wait_for_key() {
    printf("Натисніть клавішу для продовження...\n");
    getchar();
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Використання: %s <файл1> [файл2...]\n", argv[0]);
        return 1;
    }

    char line[256];
    int count = 0;

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (!fp) {
            perror(argv[i]);
            continue;
        }

        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
            if (++count % 20 == 0) {
                wait_for_key();
            }
        }

        fclose(fp);
    }

    return 0;
}
