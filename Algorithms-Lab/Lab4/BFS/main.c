#include<stdio.h>
int G[10][10],visited[10],n;    //n is no of vertices and graph is sorted in array G[10][10]
int queue[100], front = 0, rear = 0;

 
void BFS(int i){
  int j;
  printf("%d \n", i);
  visited[i]=1;
  for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1){
            visited[j]=1;
            queue[rear++] = j;
       }
            

  if(front != rear)
    BFS(queue[front++]);

}

void main()
{
    int i,j;
    printf("Enter number of vertices:");
   
	scanf("%d",&n);
 
    //read the adjecency matrix
	printf("\nEnter adjecency matrix of the graph:");
   
	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
 
    //visited is initialized to zero
   for(i=0;i<n;i++)
        visited[i]=0;
 
    BFS(0);
}
 