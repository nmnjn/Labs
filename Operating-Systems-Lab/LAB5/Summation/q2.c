#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
void *child_thread(int n){
	int sum=0;
	int arr[n];
	printf("Enter array elements:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	return (void *)sum;
}

int main(){
	pthread_t thread;
	int n,sum;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	int arr[n];
	pthread_create(&thread,0,&child_thread,(void *)n);
	pthread_join(thread,&sum);
	printf("%d\n",sum);
	return 0;
}