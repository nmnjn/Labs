// Solution to producer-consumer problem

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NITERS (100)

int buf[10], f=0, r=0;
sem_t mutex, full, empty;

void *produce(void *arg)
{
  int val1, val2;
  int i;

  printf("Producer created\n");
  
  for (int i = 0; i < NITERS; i++)
  {
    
    sem_wait( &empty );
    sem_wait( &mutex );
    printf("Produced item is: %d\n", i);
    buf[r] = i;
    r = (r + 1) % 10;

   // sleep(1);

    sem_getvalue(&full, &val1);
    sem_getvalue(&empty, &val2);
    printf("P: item = %d, full = %d, empty = %d\n", i, val1, val2);

    sem_post(&mutex);
    sem_post(&full);
  }
}

void *consume(void *arg)
{
  int item, i;

  printf("Consumer created\n");

  for (i = 0; i < NITERS; i++)
  {
    int val1, val2;

    sem_wait(&full);
    sem_wait( &mutex );

    item = buf[f];
    f = (f + 1) % 10;

    printf("consumed item is %d\n", item);
   // sleep(1);
    sem_getvalue(&full, &val1);
    sem_getvalue(&empty, &val2);
    printf("C:: item = %d, full = %d, empty = %d\n", item, val1, val2);

    sem_post(&mutex);
    sem_post(&empty);
  }
}

int main()
{
  pthread_t t1, t2;

  sem_init(&mutex, 0, 1);
  
  sem_init(&full, 0, 0);
  sem_init(&empty, 0, 10);

  pthread_create(&t2, NULL, consume, NULL);
  pthread_create(&t1, NULL, produce, NULL);
  
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}