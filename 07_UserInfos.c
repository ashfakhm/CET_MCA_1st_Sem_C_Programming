#include <stdio.h>

int main()
{
   char username[25];
    int age;
    int subjectcount;

    printf("Enter Your Name: ");
    scanf("%s", username);

    printf("Enter Your Age: ");
    scanf("%d", &age);

    printf("Enter Number Of Subjects You Have: ");
    scanf("%d", &subjectcount);

    if (subjectcount <= 0)
    {
        printf("Invalid number of subjects.\n");
    }

    int subjectmarks[subjectcount];
    int total = 0;

    for (int subject = 0; subject < subjectcount; subject++)
    {
        printf("Enter marks for Subject %d: ", subject + 1);
        scanf("%d", &subjectmarks[subject]);

        total += subjectmarks[subject];
    }

    float average = (float)total / subjectcount;

    float percentage = (float)total / (subjectcount * 100) * 100;

    printf("\n----- Details -----\n");
    printf("Name: %s\n", username);
    printf("Age: %d\n", age);
    printf("Number of Subjects: %d\n", subjectcount);
    printf("Total Marks: %d\n", total);
    printf("Average Marks: %f\n", average);
    printf("Percentage: %f\n", percentage);

    if (age >= 18)
    {
        printf("\nAs You're age is 18 and Equal Aged You are Eligible to vote\n");
    }
    else
    {
        printf("\nAs You're age is Below 18 You Are Not eligible to vote\n");
    }

    return 0;
}
