#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd;
    char buffer[100];

    fd = open("mypipe", O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Received: %s", buffer);

    close(fd);
}
