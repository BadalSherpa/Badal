#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h> 
void *fun1();
void *fun2();
int resource=5; //shared variable
void *fun1()
{
	int x;
	x=resource;//thread one reads value of shared variable
	x++; //thread one increments its value 
	sleep(1); //thread one ts preempted by thread 2 
	resource=x; //thread one updates the value of shared variable
}
void *fun2()
{
	int y;
	y=resource;//thread two reads value of shared variable
	y--;//thread two increments its Value 
	sleep(1);//thread two ts preempted by thread 1 
	resource=y; //thread one updates the value of shared variable
}
int main()
{
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,&fun1,NULL);
	pthread_create(&thread2,NULL,&fun2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("final value of resource is %d\n",resource);
}
