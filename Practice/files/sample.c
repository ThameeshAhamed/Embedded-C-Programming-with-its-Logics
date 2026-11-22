#include<stdio.h>
int main(){
	FILE *fptr;
	fptr=fopen("hello.txt","w");
	fprintf(fptr,"Thameesh Ahamed\n");
	fclose(fptr);
}

