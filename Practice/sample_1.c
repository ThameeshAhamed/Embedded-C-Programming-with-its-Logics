#include<stdio.h>
void func();
int main(){
	/*int arr[]={10,20,30,40};
	int *ptr=arr;
	printf("%ld\n",(void*)&ptr[3]-(void*)&ptr[0]);
	while(1);*/

	void func(){
		static  int x=1;
		x++;
		printf("%d\n",x);
	}
	func();
	func();
	func();
}
