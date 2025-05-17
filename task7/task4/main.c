#include <stdio.h>
#include <string.h>

#define MAX_JOBS 10
#define MAX_NAME_LENGTH 50

typedef enum {
    QUEUED,
    RUNNING,
    PAUSED,
    CANCELLED,
    COMPLETED
} Status;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    Status status;
    int progress; 
} Job;

Job jobQueue[MAX_JOBS];
int jobCount = 0;
int nextJobId = 1;

void addJob(const char* name) {
    if (jobCount >= MAX_JOBS) {
        printf("Черга повна!\n");
        return;
    }

    Job newJob;
    newJob.id = nextJobId++;
    strncpy(newJob.name, name, MAX_NAME_LENGTH - 1);
    newJob.name[MAX_NAME_LENGTH - 1] = '\0';
    newJob.status = QUEUED;
    newJob.progress = 0;

    jobQueue[jobCount++] = newJob;
    printf("Додано задачу з ID %d\n", newJob.id);
}

void showJobs() {
    printf("\nID\tНазва\t\tСтатус\t\tПрогрес\n");
    for (int i = 0; i < jobCount; i++) {
        char* statusStr;
        switch (jobQueue[i].status) {
            case QUEUED: statusStr = "Очікує"; break;
            case RUNNING: statusStr = "Виконується"; break;
            case PAUSED: statusStr = "Пауза"; break;
            case CANCELLED: statusStr = "Скасовано"; break;
            case COMPLETED: statusStr = "Завершено"; break;
            default: statusStr = "Невідомо"; break;
        }
        printf("%d\t%s\t\t%s\t%d%%\n", jobQueue[i].id, jobQueue[i].name, statusStr, jobQueue[i].progress);
    }
}

void processJobs() {
    for (int i = 0; i < jobCount; i++) {
        if (jobQueue[i].status == QUEUED || jobQueue[i].status == RUNNING) {
            jobQueue[i].status = RUNNING;
            jobQueue[i].progress += 10;
            if (jobQueue[i].progress >= 100) {
                jobQueue[i].progress = 100;
                jobQueue[i].status = COMPLETED;
            }
            printf("Обробка задачі ID %d... (%d%%)\n", jobQueue[i].id, jobQueue[i].progress);
            break; 
        }
    }
}

void pauseJob(int id) {
    for (int i = 0; i < jobCount; i++) {
        if (jobQueue[i].id == id && jobQueue[i].status == RUNNING) {
            jobQueue[i].status = PAUSED;
            printf("Задача ID %d призупинена\n", id);
            return;
        }
    }
    printf("Задачу не знайдено або вона не виконується\n");
}

void resumeJob(int id) {
    for (int i = 0; i < jobCount; i++) {
        if (jobQueue[i].id == id && jobQueue[i].status == PAUSED) {
            jobQueue[i].status = QUEUED;
            printf("Задача ID %d відновлена\n", id);
            return;
        }
    }
    printf("Задачу не знайдено або вона не на паузі\n");
}

void cancelJob(int id) {
    for (int i = 0; i < jobCount; i++) {
        if ((jobQueue[i].status == QUEUED || jobQueue[i].status == RUNNING || jobQueue[i].status == PAUSED) && jobQueue[i].id == id) {
            jobQueue[i].status = CANCELLED;
            printf("Задача ID %d скасована\n", id);
            return;
        }
    }
    printf("Задачу не знайдено або вона не може бути скасована\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int id;

    while (1) {
        printf("\n=== Меню ===\n");
        printf("1. Додати задачу\n");
        printf("2. Показати чергу\n");
        printf("3. Обробити чергу\n");
        printf("4. Пауза задачі\n");
        printf("5. Відновити задачу\n");
        printf("6. Скасувати задачу\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Назва задачі: ");
                scanf("%s", name);
                addJob(name);
                break;
            case 2:
                showJobs();
                break;
            case 3:
                processJobs();
                break;
            case 4:
                printf("ID задачі: ");
                scanf("%d", &id);
                pauseJob(id);
                break;
            case 5:
                printf("ID задачі: ");
                scanf("%d", &id);
                resumeJob(id);
                break;
            case 6:
                printf("ID задачі: ");
                scanf("%d", &id);
                cancelJob(id);
                break;
            case 0:
                printf("Вихід...\n");
                return 0;
            default:
                printf("Невірний вибір\n");
        }
    }

    return 0;
}
