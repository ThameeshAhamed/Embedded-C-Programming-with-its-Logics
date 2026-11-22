#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid = fork();

    if(pid == 0) {
        // Child process
        printf("Child START: PID=%d, PPID=%d\n", getpid(), getppid());

        sleep(5);  // wait so parent exits first

        printf("Child AFTER parent exit: PID=%d, PPID=%d\n", getpid(), getppid());
    }
    else {
	wait(NULL);
        // Parent process
        printf("Parent: PID=%d, PPID=%d\n", getpid(), getppid());

        sleep(1);  // short delay
        printf("Parent exiting...\n");

        exit(0);   // parent exits BEFORE child
    }

    return 0;
}
