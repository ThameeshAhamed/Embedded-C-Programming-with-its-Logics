#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/msg.h>
struct msgqueue{
	long type;
	char str[100];
};
int main(){
	int id,ret;
	key_t key;
	key=ftok("msgfile",65);
	struct msgqueue m;
	id=msgget(key,IPC_CREAT | 0644);
	if(id==-1){
		perror("failed to create message..\n");
		return 0;
	}
	while(1){
		printf("Enter Your Message...\n");
		fgets(m.str,sizeof(m.str),stdin);
		printf("enter id...\n");
		scanf("%ld",&m.type);
		getchar();
		ret=msgsnd(id,&m,strlen(m.str)+1,0);
		if(ret==-1){
			perror("failed...\n");
		}
		printf("Message sent successfully...\n");
	}
}


