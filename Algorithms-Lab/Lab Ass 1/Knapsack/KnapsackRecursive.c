#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int *w;
int *v;

int KnapsackRec(int size, int B, int maxSequence, int maxVal){
    int totalWeight = 0;
    int totalValue = 0;
    int index = 0;

    if(size < 1){
        return maxSequence;
    }

    int temp = size - 1;

    while(temp){
        if(temp & 0x1){
            totalWeight = totalWeight + w[index];
            totalValue = totalValue + v[index];     
        }
        index++;
        temp = temp >> 1;
    }

    if(totalWeight <= B && totalValue > maxVal){
        return KnapsackRec(size-1, B, size-1, totalValue);
    }else{
        return KnapsackRec(size-1, B, maxSequence, maxVal);  
    }

}

int main(){
    int i, n, knaps, B;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    v=(int *)calloc(n, sizeof(int));
    w=(int *)calloc(n, sizeof(int));
    printf("Please enter the weights: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    printf("Please enter the Values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    printf("Please enter the Knapsack Capacity: ");
    scanf("%d", &B);
    int subsetSize = pow(2, n);
    knaps = KnapsackRec(subsetSize, B, 0, 0);
    
    printf("Knapsack contains the folloing items: \n");
    i = 0;
    while (knaps)
    {
        if(knaps & 0X1)
            printf("item %d  value %d  weight %d\n", (i+1), v[i], w[i]);
        i++;
        knaps = knaps >> 1;
    }

    return 0;
}