#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd,writing;
	char str[100];
	fd=open("new.txt",O_WRONLY | O_CREAT | O_TRUNC,0666);
	printf("%d\n",fd);
	printf("enter text\n");
	fgets(str,sizeof(str),stdin);
	writing=write(fd,str,strlen(str));
	printf("successfully entered....\n");
}

