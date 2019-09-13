#include <stdio.h>

void main()
{
	int a[10], b[10], x[10];
	int waiting[10], turnaround[10], completion[10];
	int i, j, smallest, count = 0, time, n;
	double avg = 0, tt = 0, end;

	printf("Enter # processes: ");
	scanf("%d", &n);
	printf("\n");
	
	for(i = 0; i < n; i++)
	{
		printf("Enter a.t. of process %d: ", i + 1);
		scanf("%d", &a[i]);
	}
	printf("\n");
	for(i = 0; i < n; i++)
	{
		printf("Enter b.t. of process %d: ", i + 1);
		scanf("%d",&b[i]);
	}

	for(i = 0; i < n; i++)
		x[i] = b[i];

	b[9] = 9999;
	
	for(time = 0; count != n; time++)
	{
		smallest = 9;
		for(i = 0; i < n; i++)
		{
			if(a[i] <= time && b[i] < b[smallest] && b[i] > 0)
				smallest = i;
		}
		b[smallest]--;
		
		if(b[smallest] == 0)
		{
			count++;
			end = time+1;
			completion[smallest] = end;
			waiting[smallest] = end - a[smallest] - x[smallest];
			turnaround[smallest] = end - a[smallest];
		}
	}
	
	printf("\nPID \t Burst \t Arrival \tWaiting \tTurnaround \tCompletion");
	for(i = 0; i < n; i++)
	{
		printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d", i + 1, x[i], a[i], waiting[i], turnaround[i], completion[i]);
		avg = avg + waiting[i];
		tt = tt + turnaround[i];
	}

	printf("\n\nAvg. w.t. = %lf\n", avg / n);
	printf("Avg. t.t. = %lf", tt / n);
		
	printf("\n");
}
