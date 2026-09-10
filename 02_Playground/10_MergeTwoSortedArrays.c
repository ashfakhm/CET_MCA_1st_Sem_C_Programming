#include <stdio.h>

int main(void)
{
	int size1, size2;

	printf("Enter the size of the first sorted array: ");
	scanf("%d", &size1);

	printf("Enter the size of the second sorted array: ");
	scanf("%d", &size2);

	if (size1 <= 0 || size2 <= 0)
	{
		printf("Invalid size\n");
		return 1;
	}

	int first[size1];
	int second[size2];
	int merged[size1 + size2];

	printf("Enter %d elements in ascending order for the first array:\n", size1);
	for (int i = 0; i < size1; i++)
	{
		scanf("%d", &first[i]);
	}

	printf("Enter %d elements in ascending order for the second array:\n", size2);
	for (int i = 0; i < size2; i++)
	{
		scanf("%d", &second[i]);
	}

	int i = 0;
	int j = 0;
	int k = 0;

	while (i < size1 && j < size2)
	{
		if (first[i] <= second[j])
		{
			merged[k] = first[i];
			i++;
		}
		else
		{
			merged[k] = second[j];
			j++;
		}
		k++;
	}

	while (i < size1)
	{
		merged[k] = first[i];
		i++;
		k++;
	}

	while (j < size2)
	{
		merged[k] = second[j];
		j++;
		k++;
	}

	printf("Merged array: ");
	for (int index = 0; index < size1 + size2; index++)
	{
		printf("%d ", merged[index]);
	}
	printf("\n");

	return 0;
}
