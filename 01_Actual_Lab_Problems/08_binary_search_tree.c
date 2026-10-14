#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

struct node *insert(struct node *root, int value)
{
	if (root == NULL) {
		root = malloc(sizeof(struct node));
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	if (value < root->data)
		root->left = insert(root->left, value);
	else if (value > root->data)
		root->right = insert(root->right, value);

	return root;
}

int search(struct node *root, int value)
{
	if (root == NULL)
		return 0;
	if (root->data == value)
		return 1;
	if (value < root->data)
		return search(root->left, value);
	return search(root->right, value);
}

struct node *delete_node(struct node *root, int value)
{
	struct node *temp;

	if (root == NULL)
		return NULL;

	if (value < root->data) {
		root->left = delete_node(root->left, value);
	} else if (value > root->data) {
		root->right = delete_node(root->right, value);
	} else if (root->left == NULL) {
		temp = root->right;
		free(root);
		return temp;
	} else if (root->right == NULL) {
		temp = root->left;
		free(root);
		return temp;
	} else {
		temp = root->right;
		while (temp->left != NULL)
			temp = temp->left;
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}

	return root;
}

void display(struct node *root)
{
	if (root != NULL) {
		display(root->left);
		printf("%d ", root->data);
		display(root->right);
	}
}

int main(void)
{
	int choice, value;

	while (1) {
		printf("\n1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Enter value: ");
			scanf("%d", &value);
			root = insert(root, value);
			printf("Value inserted.\n");
			break;

		case 2:
			printf("Enter value: ");
			scanf("%d", &value);
			if (search(root, value)) {
				root = delete_node(root, value);
				printf("Value deleted.\n");
			} else {
				printf("Value not found.\n");
			}
			break;

		case 3:
			printf("Enter value: ");
			scanf("%d", &value);
			if (search(root, value))
				printf("Value found.\n");
			else
				printf("Value not found.\n");
			break;

		case 4:
			printf("Inorder: ");
			display(root);
			printf("\n");
			break;

		case 5:
			return 0;

		default:
			printf("Invalid choice.\n");
		}
	}
}
