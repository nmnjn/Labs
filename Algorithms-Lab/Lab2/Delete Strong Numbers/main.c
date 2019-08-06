#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkStrongNumber(int num){
    int i, originalNum, lastDigit, sum;
    long fact;
    /* Copy the value of num to a temporary variable */
    originalNum = num;

    sum = 0;

    /* Find sum of factorial of digits */
    while(num > 0)
    {

        /* Get last digit of num */
        lastDigit = num % 10;

        /* Find factorial of last digit */
        fact = 1;
        for(i=1; i<=lastDigit; i++)
        {
            fact = fact * i;
        }

        /* Add factorial to sum */
        sum = sum + fact;

        num = num / 10;
    }

    /* Check Strong number condition */
    if(sum == originalNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void deleteElementFromArray(int array[], int n, int position){
   if (position >= n)
      printf("Deletion not possible.\n");
   else
   {
      for (int c = position; c < n-1; c++)
         array[c] = array[c+1];
   }
}

int main(){
   int array[100];
   int n;
   printf("Enter number of elements in array\n");
   scanf("%d", &n);
   printf("Enter %d elements\n", n);
   for (int c = 0; c < n; c++)
      scanf("%d", &array[c]);
   for(int i = 0; i < n; i++){
	if(checkStrongNumber(array[i])){
		deleteElementFromArray(array, n, i);
		--n;
	}
   }

   for(int i = 0; i< n; i++)
	printf("%d  ", array[i]);
	
	getchar();
	return 0;
}
