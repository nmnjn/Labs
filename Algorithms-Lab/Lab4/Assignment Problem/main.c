#include <stdio.h>
#include <stdlib.h>

int minimum = 10000000;
int mat[10][10];
int sol[10];
int n;

void computeCost(int arr[]) {
	int cost = 0,i;
	for(i=0; i<n; i++) {
		cost = cost + mat[i][arr[i]-1];
	}

	if(cost < minimum){
		minimum = cost;
		for(i=0; i<n; i++) {
			sol[i] = arr[i];
		}
	}
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int arr[], int start, int end)
{
    if(start==end) {
        computeCost(arr);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap(&arr[i], &arr[start]);
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start+1, end);
        //restore swap
        swap(&arr[i], &arr[start]);
    }
}

int main() {
	int i,j;
	printf("Enter number of jobs: \n");
	scanf("%d",&n);

	printf("Enter the cost matrix: \n");

	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&mat[i][j]);
		}
	}

	int arr[n];
	for(i=0; i<n; i++) {
		arr[i] = i+1;
	}

	permutation(arr,0,n-1);

	printf("The minimum cost for the job is -> %d\n", minimum);

	for (int i = 0; i < n; ++i)
		printf("assign job %d to person %d\n", sol[i], i+1);
}

// #include<stdio.h>
// #include<stdlib.h>
// #include<limits.h>

// int min[1000], min_value = 100000;

// void printCombinations(int size, int arr[size][size], int buf[size], int buf_1[size], int ix) {
//   int i, j;

//   if(ix == size) {
//     int sum = 0, flag = 1;
//     for(i = 0; i < size; i++) {
//       sum += buf[i];
//     }

//     for (i = 0; i < size - 1; i++) {
//         for (j = i + 1; j < size; j++) {
//             if (buf_1[i] == buf_1[j]) {
//               flag = 0;
//               break;
//             }
//         }
//     }

//     if(sum < min_value && flag) {
//       for(i = 0; i < size; i++) {
//         min[i] = buf[i];
//       }
//       min_value = sum;
//     }
//   }
//   else {
//     for(i = 0; i < size; i++) {
//       buf[ix] = arr[i][ix];
//       buf_1[ix] = i;
//       printCombinations(size, arr, buf, buf_1, ix + 1);
//     }
//   }
// }

// int main() {
//   int i, j, size;

//   printf("Enter size:\n");
//   scanf("%d", &size);

//   int arr[size][size];

//   printf("Enter sources vs sinks:\n");
//   for(i = 0; i < size; i++) {
//     for(j = 0; j < size; j++) {
//       scanf("%d", &arr[i][j]);
//     }
//   }

//   int buff[size];
//   int buff_1[size];
//   printCombinations(size, arr, buff, buff_1, 0);

//   printf("\nMin combination: ");
//   for(j = 0; j < size; j++) {
//     printf("%d ", min[j]);
//   }

//   printf("\nMin cost: %d\n", min_value);

//   return 0;
// }