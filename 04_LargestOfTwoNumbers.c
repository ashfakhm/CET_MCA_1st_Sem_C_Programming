#include <stdio.h>

int main()
{
    double number1, number2;
    printf("Please Enter The Numbers You Want To Know Which Is Largest");

    printf("\nType Number 1 : ");
    scanf("%lf", &number1);

    printf("Type Number 2 : ");
    scanf("%lf", &number2);

    if (number1 > number2)
    {
        printf("%lf is Largest", number1);
    }
    else if (number2 > number1)
    {
        printf("%lf is Largest", number2);
    }
    else
    {
        printf("Both Numbers Are Equal");
    }
    return 0;
}