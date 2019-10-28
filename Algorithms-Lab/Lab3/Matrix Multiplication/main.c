#include <stdio.h>
#include <string.h> 
int main()
{
  int m, n, p, q, sum = 0;
  int first[10][10], second[10][10], multiply[10][10];
 
  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d", &m, &n);
  printf("Enter elements of first matrix\n");
 
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &first[i][j]);
 
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);
 
  if (n != p)
    printf("The matrices can't be multiplied with each other.\n");
  else
  {
    printf("Enter elements of second matrix\n");
 
    for (int i = 0; i < p; i++)
      for (int j = 0; j < q; j++)
        scanf("%d", &second[i][j]);
 
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < q; j++) {
        for (int k = 0; k < p; k++) {
          sum = sum + first[i][k]*second[k][j];
        }
 
        multiply[i][j] = sum;
        sum = 0;
      }
    }
 
    printf("Product of the matrices:\n");
 
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < q; j++)
        printf("%d\t", multiply[i][j]);
       
       printf("\n");
    }
  }
 
  return 0;
}