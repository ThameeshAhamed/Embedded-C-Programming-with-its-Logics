#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	for(int i=0;i<3;i++){
		if(fork() <0){
			perror("fork failed");
			exit(1);
		}
		if(fork()==0){
			printf(" child %d id is : %d parent id is : %d fork returned : %d\n",i+1,getpid(),getppid(),fork());
			
			printf("\n");
			exit(0);
		}
		else{
			printf("parent %d id created with child id : %d\n",i+1,getpid());
			printf("\n");
		}
	}
	for(int i=0;i<3;i++){
		wait(NULL);
	}
	printf("parent id pid :%d finished ",getpid());
	return 0;
}
