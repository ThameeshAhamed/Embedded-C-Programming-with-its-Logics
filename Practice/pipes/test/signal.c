#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
void isr(int);
int main(){
	while(1){
	printf("process under execution...\n");
	signal(SIGALRM,isr);
	alarm(10);
	printf("alarm signal is schedule for process..\n");
	sleep(10);
	}
	
	
	
}
void isr(int n){
	printf("in isr...\n");
	printf("n=%d\n",n);
	alarm(1);
	printf("completed\n");
}
