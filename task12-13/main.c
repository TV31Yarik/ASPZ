#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <ucontext.h>
#include <string.h>
#include <unistd.h>

void crash_handler(int sig, siginfo_t *info, void *ucontext) {
    ucontext_t *ctx = (ucontext_t *)ucontext;

#if defined(__x86_64__)
    fprintf(stderr, "Program crashed (signal %d)\n", sig);
    fprintf(stderr, "RIP: 0x%llx\n", (unsigned long long)ctx->uc_mcontext.gregs[REG_RIP]);
    fprintf(stderr, "RSP: 0x%llx\n", (unsigned long long)ctx->uc_mcontext.gregs[REG_RSP]);
    fprintf(stderr, "RBP: 0x%llx\n", (unsigned long long)ctx->uc_mcontext.gregs[REG_RBP]);
    fprintf(stderr, "RAX: 0x%llx\n", (unsigned long long)ctx->uc_mcontext.gregs[REG_RAX]);
    fprintf(stderr, "RBX: 0x%llx\n", (unsigned long long)ctx->uc_mcontext.gregs[REG_RBX]);
    fprintf(stderr, "RCX: 0x%llx\n", (unsigned long long)ctx->uc_mcontext.gregs[REG_RCX]);
    fprintf(stderr, "RDX: 0x%llx\n", (unsigned long long)ctx->uc_mcontext.gregs[REG_RDX]);
    fprintf(stderr, "RSI: 0x%llx\n", (unsigned long long)ctx->uc_mcontext.gregs[REG_RSI]);
    fprintf(stderr, "RDI: 0x%llx\n", (unsigned long long)ctx->uc_mcontext.gregs[REG_RDI]);
#else
    fprintf(stderr, "Реєстровий дамп не реалізований для цієї архітектури.\n");
#endif

    _exit(1);  
}

void setup_crash_handler() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = crash_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);  
    sigaction(SIGABRT, &sa, NULL);  
}

int main() {
    setup_crash_handler();
    int *ptr = NULL;
    *ptr = 42;  
    return 0;
} 