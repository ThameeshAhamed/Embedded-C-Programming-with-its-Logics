#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
int main(){
        int ret;
	char *str;
        key_t id;
        id=ftok("shmemory",65);
        printf("%d\n",id);
        ret= shmget(id,sizeof(str),IPC_CREAT | 0644);
        if(ret<0){
                perror("error");
                return 0;
        }
        printf("success...\n");
        str= (char*)shmat(ret,0,0);
        printf("reading data... %s\n",str);




}

