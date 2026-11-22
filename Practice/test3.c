#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
void handler(int);
int main(){
	pid_t pid[3];
	for(int i=1;i<=3;i++){
		pid[i]=fork();
		if(pid[i]==0){
			printf(" chid %d is created with pid :%d ppid :%d\n",i,getpid(),getppid());
			return i;
		}
		else{
			wait(0);

		        if(i==3){
			   signal(SIGUSR1,handler);
			   kill(pid[2],SIGUSR1);
			   printf("child 3 is signaled.. pid %d\n",pid[2]);
		        }
	
	      }
	}
}
void handler(int sig){
	printf( "isr... %d\n",sig);
}
