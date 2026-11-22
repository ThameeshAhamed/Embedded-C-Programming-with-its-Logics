#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void handler(int);
int main(){
	printf("Signal alaram star\n");
	sleep(4);
	signal(9,handler);
	signal(19,handler);
	while(1){
	printf("Running...\n");
	sleep(3);
	}
}
void handler(int sig){
	printf("isr handler.. %d\n",sig);
}

