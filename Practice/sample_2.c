#include<stdio.h>
int main(){
	int arr[]={10,20,30,40};
	int *ptr=arr;
	printf("%ld\n",(void*)&ptr[3]-(void*)&ptr[0]);
	printf("%ld\n",&ptr[2]);
	printf("%ld\n",&ptr[3]);
	printf("%ld\n",ptr[1]);  // o/p is 20
	//Thameesh Ahamed 


}
