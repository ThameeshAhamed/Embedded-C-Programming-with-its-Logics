#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
	int fd[2],ret;
	ret=pipe(fd);
	if(ret<0){
		perror("failed to create pipe...\n");
		return 0;
	}
	printf("pipe created...\n");
	if(fork()==0){
		char str[100];
		printf("enter a txt...\n");
		fgets(str,sizeof(str),stdin);
		write(fd[1],str,strlen(str)+1);
	}
	else{
		char str1[100];
		read(fd[0],str1,sizeof(str1)-1);
		printf("You entered... %s\n",str1);
	}
	return 0;
}
