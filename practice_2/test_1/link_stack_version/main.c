#include <stdio.h>
#include <stdlib.h>
struct remainder
{
    int element;
    struct remainder *next;
};
struct remainder *function_push_remainder(struct remainder *top, int element_to_push)
{
    if (top == NULL)
    {
        top = (struct remainder *)malloc(sizeof(struct remainder));
        top->element = element_to_push;
        top->next = NULL;
        return top;
    }
    else
    {
        struct remainder *tmp;
        tmp = top;
        top = (struct remainder *)malloc(sizeof(struct remainder));
        top->element = element_to_push;
        top->next = tmp;
    }
    return top;
}
void function_convert_num(int decimal, int base)
{
    struct remainder *top_of_remainder_stack = NULL; //free:top_top_of_remainder_stack
    while (decimal != 0)
    {
        top_of_remainder_stack = function_push_remainder(top_of_remainder_stack, decimal % base);
        decimal /= base;
    }
    //print remainder stack
    printf("the converted number is:\n");
    while (top_of_remainder_stack != NULL)
    {
        struct remainder *tmp;
        printf("%d", top_of_remainder_stack->element);
        tmp = top_of_remainder_stack;
        top_of_remainder_stack = top_of_remainder_stack->next;
        free(tmp); // free:top_top_of_remainder_stack
    }
    printf("\n");
    printf("press enter to continue\n");
    getchar();
}
int main()
{
    system("clear");
    printf("number converted\n");
    printf("you have four options:\n");
    printf("1.input a decimal\n");
    printf("2.input a base\n");
    printf("3.convert the decimal\n");
    printf("4.quit\n");
    printf("input your option:\n");
    int choice = 0;
    int decimal = 0, base = 0;
    while (choice != 4)
    {
        system("clear");
        printf("you have four options:\n");
        printf("1.input a decimal\n");
        printf("2.input a base\n");
        printf("3.convert the decimal\n");
        printf("4.quit\n");
        printf("input your option:\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            system("clear");
            printf("input a decimal\n");
            scanf("%d", &decimal);
            break;
        case 2:
            system("clear");
            printf("input a base\n");
            scanf("%d", &base);
            break;
        case 3:
            system("clear");
            if (decimal == 0 || base == 0)
            {

                if (decimal == 0)
                {
                    printf("need to reinput a decimal\n");
                }
                if (base == 0)
                {
                    printf("need to reinput a base\n");
                }
                printf("press enter to continue\n");
                getchar();
                break;
            }
            function_convert_num(decimal, base);
            break;
        case 4:
            choice = 4;
            break;
        }
    }
    return 0;
}