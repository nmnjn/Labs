#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct numbers{
int even[100];
int odd[100];
};
int even_count=0,odd_count=0;
void *even_thread(void *even){
	struct numbers *num=(struct numbers *)even;
	int sum=0;
	for(int i=0;i<even_count;i++){
		sum+=num->even[i];
	}
	return (void *)sum;
}
void *odd_thread(void *odd){
	struct numbers *num=(struct numbers *)odd;
	int sum=0;
	for(int i=0;i<odd_count;i++){
		sum+=num->odd[i];
	}
	return (void *)sum;
}
int main(){
	pthread_t e_thread,o_thread;
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter arrat elements: \n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	struct numbers num;
	int even_sum,odd_sum;
	for(int i=0;i<n;i++){
		if(arr[i]%2)
			num.odd[odd_count++]=arr[i];
		else
			num.even[even_count++]=arr[i];
	}
	pthread_create(&e_thread,NULL,&even_thread,(void *)&num);
	pthread_create(&o_thread,NULL,&odd_thread,(void *)&num);
	void *even_return,*odd_return;
	pthread_join(e_thread,&even_return);
	pthread_join(o_thread,&odd_return);
	even_sum=even_return;
	odd_sum=odd_return;
	printf("Even Sum = %d\n",even_sum);
	printf("Odd Sum = %d\n",odd_sum);
	return 0;
}

