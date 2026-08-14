#include <stdio.h>

int main()
{
    double number1, number2, number3;

    printf("Please enter the three numbers to find the largest.\n");

    printf("Type Number 1: ");
    scanf("%lf", &number1);

    printf("Type Number 2: ");
    scanf("%lf", &number2);

    printf("Type Number 3: ");
    scanf("%lf", &number3);

    if (number1 >= number2 && number1 >= number3)
    {
        printf("%lf is Largest", number1);
    }
    else if (number2 >= number1 && number2 >= number3)
    {
        printf("%lf is Largest", number2);
    }
    else
    {
        printf("%lf is Largest", number3);
    }

    return 0;
}
