#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void isr(int sig){
	printf("ISR NUMBER %d : \n",sig);
	signal(2,SIG_DFL);
	signal(3,SIG_DFL);
	printf("isr completed\n");
}
int main(){
	printf("Signal ignored 5 seconds...\n");
	signal(2,SIG_IGN);
	signal(3,SIG_IGN);
	signal(SIGALRM,isr);
	alarm(5);
	while(1){
		printf("signal ignored successfuly...\n");
		sleep(1);
	}

}
