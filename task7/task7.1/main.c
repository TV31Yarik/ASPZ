#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = popen("rwho | more", "r");
    if (!fp) {
        perror("popen");
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        fputs(buffer, stdout);
    }

    pclose(fp);
    return 0;
}