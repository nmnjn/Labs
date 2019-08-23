#include <pthread.h>
#include <stdio.h>
#include <unistd.h>



void* thread_code(void * param){
	printf("In thread code\n");
}

int main(int argc, char const *argv[])
{
	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, 0);
	// sleep(5);
	pthread_join(thread, 0);
	printf("In the main thread\n");

	return 0;
}