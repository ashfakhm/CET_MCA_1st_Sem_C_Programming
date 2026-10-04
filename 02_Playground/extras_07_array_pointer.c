#include<stdio.h>
int main()
{
    int n,*p;
    printf("Enter the number of elements :");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the %d elements :\n",n);
     for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }  
  p=arr;
  
    for (int i = 0; i < n; i++)
  {
    printf("Element %d =",i+1);
    printf("%d\n", *(p+i));
  }  

    return 0;
}
