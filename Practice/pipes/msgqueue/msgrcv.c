#include<stdio.h>
#include<string.h>
#include<sys/msg.h>
struct msgrcv{
	long int tpe;
	char str[100];
};
int main(){
	int id,ret;
	struct msgrcv a;
	id=msgget(5,IPC_CREAT | 0644);
	while(1)
	{
	printf("enter msg type..\n");
	scanf("%ld",&a.tpe);
	ret=msgrcv(id,&a,sizeof(a.str),a.tpe,0);
	printf("mesg received... %s\n",a.str);
	printf("msg type....%ld\n",a.tpe);
	}
}
