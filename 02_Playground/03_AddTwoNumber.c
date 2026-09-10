#include <stdio.h>

int main(void)
{
    double number1, number2;
    printf("Please Enter The Two Numbers You Want To Know The Sums");

    printf("\nType Number 1 : ");
    scanf("%lf", &number1);

    printf("Type Number 2 : ");
    scanf("%lf", &number2);

    double sum;
    sum = number1 + number2;

    printf("The Sum Of Two Numbers Is %f", sum);

    return 0;
}