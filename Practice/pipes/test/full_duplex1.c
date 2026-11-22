#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include"fcntl.h"
#include<string.h>
int main(){
	int fd1,fd2,ret;
	char str1[100],str2[100];
	mkfifo("file_1.txt",0644);
	mkfifo("file_2.txt",0644);
	fd1=open("file_1.txt",O_WRONLY);
	fd2=open("file_2.txt",O_RDONLY);
	if(fork()==0){
		while(1)
		{
		printf("enter txt...\n");
		fgets(str1,sizeof(str1),stdin);
		write(fd1,str1,strlen(str1)+1);
		}
	}
	else{
		while(1)
		{
		int n=read(fd2,str2,sizeof(str2)-1);
		if(n>0)
		{
		str2[n]='\0';
		printf( "data received duplex 1 is ... %s\n",str2);
		}
		}

	}
}



