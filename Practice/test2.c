#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    for(int i=1;i<=3;i++){
        pid_t pid = fork();

        if(pid < 0){
            perror("fork failed");
            exit(1);
        }

        if(pid == 0){
            printf("Child %d PID:%d PPID:%d\n", i, getpid(), getppid());
            exit(i);   // important
        }
    }


    // Parent waits AFTER creating all children
    int stat;
    pid_t ret;
    wait(NULL);


    while((ret = wait(&stat)) > 0){
        if(WIFEXITED(stat)){
            int cur_stat = WEXITSTATUS(stat);

            printf("Child with exit status %d terminated (PID=%d)\n", cur_stat, ret);
        }
    }

    printf("Parent PID: %d\n", getpid());
}

