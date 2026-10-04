#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct node *createNode(int value)
{
	struct node *newnode = malloc(sizeof(*newnode));
	if (newnode == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	newnode->data = value;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

void insert_at_beginning(struct node **head, int value)
{
	struct node *newnode = createNode(value);
	newnode->next = *head;

	if (*head != NULL) {
		(*head)->prev = newnode;
	}
	*head = newnode;
}

void insert_at_end(struct node **head, int value)
{
	struct node *newnode = createNode(value);
	if (*head == NULL) {
		*head = newnode;
		return;
	}

	struct node *current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newnode;
	newnode->prev = current;
}

int insert_at_position(struct node **head, int value, int position)
{
	if (position < 1) {
		return 0;
	}

	if (position == 1) {
		insert_at_beginning(head, value);
		return 1;
	}

	struct node *current = *head;
	int current_position = 1;
	while (current != NULL && current_position < position - 1) {
		current = current->next;
		current_position++;
	}

	if (current == NULL) {
		return 0;
	}

	if (current->next == NULL) {
		insert_at_end(head, value);
		return 1;
	}

	struct node *newnode = createNode(value);
	newnode->next = current->next;
	newnode->prev = current;
	current->next->prev = newnode;
	current->next = newnode;
	return 1;
}

int delete_at_position(struct node **head, int position)
{
	struct node *current = *head;
	int current_position = 1;
	while (current != NULL && current_position < position) {
		current = current->next;
		current_position++;
	}

	if (position < 1 || current == NULL) {
		return 0;
	}

	if (current->prev != NULL) {
		current->prev->next = current->next;
	} else {
		*head = current->next;
	}

	if (current->next != NULL) {
		current->next->prev = current->prev;
	}

	free(current);
	return 1;
}

int search_value(struct node *head, int value)
{
	int position = 1;
	while (head != NULL) {
		if (head->data == value)
			return position;
		head = head->next;
		position++;
	}
	return 0;
}

void display_forward(const struct node *head)
{
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}

	printf("Forward: ");
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void display_backward(const struct node *head)
{
	if (head == NULL) {
		printf("List is empty.\n");
		return;
	}

	while (head->next != NULL) {
		head = head->next;
	}

	printf("Backward: ");
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->prev;
	}
	printf("\n");
}

void free_list(struct node *head)
{
	while (head != NULL) {
		struct node *next = head->next;
		free(head);
		head = next;
	}
}

int main(void)
{
	struct node *head = NULL;
	int choice;
	int value;
	int position;

	while (1) {
		printf("\n--- Doubly Linked List ---\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Display forward and backward\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");

		if (scanf("%d", &choice) != 1) {
			printf("Invalid input.\n");
			free_list(head);
			return 1;
		}

		switch (choice) {
		case 1:
			printf("Enter position to insert (starting from 1): ");
			if (scanf("%d", &position) != 1) {
				printf("Invalid input.\n");
				free_list(head);
				return 1;
			}
			printf("Enter a value: ");
			if (scanf("%d", &value) != 1) {
				printf("Invalid input.\n");
				free_list(head);
				return 1;
			}
			if (insert_at_position(&head, value, position))
				printf("%d inserted at position %d.\n", value, position);
			else
				printf("Invalid position. Insert from 1 to the next position after the list.\n");
			break;

		case 2:
			printf("Enter position to delete (starting from 1): ");
			if (scanf("%d", &position) != 1) {
				printf("Invalid input.\n");
				free_list(head);
				return 1;
			}
			if (delete_at_position(&head, position))
				printf("Node at position %d deleted.\n", position);
			else
				printf("Invalid position.\n");
			break;

		case 3:
			printf("Enter value to search: ");
			if (scanf("%d", &value) != 1) {
				printf("Invalid input.\n");
				free_list(head);
				return 1;
			}
			position = search_value(head, value);
			if (position != 0)
				printf("%d found at position %d.\n", value, position);
			else
				printf("Value not found.\n");
			break;

		case 4:
			display_forward(head);
			display_backward(head);
			break;

		case 5:
			free_list(head);
			return 0;

		default:
			printf("Invalid choice. Please choose 1 to 5.\n");
		}
	}
}
