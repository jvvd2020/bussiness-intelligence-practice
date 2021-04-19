// void test(struct single_number_count_stack *top) //function_convert_single_stack_number_to_double_number
// {
//     int a;
//     double output;
//     for (int i = 0; i < 5; i++)
//     {
//         printf("input a single number\n");
//         scanf("%d", &a);
//         top = function_push_single_number_to_stack(top,a);
//     }
//     output = function_convert_single_stack_number_to_double_number(top);
//     printf("the number is:%.2lf\n",output);
// }

// void print_operator_stack(struct numberstack *top)
// {
//     int i;
//     while (top != NULL)
//     {
//         i = (int)top->element;
//         if (i >= 0)
//         {
//             printf("%d ", i);
//         }
//         else
//         {
//             switch (i)
//             {
//             case -3:
//                 printf("+");
//                 break;
//             case -4:
//                 printf("-");
//                 break;
//             case -5:
//                 printf("x");
//                 break;
//             case -6:
//                 printf("/");
//                 break;
//             }
//         }
//         top = top->next;
//     }
//     printf("\n");
// }
#include<stdio.h>
int main()
{
    double a;
    printf("a\n");
    a = -1;
    if (a == -1)
    {
        printf("hello\n");
    }
    


    getchar();
    getchar();
    return 0;
}