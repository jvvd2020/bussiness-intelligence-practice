#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int main()
{
    printf("*************************\n");
    printf("**  data type transfer **\n");
    printf("*************************\n");
 
    int next = 1;
    int choice;
    while (next)
    {
        printf("you have four choice now\n");
        printf("1. input a decimal\n");
        printf("2. input the converted base\n");
        printf("3. to convert\n");
        printf("4. continue?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            function_input_a_decimal();
            break;

        case 2:
            function_input_a_base();
            break;
        case 3:
            function_convert();
            break;
        case 4:
            printf("press y to contunue or n to quit\n");
            char q;
            getchar();
            q = getchar();
            if (q == 'y' || q == '\n')
            {
                next = 1;
            }
            else
            {
                next = 0;
            }
            break;
        }
    }

    return 0;
}