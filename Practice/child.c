#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main() {
    int i;

    for (i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            printf("Child %d: PID = %d, Parent PID = %d\n", i+1, getpid(), getppid());
            exit(1);  // Important → stop child from creating more children
        }
    }

    // Parent process
    printf("Parent: PID = %d\n", getpid());

    exit(1);
}
