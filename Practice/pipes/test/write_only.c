#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
	int fd,ret;
	char str[100];
	fd=open("duumy.txt",O_WRONLY | O_CREAT | O_TRUNC,0644);
	if(fd<0){
		perror("failed to open pipe..\n");
		return 0;
	}
	while(1)
	{
	fgets(str,strlen(str),stdin);
	write(fd,str,strlen(str)+1);
	}
}

