#include <stdio.h>

#define MAX 50

int parent[MAX];
int number_of_elements;

void create_sets(int n)
{
	int i;

	number_of_elements = n;

	/*
	 * At the beginning, every element is a separate set.
	 * Therefore, every element is its own parent.
	 */
	for (i = 0; i < n; i++)
		parent[i] = i;
}

int find_set(int element)
{
	/*
	 * Follow the parent until the element becomes its own parent.
	 * That element is the representative of the set.
	 */
	while (parent[element] != element)
		element = parent[element];

	return element;
}

void union_sets(int first, int second)
{
	int first_parent = find_set(first);
	int second_parent = find_set(second);

	if (first_parent == second_parent) {
		printf("They are already in the same set.\n");
		return;
	}

	/* Make the representative of second point to the representative of first. */
	parent[second_parent] = first_parent;
	printf("Sets joined successfully.\n");
}

void display(void)
{
	int i;

	printf("\nElement: ");
	for (i = 0; i < number_of_elements; i++)
		printf("%d ", i);

	printf("\nParent : ");
	for (i = 0; i < number_of_elements; i++)
		printf("%d ", parent[i]);

	printf("\n");
}

int main(void)
{
	int choice, n, first, second;

	printf("Enter number of elements (1-%d): ", MAX);
	scanf("%d", &n);

	if (n < 1 || n > MAX) {
		printf("Invalid number of elements.\n");
		return 1;
	}

	create_sets(n);

	while (1) {
		printf("\n1. Union two elements\n");
		printf("2. Find set representative\n");
		printf("3. Display parent array\n");
		printf("4. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter two elements: ");
			scanf("%d %d", &first, &second);

			if (first < 0 || first >= n || second < 0 || second >= n) {
				printf("Invalid element.\n");
				break;
			}

			union_sets(first, second);
			break;

		case 2:
			printf("Enter an element: ");
			scanf("%d", &first);

			if (first < 0 || first >= n) {
				printf("Invalid element.\n");
				break;
			}

			printf("Representative: %d\n", find_set(first));
			break;

		case 3:
			display();
			break;

		case 4:
			return 0;

		default:
			printf("Invalid choice.\n");
		}
	}
}
