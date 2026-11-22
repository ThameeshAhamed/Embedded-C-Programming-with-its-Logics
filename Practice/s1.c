#include<stdio.h>
#pragma pack(2)
int func(){
	int a=10;
	a++;
	return a;
}
int func1(){
	int b=20;
	b++;
	return b;
}
void show_bit(int n){
	for(int i=31;i>=0;i--){
		printf("%d",(n>>i)&1);
	}
	printf("\n");
}
 struct a{
         char a,int b,short c;
 };

int main(){
	//printf("%d\n",func());
	//printf("%d\n",func());
	//printf("%p\n",(void*)func());
	//printf("%p\n",(void*)func1());

//	int a=0x12345678;
//	int temp=a & 0xff000000;
//	show_bit(temp);
//	int bit=0x11;
// 	show_bit(bit<<1);
//	if(printf("%d\n",10<=15)-9){
	}

	//int a[10]={0};//
	//printf("%d\n",(int)(&a+1)-(int) &a);//
	 printf("%d\n",sizeof(struct));

	

}
