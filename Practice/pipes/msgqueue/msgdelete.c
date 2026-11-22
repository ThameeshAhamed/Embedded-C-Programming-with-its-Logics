#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/msg.h>
struct message{
	long type;
	char str[100];
};
int main(){
	int id,ret;
	key_t key;
	struct message m;
	key=ftok("msgfile",65);
	id=msgget(key,IPC_CREAT);
	if(id==-1){
		perror("failed..\n");
		return 0;
	}
	while(1)
	{
	printf("enter id..\n");
	scanf("%ld",&m.type);
	getchar();
	ret=msgrcv(id,&m,sizeof(m.str),m.type,0);
	printf("received msg is... %s\n",m.str);
	
	printf("enter id to delete mesage..\n");
	scanf("%ld",&m.type);
	getchar();
	msgctl(id,IPC_RMID,0);
	printf("msg queue deleted\n");
	}
}

