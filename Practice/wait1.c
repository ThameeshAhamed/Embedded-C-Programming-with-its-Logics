#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;
    pid_t ret;

    // Child 1
    pid1 = fork();
    if (pid1 == 0) {
        printf("Child 1 START: PID=%d, PPID=%d\n", getpid(), getppid());
        sleep(2);
        return 1;
    }

    // Child 2
    pid2 = fork();
    if (pid2 == 0) {
        printf("Child 2 START: PID=%d, PPID=%d\n", getpid(), getppid());
        sleep(3);
        return 2;
    }

    // Child 3
    pid3 = fork();
    if (pid3 == 0) {
        printf("Child 3 START: PID=%d, PPID=%d\n", getpid(), getppid());
        sleep(4);
        return 3;
    }

    // Parent waits for all children
    while ((ret = wait(&status)) != -1) {
        int exit_status = status >> 8;

        if (exit_status == 1) {
            printf("Child 1 terminated (PID=%d)\n", ret);
        } else if (exit_status == 2) {
            printf("Child 2 terminated (PID=%d)\n", ret);
        } else if (exit_status == 3) {
            printf("Child 3 terminated (PID=%d)\n", ret);
        }
    }

    printf("Parent is terminated\n");
    return 0;
}
