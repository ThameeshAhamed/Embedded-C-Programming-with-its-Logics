#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	pid_t pid1,pid2;
	pid1=fork();
	if(pid1==0){
		sleep(2);
		printf("child 1 created pid : %d ppid : %d\n",getpid(),getppid());
		exit(1);
	}
	pid2=fork();
	if(pid2==0){
		sleep(1);
                printf("child 2 created pid : %d ppid : %d\n",getpid(),getppid());
		exit(2);
        }
	int stat;
	pid_t ret;
	waitpid(pid2,&stat,0);
	printf("parent wait for child 2 is : %d stat : %d\n",getpid(),WEXITSTATUS(stat));
}	
