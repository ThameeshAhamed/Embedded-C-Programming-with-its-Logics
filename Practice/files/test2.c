#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(){
	int fd,reading;
	char str[100];
	fd=open("new.txt",O_RDONLY);
	printf("%d\n",fd);
	while((reading= read(fd, str, sizeof(str))) > 0){
		printf("%s",str);
	}
	close(fd);
}
