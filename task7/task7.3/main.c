#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Використання: %s <слово> <файл>\n", argv[0]);
        return 1;
    }

    char *word = argv[1];
    FILE *fp = fopen(argv[2], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, word)) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}
