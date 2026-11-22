#include<stdio.h>
#include<unistd.h>
int main(){
	int fd[2],ret;
	ret=pipe(fd);
	printf("%d\n",ret);
	if(ret==-1){
		perror("error");
		return 0;
	}
	printf("enter text\n");
	char str[100];
	
}
