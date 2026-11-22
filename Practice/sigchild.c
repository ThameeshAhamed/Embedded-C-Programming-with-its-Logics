#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<signal.h>
void isr(int);
int main(){
	if(fork()==0){
		printf("child process created successfully... %d\n",getpid()); 
		sleep(5);
		return 0;
	}
	else{
		wait(0);
		signal(SIGCHLD,isr);
		printf("child is terminated using signal :%d\n",getpid());
	}
}
	void isr(int sig){
		printf("in isr..\n");
		 wait(NULL);

	}
		

