#include<stdio.h>
int main(){
	int a=0x12345678;
	int temp;
	temp=((a&0x000000ff)<<24);
	printf("%c\n",temp);
}
