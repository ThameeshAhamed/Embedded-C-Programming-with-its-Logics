#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
	int fd1,fd2,ret;
	char str1[100],str2[100];
	mkfifo("file_1.txt",0644);
	mkfifo("file_2.txt",0644);
	fd1=open("file_1.txt",O_RDONLY);
	fd2=open("file_2.txt",O_WRONLY);
	if(fork()==0){
		while(1)
		{
		int n=read(fd1,str1,sizeof(str1)-1);
		if(n>0)
		{
		str1[n]='\0';
		printf("data received duplex 2 is ...%s",str1);
		}
		}
	}
	else{
		while(1)
		{
		printf("enter txt...\n");
		fgets(str2,sizeof(str2),stdin);
		write(fd2,str2,strlen(str2)+1);
		}
	}
}

