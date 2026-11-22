#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *thread1(void *p){
	printf("thread 1 is executed...\n");

	printf("thread 1 id :%lu\n",pthread_self());
	
}
void *thread2(void *p){
        printf("thread 2 is executed...\n");

        printf("thread 2 id :%lu\n",pthread_self());

}

int main(){
	pthread_t t1,t2;
	pthread_create(&t1,0,thread1,0);
        sleep(10);
        pthread_create(&t2,0,thread2,0);
        sleep(10);	
	printf("main is executed...\n");
	


	
}
