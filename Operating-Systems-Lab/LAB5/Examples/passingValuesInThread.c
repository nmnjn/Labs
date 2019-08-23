#include <pthread.h>
#include <stdio.h>

void* child_thread(void * param){
	int id = (int)param;
	printf("Start thread %i\n", id);
	return (void *)id;
}


int main(){
	pthread_t thread[10];
	int return_value[10];
	for (int i = 0; i < 10; ++i)
	{
		pthread_create(&thread[i], 0, &child_thread, (void*)i);
	}
	for (int i = 0; i < 10; ++i)
	{
		pthread_join(thread[i], (void**)&return_value[i]);
		printf("End thread %i\n", return_value[i]);
	}
}