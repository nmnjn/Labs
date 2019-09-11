// #include <stdio.h>  
 
// int wt[10], bt[10], at[10], tat[10], n;  
// float awt, atat;

// void input()
// {  
//     printf("Number of processes?\t");  
//     scanf("%d", &n);  
//     int i;  
//     for(i=0; i<n; i++)  
//     {
//         printf("Arrival Time of process %d?\t", i+1);  
//         scanf("%d", &at[i]);         
//         printf("Burst Time of process %d?\t", i+1);  
//         scanf("%d", &bt[i]);         
//     }  
// }

// void sort()
// {
//     int i, j, temp;
//     for(i=0; i<n; i++)
//     {
//         for(j=i+1; j<n; j++)
//         {    
//             if(at[j] < at[i])
//             {
//                 temp = at[i];
//                 at[i] = at[j];
//                 at[j] = temp;
		
// 		      temp = bt[i];
//                 bt[i] = bt[j];
//                 bt[j] = temp;
//             }
//         }
//     }
// }

// void calculate()
// {  
//     wt[0]=0;  
//     atat = tat[0] = bt[0];  
//     int btt = bt[0];
//     int i;  
//     for(i=1; i<n; i++)
//     {  
//         wt[i] = btt - at[i];  
//         btt += bt[i];        
//         awt += wt[i];     
//         tat[i] = wt[i] + bt[i];   
//         atat += tat[i];    
//     }  
//     atat/=n;  
//     awt/=n;       
// }
  
// void display()
// {  
//     int i;  
//     printf("ID\tArrival\tBurst\tWaiting\tTurnAround\n");  
//     for(i=0;i<n;i++)
//         printf("%2d\t%2d\t%2d\t%2d\t%2d\n", i+1, at[i], bt[i], wt[i], tat[i]); 
//     printf("Average Waiting Time:%.2f\nAverage Turn Around Time:%.2f\n", awt, atat);
// }
    
// int main()
// {         
//     input(); 
//     sort(); 
//     calculate();  
//     display();   
//     return 0;  
// } 


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int AT(int *a, int *b, int n, int time)
{
    int i, min=0;
    for(i=0; i<n; i++)
        if (b[i] == -1)
            continue;
        if (b[min] > b[i] &&a [i] <= time)
            min=i;
    return min;
}
int processorTime = 0;

int findShortestProcess(int *at, int *bt, int n){
    int min = 0, flag = 0;
    for (int i = 0; i < n; ++i)
    {
        if(at[i] <= processorTime){
            return i;
        }
    }
    processorTime++;
    return findShortestProcess(at, bt, n);
}

void sort(int *at, int *bt, int n)
{
    int i, j, temp;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {    
            if(at[j] < at[i])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
        
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
}

int main(){
    int *at, *bt, *wt, *tat, *ct;
    int n, shortestProcess, time = 0;
    float averageWT;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    at=(int *)calloc(n,sizeof(int));
    bt=(int *)calloc(n,sizeof(int));
    wt=(int *)calloc(n,sizeof(int));
    tat=(int *)calloc(n,sizeof(int));
    ct=(int *)calloc(n,sizeof(int));
    for(int i=0; i<n; i++)
    {
        printf("\nEnter arrival time for P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("\nEnter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    sort(at, bt, n);

    for(int i=0; i<n; i++)
    {
        shortestProcess = findShortestProcess(at, bt, n);
        wt[shortestProcess]= time - at[shortestProcess];
        for(int j=0; j<bt[shortestProcess]; j++)
        {
            time++;
        }
        tat[shortestProcess] = time - at[shortestProcess];
        at[shortestProcess] = INT_MAX;
    }
    for(int i=0; i<n; i++)
        averageWT+=wt[i];
    averageWT/=n;
    printf("ID\tArrival\t\tBurst\tWaiting\tTurnAround\n");
    for(int i=0; i<n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    printf("Average Time=%.2lf\n", averageWT);
    return 0;
}
