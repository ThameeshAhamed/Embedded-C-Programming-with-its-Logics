#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    int fd1, fd2;
    char a[100], b[100];

    mkfifo("FIFO1", 0644);
    mkfifo("FIFO2", 0644);

    fd1 = open("FIFO1", O_RDONLY);
    fd2 = open("FIFO2", O_WRONLY);

    while(1){
        read(fd1, a, sizeof(a));
        printf("Received: %s\n", a);

        printf("Reply: ");
        fgets(b, sizeof(b), stdin);

        write(fd2, b, strlen(b)+1);
    }
}

