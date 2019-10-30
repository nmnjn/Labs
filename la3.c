#include<stdio.h>
#define MAX 10

//int arr[MAX][MAX],c[MAX][MAX];

int max(int a,int b){
	if(a>b) return a;
	else return b;
}

void method1(int n,int m,int arr[][MAX],int c[][MAX]){
	for(int i=0;i<=n;i++) arr[i][0]=0;
	for(int i=0;i<=m;i++) arr[0][i]=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			arr[i][j]=max(arr[i-1][j],arr[i][j-1])+c[i][j];
		}
	}
}

void getOptPath(int n,int m,int arr2[],int arr[][MAX],int c[][MAX]){
	int k=0;
	int i=n,j=m;
	while(i!=0&&j!=0){
		arr2[k]=c[i][j];
		if(arr[i][j-1]>arr[i-1][j]) j--;
		else i--;
		k++;
	}
	if(i==0){
		j--;
		while(j!=0){
			arr2[k]=c[1][j];
			j--;
			k++;
		}
	}
	else if(j==0){
		i--;
		while(i!=0){
			arr2[k]=c[i][1];
			i--;
			k++;
		}
	}
}

int display(int n,int m,int arr3[]){
	int sum=0;
	printf("\nPath:\n");
	for(int i=m+n-2;i>0;i--){
		printf("%d-->",arr3[i]);
		sum=sum+arr3[i];
	}
	printf("%d",arr3[0]);
	sum=sum+arr3[0];
	printf("\n");
	return sum;
}

int main(){
	int arr[MAX][MAX],c[MAX][MAX];
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			arr[i][j]=0;
			c[i][j]=0;
		}
	}
	int n,m;
	printf("Enter N: ");
	scanf("%d",&n);
	printf("Enter M: ");
	scanf("%d",&m);
	printf("Enter the coin matrix:\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&c[i][j]);
		}
	}
	method1(n,m,arr,c);
	int arr3[m+n];
	for(int i=0;i<m+n;i++) arr3[i]=0;
	getOptPath(n,m,arr3,arr,c);
	int s=display(n,m,arr3);
	//display(n,m,arr3);
	printf("The total number of coins in the opt path:%d\n",s);
}