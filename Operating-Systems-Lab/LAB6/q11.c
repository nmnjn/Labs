#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
	int id;
	int at;		
	int bt;		
	int wt;		
	int tat;	
} DATA_t, *DATA_p_t;

double awt, atat; 
int n; 

DATA_p_t *datas;

void display()
{
	printf("\nWaiting Time: \n");
	for (int i = 0; i < n; ++i) 
	{
 		DATA_p_t data = *(datas + i);
 		printf("%d ", data->wt);
 	}

 	printf("\nTurnaround Time: \n");
	for (int i = 0; i < n; ++i) 
	{
 		DATA_p_t data = *(datas + i);
 		printf("%d ", data->tat);
 	}

	printf("\n\n");
	printf("Avg. w.t = %.2lf\n", awt);
	printf("Avg. t.a.t = %.2lf\n", atat);
}

int main()
{
	//
	printf("Enter # processes: ");
	scanf("%d", &n);
	int i;
	datas = (DATA_p_t *)calloc(n, sizeof(DATA_p_t));

	printf("\n");

	for (i = 0; i < n; ++i)
	{
		*(datas + i) = (DATA_p_t)malloc(sizeof(DATA_t));
		DATA_p_t data = *(datas + i);
		data->id = i;

		printf("Enter a.t & b.t for process [%d]: ", i+1);
		scanf("%d", &data->at);
		scanf("%d", &data->bt);
	}
	
	//
	(*datas)->wt = 0;
	atat = (*datas)->tat = (*datas)->bt;
	int btt = (*datas)->bt;

	for (i = 1; i < n; ++i) 
	{
		DATA_p_t data = *(datas + i);
		data->wt = btt - data->at;
		btt += data->bt;
		awt += data->wt;
		data->tat = data->wt + data->bt;
		atat += data->tat;
	}
	atat /= n;
	awt /= n;
	
	display();
	
	return 0;
}