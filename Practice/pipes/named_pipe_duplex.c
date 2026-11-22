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

    fd1 = open("FIFO1", O_WRONLY);
    fd2 = open("FIFO2", O_RDONLY);

    while(1){
        printf("Enter message: ");
        fgets(a, sizeof(a), stdin);

        write(fd1, a, strlen(a)+1);

        read(fd2, b, sizeof(b));
        printf("Received: %s\n", b);
    }
}
