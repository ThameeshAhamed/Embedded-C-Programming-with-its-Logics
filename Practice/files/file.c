#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int file_open,write_file;
	char str[100];
	file_open=open("temp.txt",O_WRONLY | O_CREAT | O_TRUNC,0666);
	if(file_open<0){
		perror("file error");
		return 0;
	}
	printf("Enter texts to the file\n");
	scanf("%[^\n]",str);
	write_file=write(file_open,str,strlen(str));
	if(write_file<=0){
		perror("error");
		return 0;
	}
	printf("waiting to uploading....\n");
	sleep(4);
	printf("successfully entered...\n");
}

