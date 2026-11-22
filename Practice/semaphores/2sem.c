#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd,i,ret;
	key_t id;
	char str[100]="123456789";

	id=ftok("semaphore",65);

	struct sembuf V;

	ret=semget(id,3,IPC_CREAT | 0644);

	fd=open("sample.txt",O_WRONLY | O_CREAT | O_APPEND,0644);

	if(ret<0){
		perror("failed...\n");
	}

	V.sem_num=0;
	V.sem_op=0;
	V.sem_flg=0;

	printf("waiting for resources...\n");
	semop(ret,&V,1);

	semctl(ret,0,SETVAL,1);

	printf("aquire the resources..\n");
	printf("data writing into the file...\n");

	for(i=0;str[i]!='\0';i++){
		write(fd,str+i,1);
		sleep(2);
	}

	printf("completed to writting..\n");

	sleep(5);
	printf("process one going to release...\n");
	sleep(3);

	semctl(ret,0,SETVAL,0);

	printf("resource released...\n");

	return 0;
}
