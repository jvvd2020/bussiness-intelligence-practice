#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char S[100];
char T[100];
int *next = NULL;
int function_input_S(char *S, int option)
{
    for (int i = 0; i < 100; i++)
    {
        *(S + i) = '\0';
    }
    if (option == 1)
    {
        printf("input a S:\n");
    }
    else
    {
        printf("input a T:\n");
    }
    char c;
    while ((c = getchar()) != '\n')
    {
        *(S++) = c;
    }
    return 0;
}
int function_regular_match(char *S, char *T)
{
    int i, j, k;
    for (i = 0; *(S + i) != '\0'; i++)
    {
        k = i;
        if (strlen(T) + k > strlen(S))
        {
            printf("match false,there is no such string\n");
            return 0;
        }
        for (j = 0; *(T + j) != '\0'; j++)
        {
            if (*(S + k + j) != *(T + j))
            {
                k++;
                break;
            }
            if (*(T + j + 1) == '\0')
            {
                printf("match done!\n");
                printf("location is in %d\n", i);
                printf("the result is\n");
                for (int c = 0; c < i; c++)
                {
                    printf("%c", *(S + c));
                }
                int c;
                for (c = 0; *(T + c) != '\0'; c++)
                {
                    printf("\033[31m%c", *(T + c));
                }
                for (; *(S + i + c) != '\0'; i++)
                {
                    printf("\033[0m");
                    printf("%c", *(S + i + c));
                }

                printf("\033[0m");
                printf("\n");

                return 0;
            }
        }
    }
    printf("match false!no such string!\n");
    return 0;
}
int *function_calculate_next(char *T, int *next)
{
    free(next);
    next = (int *)malloc(strlen(T) * sizeof(int));
    for (int i = 0; i < strlen(T); i++)
    {
        *(next + i) = 0;
    }
    if (strlen(T) <= 2)
    {
        return next;
    }
    //when strlen is more than 3 ,excute followingπ code
    int T_length = strlen(T);
    for (int j = 2; j < T_length; j++)
    {
        for (int i = 1; i < j; i++)
        {
            char *string_left;
            char *string_right;
            string_left = (char *)malloc((j - i) * sizeof(char));
            string_right = (char *)malloc((j - i) * sizeof(char));
            for (int k = 0; k < j - i; k++)
            {
                *(string_left + k) = *(T + k);
            }
            for (int k = i, m = 0; k <= j - 1; k++, m++)
            {
                *(string_right + m) = *(T + k);
            }
            if (strcmp(string_left, string_right) == 0)
            {
                free(string_left);
                free(string_right);
                *(next + j) = j - i;
                break;
            }
            free(string_left);
            free(string_right);
        }
    }
    return next;
}
int function_kmp_match(char *S, char *T, int *next)
{
    int j = 0, k;
    for (k = 0; *(S + k) != '\0';)
    {
        if (strlen(T) + k > strlen(S))
        {
            printf("match false,there is no such string\n");
            return 0;
        }
        for (; *(T + j) != '\0'; j++)
        {
            if (*(S + k + j) != *(T + j))
            {
                j = *(next + j);
                if (j == 0)
                {
                    k++;
                }
                break;
            }
            if (*(T + j + 1) == '\0')
            {
                printf("kmp match done!\n");
                printf("location is in %d\n", k);
                printf("the result is\n");
                for (int c = 0; c < k; c++)
                {
                    printf("%c", *(S + c));
                }
                int c;
                for (c = 0; *(T + c) != '\0'; c++)
                {
                    printf("\033[31m%c", *(T + c));
                }
                for (; *(S + k + c) != '\0'; k++)
                {
                    printf("\033[0m");
                    printf("%c", *(S + k + c));
                }

                printf("\033[0m");
                printf("\n");

                return 0;
            }
        }
    }
    printf("match false!no such string!\n");
    return 0;
}
int main()
{
    int option;

    while (option != 6)
    {
        system("clear");
        printf("pattern match!\n");
        printf("you have four options:\n");
        printf("1.input a S\n");
        printf("2.input a T\n");
        printf("3.match\n");
        printf("4.value of next\n");
        printf("5.kmp match\n");
        printf("6.quit\n");
        printf("input your option:\n");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            system("clear");
            function_input_S(S, 1);
            break;
        case 2:
            system("clear");
            function_input_S(T, 0);
            break;
        case 3:
            system("clear");
            if (strlen(S) == 0 || strlen(T) == 0)
            {
                if (strlen(S) == 0)
                {
                    printf("you need to input a S\n");
                }
                if (strlen(T) == 0)
                {
                    printf("you need to input a T\n");
                }
                printf("press to continue\n");
                getchar();
                break;
            }
            function_regular_match(S, T);
            printf("press to continue\n");
            getchar();
            break;
        case 4:
            if (strlen(S) == 0 || strlen(T) == 0)
            {
                if (strlen(S) == 0)
                {
                    printf("you need to input a S\n");
                }
                if (strlen(T) == 0)
                {
                    printf("you need to input a T\n");
                }
                printf("press to continue\n");
                getchar();
                break;
            }
            next = function_calculate_next(T, next);
            for (int i = 0; i < strlen(T); i++)
            {
                printf("%d ", *(next + i));
            }
            printf("press to continue\n");
            getchar();
            break;
        case 5:
            if (strlen(S) == 0 || strlen(T) == 0)
            {
                if (strlen(S) == 0)
                {
                    printf("you need to input a S\n");
                }
                if (strlen(T) == 0)
                {
                    printf("you need to input a T\n");
                }
                printf("press to continue\n");
                getchar();
                break;
            }
            next = function_calculate_next(T, next);
            function_kmp_match(S, T, next);
            printf("press to continue\n");
            getchar();
            break;
        case 6:
            option = 6;
            break;
        }
    }
    return 0;
}