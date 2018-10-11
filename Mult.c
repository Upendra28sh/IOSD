#include<stdio.h>
#include<string.h>

void main()
{
  int n1, n2, arr[10], k = 0, l, temp;
  puts("Enter two numbers");
  scanf("%d %d",&n1,&n2);
  memset(arr, 0, sizeof(arr));
  while(n1)
  {
    l = k;
    temp = n2;
    while(temp)
    {
      arr[l] += ((temp % 10) * (n1 % 10)) % 10;
      arr[++l] += ((temp % 10) * (n1 % 10)) / 10;
      temp /= 10;
    }
    k++;
    n1 /= 10;
  }
  for(int i = 0; i <= l; i++)
  {
    if(arr[i] > 9)
    {
      arr[i+1] += arr[i] / 10;
      arr[i] %= 10;
    }
  }
  if(arr[l] == 0)
    l--;
  printf("\nProduct: ");
  while(l >= 0)
  {
    printf("%d",arr[l]);
    l--;
  }
  printf("\n");
}
