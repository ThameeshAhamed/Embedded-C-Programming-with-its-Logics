#include<stdio.h>
int main(){
	int a=0x12345678;
	char *ptr=(char*)&a;

	if(*ptr==78){
		printf("little");
	}
	else{
		printf("big");
	}
}
