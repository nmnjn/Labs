#include <stdio.h>
#include <string.h>

void worst(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];

    memset(allocation, -1, sizeof(allocation));
  
    for (int i=0; i<n; i++) { 
        int wstIdx = -1; 
        for (int j=0; j<m; j++) { 
            if (blockSize[j] >= processSize[i]) { 
                if(wstIdx == -1) 
                    wstIdx = j; 
                else if(blockSize[wstIdx] < blockSize[j]) 
                    wstIdx = j; 
            } 
        } 
  
        if (wstIdx != -1) { 
            allocation[i] = wstIdx; 
  
            blockSize[wstIdx] -= processSize[i]; 
        } 
    } 
  
    printf("Process No.\tProcess Size\tBlock no.\n"); 
    for (int i = 0; i < n; i++) { 
        printf("%d\t\t%d\t\t", i+1, processSize[i]); 
        if (allocation[i] != -1) 
            printf("%d", allocation[i]+1); 
        else
            printf("Not Allocated"); 
        printf("\n"); 
    } 
} 

int main() { 
    int partitions[] = {100, 500, 200, 300, 600}; 
    int processSize[] = {212, 417, 112, 426}; 
    int m = sizeof(partitions)/sizeof(partitions[0]); 
    int n = sizeof(processSize)/sizeof(processSize[0]); 
  
    worst(partitions, m, processSize, n); 
  
    return 0;
}
