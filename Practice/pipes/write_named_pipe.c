#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    int fd;
    char a[100];

    mkfifo("mypipe", 0644);   // create FIFO

    printf("Enter message:\n");
    fgets(a, sizeof(a), stdin);   // ✅ take input with spaces

    fd = open("mypipe", O_WRONLY);   // wait for reader

    write(fd, a, strlen(a)+1);   // send data

    printf("Sent data: %s", a);

    close(fd);
}

