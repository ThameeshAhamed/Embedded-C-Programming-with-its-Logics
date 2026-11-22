#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig){
    printf("In ISR... %d\n",sig);
}

int main(){
        printf("signal is not respond 10 seconds...\n");
	signal(2,handler);
	signal(3,handler);
	sleep(10);
	while(1){
		printf("signal ignored successfully...\n");
               sleep(1);
	}
}
