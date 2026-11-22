#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void isr(int);
int main(){
	printf("before signal killing\n");
	sleep(5);
	signal(SIGKILL,isr);
	while(1){
	   printf("after signal kill...\n");
	   sleep(3);
	}
}
void isr(int sig){
	printf( "isr returned : %d\n",sig);
}
