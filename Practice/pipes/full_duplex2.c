#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    int fd1, fd2;
    char str1[100], str2[100];

    mkfifo("full_duplex1", 0644);
    mkfifo("full_duplex2", 0644);

    fd1 = open("full_duplex1", O_RDONLY);
    fd2 = open("full_duplex2", O_WRONLY);

    if(fork() == 0){
        // child → read
        while(1){
            int n = read(fd1, str1, sizeof(str1));
            if(n > 0){
                str1[n] = '\0';
                printf("Received: %s\n", str1);
            }
        }
    }
    else{
        // parent → write
        while(1){
            printf("Reply: ");
            fgets(str2, sizeof(str2), stdin);
            write(fd2, str2, strlen(str2)+1);
        }
    }
}

