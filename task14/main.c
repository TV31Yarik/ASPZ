#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

timer_t timer;

void timer_handler(int sig) {
    printf("Таймер спрацював!\n");
}
void set_timer_interval(int seconds) {
    struct itimerspec ts;
    ts.it_value.tv_sec = seconds;
    ts.it_value.tv_nsec = 0;
    ts.it_interval.tv_sec = seconds;
    ts.it_interval.tv_nsec = 0;

    if (timer_settime(timer, 0, &ts, NULL) == -1) {
        perror("timer_settime");
        exit(1);
    }
}

int main() {
    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = timer_handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);
    struct sigevent sev;
    memset(&sev, 0, sizeof(sev));
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGALRM;

    if (timer_create(CLOCK_REALTIME, &sev, &timer) == -1) {
        perror("timer_create");
        exit(1);
    }
    printf("Введіть інтервал у секундах (наприклад, 2): ");
    int interval;
    scanf("%d", &interval);
    set_timer_interval(interval);

    while (1) {
        printf("Введіть новий інтервал (сек) або 0 щоб вийти: ");
        scanf("%d", &interval);
        if (interval <= 0) break;
        set_timer_interval(interval);
    }

    timer_delete(timer);
    printf("Програма завершена.\n");
    return 0;
}