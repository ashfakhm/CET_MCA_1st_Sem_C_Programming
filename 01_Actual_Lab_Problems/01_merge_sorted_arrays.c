#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int first[MAX_SIZE];
    int second[MAX_SIZE];
    int merged[MAX_SIZE * 2];
    int first_count;
    int second_count;
    int first_index = 0;
    int second_index = 0;
    int merged_index = 0;

    printf("Enter size of first sorted array (0-%d): ", MAX_SIZE);
    if (scanf("%d", &first_count) != 1 || first_count < 0 || first_count > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }
    printf("Enter first array in sorted order: ");
    for (int index = 0; index < first_count; index++) {
        if (scanf("%d", &first[index]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    printf("Enter size of second sorted array (0-%d): ", MAX_SIZE);
    if (scanf("%d", &second_count) != 1 || second_count < 0 || second_count > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }
    printf("Enter second array in sorted order: ");
    for (int index = 0; index < second_count; index++) {
        if (scanf("%d", &second[index]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    while (first_index < first_count && second_index < second_count) {
        if (first[first_index] <= second[second_index])
            merged[merged_index++] = first[first_index++];
        else
            merged[merged_index++] = second[second_index++];
    }
    while (first_index < first_count)
        merged[merged_index++] = first[first_index++];
    while (second_index < second_count)
        merged[merged_index++] = second[second_index++];

    printf("Merged sorted array: ");
    for (int index = 0; index < merged_index; index++)
        printf("%d ", merged[index]);
    printf("\n");
    return 0;
}
