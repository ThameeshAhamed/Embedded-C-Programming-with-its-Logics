#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd,ret;
	char str[100];
	fd=open("temp.txt",O_WRONLY , 0644);
	scanf("%s",str);
	ret=write(fd,str,100);
	printf(" entered txt is :%s",str);
}
