#include<stdio.h>
#include<stdint.h>
int main(){
      	uint16_t a=10;
	printf("%p\n",&a);
	printf("%d\n",a);

	uint64_t b=20;
	printf("%p\n",(void*)&b);
}
