#include <stdio.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        // Child process
        sleep(5);  // wait so parent exits first
        printf("Child: PID = %d, New Parent PID = %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent exiting...\n");
    }

    return 0;
}
