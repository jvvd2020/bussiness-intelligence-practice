#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int main()
{
    system("clear");
    printf("*************************\n");
    printf("**  data type transfer **\n");
    printf("*************************\n");

    int next = 1;
    int choice;
    while (next != 4)
    {
        system("clear");
        printf("you have four choice now\n");
        printf("1. input a decimal\n");
        printf("2. input the converted base\n");
        printf("3. to convert\n");
        printf("4. quit\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            system("clear");
            printf("input a decimal\n");
            function_input_a_decimal();
            printf("press to continue\n");
            getchar();
            getchar();
            break;

        case 2:
            system("clear");
            printf("input a base\n");
            function_input_a_base();
            printf("press to continue\n");
            getchar();
            break;
        case 3:
            system("clear");
            function_convert();
            printf("press to continue\n");
            getchar();
            break;
        case 4:
            next = 4;
            break;
        }
    }

    return 0;
}