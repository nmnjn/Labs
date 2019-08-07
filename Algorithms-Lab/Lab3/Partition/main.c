#include <stdio.h>
#include <string.h> 


#include <stdio.h> 
#include <math.h> 
  
void findPartitions(int set[], int setSize) 
{ 
    unsigned int powerSetSize = pow(2, setSize); 
    int i, j, n, m, set1sum, set2sum;
    int set1[100], set2[100];

    for(i = 1; i < powerSetSize / 2; i++) 
    { 
        set1sum = 0;
        set2sum = 0;
        n = 0;
        m = 0;

      for(j = 0; j < setSize; j++) 
       { 
            if(i & (1<<j)){
                set1sum = set1sum + set[j];
                set1[n] = set[j];
                ++n;
            }
            else{
                set2sum = set2sum + set[j];
                set2[m] = set[j];
                ++m;
            }
       }
       if(set1sum == set2sum){
            printf("Found Sets: \n");
            printf("{ ");
            for (int i = 0; i < n; ++i)
                printf("%d ", set1[i]);
            printf("}\n{ ");
            for (int i = 0; i < m; ++i)
                printf("%d ", set2[i]);
            printf("}\n");
       }
    } 
} 
  
int main() 
{ 
    int array[100];
    int n;
    printf("Enter number of elements in array\n");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (int c = 0; c < n; c++)
        scanf("%d", &array[c]);
    findPartitions(array, n);
    return 0;   
} 

