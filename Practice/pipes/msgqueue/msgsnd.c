#include<stdio.h>
#include<string.h>
#include<sys/msg.h>
struct msg{
	long int  mtype;
	char str[100];
};
int main(){
	int id,ret;
	struct msg v;
	id=msgget(5,IPC_CREAT | 0644);
	while(1)
	{
	printf("enter data to snd..\n");
	fgets(v.str,sizeof(v.str),stdin);
	printf("enter msg type...\n");
	scanf("%ld",&v.mtype);
	getchar();
	ret=msgsnd(id,&v,strlen(v.str)+1,0);
	printf("msg sent successfully...\n");
	}
}

	
