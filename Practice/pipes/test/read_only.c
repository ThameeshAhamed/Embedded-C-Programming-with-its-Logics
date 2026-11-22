#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
        int fd,ret;
        char str1[100];
        fd=open("duumy.txt", O_RDONLY);
        if(fd<0){
                perror("failed to open pipe..\n");
                return 0;
        }
        while(1)
        {
        read(fd,str1,sizeof(str1));
	sleep(3);
	printf("Data Received...%s\n",str1);
        }
	
}
	
