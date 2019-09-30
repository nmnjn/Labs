#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *func(void *params){
 counter++;
 printf("%d\n", counter);
}

void main()
{
 pthread_t t1, t2;
 pthread_create(&t1, 0, func, 0);
 pthread_create(&t2, 0, func, 0);
 pthread_join(t1, 0);
 pthread_join(t2, 0);
}