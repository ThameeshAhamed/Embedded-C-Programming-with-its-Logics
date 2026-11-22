#include<stdio.h>
int main(){
        FILE *fptr;
        fptr=fopen("hello.txt","a");
	printf("\n");
        fprintf(fptr,"linux is processing...\n");
        fclose(fptr);
}

