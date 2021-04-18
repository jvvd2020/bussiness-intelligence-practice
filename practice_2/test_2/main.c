#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "main.h"
int main()
{
    system("clear");
    int choice = 9;
    printf("expression check and calculate\n");
    while (choice != 4)
    {
        if (choice != 9)
        {
            system("clear");
        }
        printf("you have four options:\n");
        printf("1.input expression\n");
        printf("2.output expression\n");
        printf("3.calculate expression\n");
        printf("4.quit\n");
        printf("enter your choice:");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            free(stack_top_of_expression_input);
            free(stack_top_of_expression_input_reverse);
            stack_top_of_expression_input = NULL;
            stack_top_of_expression_input_reverse = NULL;
            system("clear");
            stack_top_of_expression_input = function_input_expression(stack_top_of_expression_input);
            stack_top_of_expression_input_reverse = function_creat_reverse_stack(stack_top_of_expression_input);
            while (function_check_expression_correction(stack_top_of_expression_input_reverse) == 0)
            {
                system("clear");
                printf("expression is error,input again\n");
                free(stack_top_of_expression_input);
                free(stack_top_of_expression_input_reverse);
                stack_top_of_expression_input = NULL;
                stack_top_of_expression_input_reverse = NULL;

                stack_top_of_expression_input = function_input_expression(stack_top_of_expression_input);
                stack_top_of_expression_input_reverse = function_creat_reverse_stack(stack_top_of_expression_input);
            }
            break;
        case 2:
            system("clear");
            if (stack_top_of_expression_input_reverse != NULL)
            {
                printf("the expression is:\n");
                function_link_stack_print(stack_top_of_expression_input_reverse);
            }
            else
            {
                printf("no input expression!\n");
            }
            printf("press enter to continue\n");
            getchar();
            break;
        case 3:
            system("clear");
            if (stack_top_of_expression_input == NULL)
            {
                printf("no input expression!\n");
            }
            else
            {

                function_convert_middle_bracket_to_small_bracket(stack_top_of_expression_input);
                top_of_number_stack = function_convert_char_to_number_stack(top_of_number_stack, stack_top_of_expression_input);
                top_of_operator_stack = function_convert_infix_to_postfix(top_of_number_stack, top_opeartor_number_stack, top_of_operator_stack);
                printf("expression result is :\n%.2f\n", function_postfix_expression_calculation(top_of_operator_stack));

                //after calculate need to free memory
                free(top_of_number_stack);
                free(top_of_operator_stack);
                free(top_opeartor_number_stack);
                top_of_number_stack = NULL;
                top_of_operator_stack = NULL;
                top_opeartor_number_stack = NULL;
            }
            printf("press enter to continue\n");
            getchar();
            break;
        case 4:
            choice = 4;
            break;
        }
    }
    return 0;
}