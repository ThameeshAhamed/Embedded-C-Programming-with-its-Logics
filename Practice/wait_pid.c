#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("child process created : %d\n",getpid());
		return 2;
	}
	else{
		int stat;
		pid_t ret;
		ret=waitpid(-1,&stat,0);
		printf("after waitpid\n");
		printf("status : %d\n",WEXITSTATUS(stat));
		printf("ret : %d\n",ret);
	}
}
