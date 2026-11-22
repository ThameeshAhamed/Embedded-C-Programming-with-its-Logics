#include<stdio.h>
#include<string.h>
int main(){
        FILE *fptr;
        fptr=fopen("hello.txt","r");
        char str[100];
	while(fgets(str,sizeof(str),fptr))
	     printf("%s",str);
        fclose(fptr);
}

