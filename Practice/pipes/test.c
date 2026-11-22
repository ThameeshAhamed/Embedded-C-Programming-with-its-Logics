
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<ctype.h>
void casec(char *str){
	for(int i=0;str[i]!='\0';i++){
		if(isupper(str[i])){
		   str[i]=tolower(str[i]);
		}
		else if(islower(str[i])){
		   str[i]=toupper(str[i]);
		}
		
	}
}
int main(){
        int ret,fd[2];
        ret=pipe(fd);
        if(ret==-1){
                perror("pipe creation failes..\n");
                return 0;
        }
        if(fork()==0){
                char str1[100];
                printf("enter your thoughts...\n");
                fgets(str1,sizeof(str1),stdin);
                write(fd[1],str1,strlen(str1)+1);
        }
        else{
                wait(0);
                char str2[100];
                printf("your txts are received in parent process...\n\n");
                sleep(4);
                read(fd[0],str2,sizeof(str2)-1);
		casec(str2);
		
                printf("%s",str2);



        }
}


