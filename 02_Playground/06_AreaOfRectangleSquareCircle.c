#include <stdio.h>

int main(void)
{
    printf("Please Enter What You Want To Find Area Of\n");

    printf("If Circle Then Type C\n");
    printf("If Rectangle Then Type R\n");
    printf("If Square Then Type S\n");

    char shape;
    double area;

    scanf(" %c", &shape);

    if (shape == 'c')
    {
        shape = 'C';
    }
    if (shape == 'r')
    {
        shape = 'R';
    }
    if (shape == 's')
    {
        shape = 'S';
    }

    switch (shape)
    {
    case 'C':
    {
        double radius;

        printf("Enter radius: ");
        scanf("%lf", &radius);

        area = 3.14159 * radius * radius;

        printf("Area of Circle = %lf\n", area);
        break;
    }

    case 'R':
    {
        double length, width;

        printf("Enter length: ");
        scanf("%lf", &length);

        printf("Enter width: ");
        scanf("%lf", &width);

        area = length * width;

        printf("Area of Rectangle = %lf\n", area);
        break;
    }

    case 'S':
    {
        double side;

        printf("Enter side: ");
        scanf("%lf", &side);

        area = side * side;

        printf("Area of Square = %lf\n", area);
        break;
    }

    default:
        printf("Invalid Shape You Want Area To Find\n");
    }

    return 0;
}