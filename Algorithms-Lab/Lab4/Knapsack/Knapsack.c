#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int Knapsack(int *w, int *v, int n, int B){
    int temp;
    int maxVal = 0, maxSequence = 0;
    int totalWeight, totalValue;
    int opcount=0;
    unsigned int index = 0;
    for (int i = 0; i < pow(2, n); i++)
    {
        ++opcount;
        temp = i;
        totalValue = totalWeight = 0;
        index = 0;
        while (temp)
        {
            if(temp & 0x1){
                totalWeight = totalWeight + w[index];
                totalValue = totalValue + v[index];
            }
            index++;
            temp = temp >> 1;
        }

        if(totalWeight <= B && totalValue > maxVal){
            maxVal = totalValue;
            maxSequence = i;
        }
    }

    printf("\n Operation Count = %d\n", opcount);
    return maxSequence;

}

int main(){
    int *v, *w, i, n, knaps, B;
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

    knaps = Knapsack(w, v, n, B);
    printf("Knapscak contains the folloing items: \n");
    i = 0;
    while (knaps)
    {
        if(knaps & 0X1)
            printf("item %d  value %d\n", (i+1), v[i]);
        i++;
        knaps = knaps >> 1;
    }

    return 0;
}

