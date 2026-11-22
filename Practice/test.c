#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t pid_1,pid_2,pid_3;
	pid_1=fork();
	if(pid_1==0){
		printf("pid : %d ppid : %d\n",getpid(),getppid());
		exit(1);
	
	}
	pid_2=fork();
	if(pid_2==0){
                printf("pid : %d ppid : %d\n",getpid(),getppid());

		exit(2);
        }
	pid_3=fork();
	if(pid_3==0){
                printf("pid : %d ppid : %d\n",getpid(),getppid());
		exit(3);
        }
}
