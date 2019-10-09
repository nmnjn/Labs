#include <stdio.h> 

#define MAX(a, b) ((a>b) ? a : b)
  
//Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n){ 
  int i, w; 
  int K[n+1][W+1]; 
  
  //build table K[][] in bottom up manner 
    for(i=0; i<=n; i++){ 
      for(w=0; w<=W; w++){ 
        if(i==0 || w==0)
          K[i][w] = 0; 
        else if (wt[i-1] <= w) 
          K[i][w] = MAX(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
        else
          K[i][w] = K[i-1][w]; 
       } 
   }

   i = n; 
   int j = W;
   while(i > 0){
      if (K[i][j] > K[i-1][j])
      {
        printf("Include item %d\n", i);
        j = j - wt[i-1];
      }
      i = i -1;
   }
   return K[n][W]; 
} 
  
int main(){

  int Weights[10], Values[10];

    int n;
    printf("Enter the number of items: \n");
    scanf("%d", &n);
    int W;
    printf("Enter the maximum knapsack capacity\n");
    scanf("%d", &W);

    for (int i = 0; i < n; ++i)
    {
      printf("Enter weight for item %d:", i+1);
      scanf("%d", &Weights[i]);
      printf("Enter value for item %d:", i+1);
      scanf("%d", &Values[i]);
      printf("\n");
    }

    printf("Optimal knapsack cost = %d\n", knapSack(W, Weights, Values, n)); 
    
    return 0; 
} 
