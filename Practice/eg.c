#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t pid1,pid2,pid3;
	int status;
	pid_t ret;
	if(1){
	pid1=fork();
	if(pid1==0){
		printf("child 1 is created : %d %d\n",getpid(),getppid());
		sleep(3);
		return 1;
	}
	pid2=fork();
        if(pid2==0){
                printf("child 2 is created : %d %d\n",getpid(),getppid());
		sleep(4);
		return 2;
        }
	pid3=fork();
        if(pid3==0){
                printf("child 3 is created : %d %d\n",getpid(),getppid());
		sleep(5);
		return 3;
        }
	while((ret=wait(&status))!=-1){
		int stat=status>>8;
		if(stat==1){
			printf("child 1 is terminated :%d\n",ret);
		}
		else if(stat==2){
                        printf("child 2 is terminated :%d\n",ret);
                }
		else if(stat==3){
                        printf("child 3 is terminated :%d\n",ret);
                }
	}
	printf("parent is terminated :%d\n",getpid());
	
	return 0;
	}
}

