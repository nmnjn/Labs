//BEST FIT
#include <stdio.h>
#include <string.h>

void bestFit(int partitions[], int m, int processSize[], int n) {
    int allocation[n]; 
  
    memset(allocation, -1, sizeof(allocation)); 
 
    for (int i=0; i<n; i++) { 
        int bestIdx = -1; 
        for (int j=0; j<m; j++) { 
            if (partitions[j] >= processSize[i]) { 
                if (bestIdx == -1) 
                    bestIdx = j; 
                else if (partitions[bestIdx] > partitions[j]) 
                    bestIdx = j; 
            } 
        } 
  
        if (bestIdx != -1) {
            allocation[i] = bestIdx;

            partitions[bestIdx] -= processSize[i]; 
        } 
    } 
  
    printf("Process No.\tProcess Size\tBlock no.\n"); 
    for (int i = 0; i < n; i++) { 
        printf("%d\t\t%d\t\t", i+1, processSize[i]); 
        if(allocation[i] != -1) 
            printf("%d\n", allocation[i]+1); 
        else
            printf("Not Allocated\n");
    } 
} 

int main() { 
    int partitions[] = {100, 500, 200, 300, 600}; 
    int processSize[] = {212, 417, 112, 426}; 
    int m = sizeof(partitions)/sizeof(partitions[0]); 
    int n = sizeof(processSize)/sizeof(processSize[0]); 
  
    bestFit(partitions, m, processSize, n); 
  
    return 0 ; 
} 
