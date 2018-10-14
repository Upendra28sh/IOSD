#include<stdio.h>
void main()
{
  int m, n, count = 0;
  printf("Enter the number of rows in the sparse matrix: ");
  scanf("%d",&m);
  printf("Enter the number of columns in the sparse matrix: ");
  scanf("%d",&n);
  int arr[m][n];
  printf("Enter a %dx%d sparse matrix\n",m,n);
  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
    {
      scanf("%d",&arr[i][j]);
      if(arr[i][j] != 0)
        count++;
    }
  struct sparse
  {
    int row_index;
    int col_index;
    int value;
  } sp_arr[count];
  for(int i=0, k=0; i<m; i++)
    for(int j=0; j<n && k<count; j++)
      if(arr[i][j] != 0)
      {
        sp_arr[k].row_index = i;
        sp_arr[k].col_index = j;
        sp_arr[k].value = arr[i][j];
        k++;
      }
  puts("Sparse matrix:");
  puts("\nRow\tColumn\tValue");
  for(int k=0; k<count; k++)
  {
    printf("%d\t",sp_arr[k].row_index);
    printf("%d\t",sp_arr[k].col_index);
    printf("%d\n",sp_arr[k].value);
  }
}
