#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct range{
int m;
int n;
};
int p_count=0;
int isprime(int x){
	for(int i=2;i<(x/2);i++){
		if(x%i==0)
			return 1;
	}
	return 0;
}
void *child_thread(void *arguments){
	struct range *arg=(struct range *)arguments;
	int n=(arg->n)-(arg->m);
	int *arr=(int*) malloc(sizeof(int)*n);
	int count=0;
	for(int i=arg->m;i<=arg->n;i++){
		if(isprime(i)==0){
			arr[count]=i;
			count++;
			p_count++;
		}
	}
	return (void *)arr;
}
int main(){
	pthread_t thread;
	int arg[2];
	struct range args;
	printf("Enter starting and ending element\n");
	scanf("%d%d",&args.m,&args.n);
	pthread_create(&thread,NULL,&child_thread,(void *)&args);
	//int r=args.n-args.m;
	void *temp;
	int *arr;
	pthread_join(thread,&temp);
	arr=temp;
	for(int i=0;i<p_count;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}
