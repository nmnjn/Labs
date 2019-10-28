#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

int counter = 0; 
  
void swap (int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(&arr[i], &arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
    counter++;
} 
  
void buildHeap(int arr[], int n) 
{  
    int startIdx = (n / 2) - 1; 
    for (int i = startIdx; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
} 
  
void printHeap(int arr[], int n) 
{ 
    printf("Array representation of Heap is:\n"); 
  
    for (int i = 0; i < n; ++i) 
        printf(" %d", arr[i]); 
    printf("\n"); 
} 

int main() 
{ 
    int n;
    int i;
    int m; 
    clock_t start_time, end_time;
    double total_time;

    FILE *input;
    input = fopen("numbers.txt", "r");

    FILE *output;
    output = fopen("buildheap.csv", "w+");
    fprintf(output, "inputsize, counts\n");

    while (fscanf(input, " %d", &n)) {

        int *arr = (int *)calloc(n, sizeof(int));
        for (i = 0; i < n; ++i) {
            fscanf(input, " %d", &m);
            *(arr + i) = m;
        }

        start_time = clock();
        buildHeap(arr, n);
        printf("Building Heap for size %d with counts: %d\n", n, counter);
        
        end_time = clock();
        total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;

        fprintf(output, "%d, %d, %lf\n", n, counter, total_time);
        counter = 0;

        if (n == 1000)
            break;
    }

    fclose(input);
    fclose(output);
    return 0; 
} 