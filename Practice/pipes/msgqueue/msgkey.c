#include<stdio.h>
#include<sys/msg.h>
int main(){
	key_t id;
	id=ftok("msgfile",65);
	if(id==-1){
		perror("error");
		return 0;
	}
	printf("id created.... %d\n",id);
}

