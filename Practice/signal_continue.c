#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// handler for SIGCONT
void handle_cont(int sig) {
    printf("\nProcess resumed using SIGCONT (signal %d)\n", sig);
}

int main() {
    // register SIGCONT handler
    signal(SIGCONT, handle_cont);

    printf("Process started. PID = %d\n", getpid());

    while (1) {
        printf("Running...\n");
        sleep(2);
    }

    return 0;
}
