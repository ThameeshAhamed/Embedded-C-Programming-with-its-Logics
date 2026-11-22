#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/msg.h>
int main(){
	int id;
	id=msgget(8,IPC_CREAT | 0644);
	printf("id is %d\n",id);
	if(id<0){
	   perror("error");
	   return 0;
	}
	printf("created...\n");
}

