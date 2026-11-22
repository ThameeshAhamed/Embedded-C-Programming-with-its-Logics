#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    int fd1, fd2;
    char str1[100];

    mkfifo("full_duplex1", 0644);
    mkfifo("full_duplex2", 0644);

    fd1 = open("full_duplex1", O_WRONLY);
    fd2 = open("full_duplex2", O_RDONLY);

    if(fork() == 0){
        // child → write
        while(1){
            printf("Enter message: ");
            fgets(str1, sizeof(str1), stdin);
            write(fd1, str1, strlen(str1)+1);
        }
    }
    else{
        // parent → read
        char str2[100];
        while(1){
            int n = read(fd2, str2, sizeof(str2));
            if(n > 0){
                str2[n] = '\0';
                printf("Received: %s\n", str2);
            }
        }
    }
}
