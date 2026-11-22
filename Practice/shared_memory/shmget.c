#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
int main(){
	int ret;
	key_t key;
	char *str;
	key=ftok("shmemory",65);
	printf("memory identifier %d\n",key);
	ret=shmget(key,100,IPC_CREAT | 0644);
	if(ret < 0){
		perror("error to create...\n");
		return 0;
	}
	printf("shm created successfully... %d\n",ret);
	str=(char*)shmat(ret,0,0);
	printf("enter a txt..\n");
	fgets(str,100,stdin);
	shmdt(str);
	return 0;
}
	
