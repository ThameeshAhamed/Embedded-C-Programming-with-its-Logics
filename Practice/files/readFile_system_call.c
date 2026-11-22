#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int file_open, read_file;
    char str[100];

    file_open = open("temp.txt", O_RDONLY);

    if(file_open < 0){
        perror("file error");
        return 0;
    }



    if(read_file < 0){
        perror("read error");
        return 0;
    }

    // ✅ add null terminator
    while((read_file = read(file_open, str, sizeof(str)-1)) > 0){
	    str[read_file] = '\0';
            printf("%s", str);
}

    close(file_open);

    return 0;
}
