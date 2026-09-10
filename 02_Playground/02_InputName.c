#include <stdio.h>

int main(void)
{
    char name[25];
    printf("Om Krim Kutti Chaatha...\
        \nI guessed Your Name Alredy.. ");

    printf("\nPlease Enter Your Name And.. \
        \nI Will Say My Guess Is Correct Or Not \n");
    scanf("%24s", name);

    printf("And My Guess Was %s", name);
    printf("\nYou're Name Is %s", name);
    printf("\nSo My Guess Was Correct");

    return 0;
}