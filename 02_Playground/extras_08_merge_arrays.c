#include<stdio.h>
int main()
{
    int n1,n2,n3,i1,i2,i;
    printf("Enter the number of elements in first set :");
    scanf("%d",&n1);
    int arr1[n1];
    printf("Enter the %d elements :\n",n1);
     for (int i1 = 0; i1 < n1; i1++)
  {
    scanf("%d", &arr1[i1]);
  } 
    printf("Enter the number of elements in second set :");
    scanf("%d",&n2);
    int arr2[n2];
    printf("Enter the %d elements :\n",n2);
     for (int i2 = 0; i2 < n2; i2++)
  {
    scanf("%d", &arr2[i2]);
  } 
  n3=n1+n2;
int arr3[n3];
return 0;
}
