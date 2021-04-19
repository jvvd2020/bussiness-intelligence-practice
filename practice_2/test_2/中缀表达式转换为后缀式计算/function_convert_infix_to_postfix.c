struct numberstack *function_convert_infix_to_postfix(struct numberstack *top_of_expression, struct numberstack *top_of_number, struct numberstack *top_of_opearator)
{
    int i, j;
    while (top_of_expression != NULL)
    {
        i = (int)(top_of_expression->element);
        if (top_of_expression->element >= 0)
        {
            top_of_number = function_push_operate_number(top_of_number, top_of_expression->element);
        }
        else
        {
            if (top_of_opearator == NULL)
            {
                top_of_opearator = function_push_operate_number(top_of_opearator, top_of_expression->element);
            }
            else
            {
                // if (top_of_opearator->element == -1)
                // {
                //     top_of_opearator = function_push_operate_number(top_of_opearator, top_of_expression->element);
                // }else if (/* condition */)
                // {
                //     /* code */
                // }
                // if (i == -2)
                // {
                //     while ((int)top_of_opearator->element != -1)
                //     {
                //         getchar();
                //         printf("hello\n");
                //         double new;
                //         new = calculate_two_number(top_of_number->next->element, top_of_number->element, top_of_opearator->element);
                //         top_of_number = function_pop_operate_number(top_of_number);
                //         top_of_number = function_pop_operate_number(top_of_number);
                //         top_of_number = function_push_operate_number(top_of_number, new);
                //         top_of_opearator = function_pop_operate_number(top_of_opearator);
                //     }
                //     top_of_opearator = function_pop_operate_number(top_of_opearator);
                // }

                switch (i)
                {
                case -1:
                    top_of_opearator = function_push_operate_number(top_of_opearator, top_of_expression->element);
                    break;
                case -2:
                    // printf("oooo1\n");
                    // printf("top of opearator is :%.2f\n",top_of_opearator->element);
                    // j = (int)top_of_opearator->element;
                    // printf("j = %d\n",j);
                    while ((int)top_of_opearator->element != -1)
                    {
                        double new;
                        new = calculate_two_number(top_of_number->next->element, top_of_number->element, top_of_opearator->element);
                        top_of_number = function_pop_operate_number(top_of_number);
                        top_of_number = function_pop_operate_number(top_of_number);
                        top_of_number = function_push_operate_number(top_of_number, new);
                        top_of_opearator = function_pop_operate_number(top_of_opearator);
                        // j = (int)top_of_opearator->element;
                    }
                    top_of_opearator = function_pop_operate_number(top_of_opearator);
                    break;
                case -3:
                case -4:
                    if ((int)top_of_opearator->element == -3 || (int)top_of_opearator->element == -4 || (int)top_of_opearator->element == -1)
                    {
                        top_of_opearator = function_push_operate_number(top_of_opearator, top_of_expression->element);
                    }
                    else
                    {
                        double new;
                        new = calculate_two_number(top_of_number->next->element, top_of_number->element, top_of_opearator->element);
                        top_of_number = function_pop_operate_number(top_of_number);
                        top_of_number = function_pop_operate_number(top_of_number);
                        top_of_number = function_push_operate_number(top_of_number, new);
                        top_of_opearator = function_pop_operate_number(top_of_opearator);
                        top_of_opearator = function_push_operate_number(top_of_opearator, top_of_expression->element);
                    }
                    break;
                case -5:
                case -6:
                    top_of_opearator = function_push_operate_number(top_of_opearator, top_of_expression->element);
                    break;
                    // default:
                    //     while ((int)top_of_opearator->element != -1)
                    //     {
                    //         getchar();
                    //         getchar();
                    //         getchar();
                    //         printf("hello\n");
                    //         double new;
                    //         new = calculate_two_number(top_of_number->next->element, top_of_number->element, top_of_opearator->element);
                    //         top_of_number = function_pop_operate_number(top_of_number);
                    //         top_of_number = function_pop_operate_number(top_of_number);
                    //         top_of_number = function_push_operate_number(top_of_number, new);
                    //         top_of_opearator = function_pop_operate_number(top_of_opearator);
                    //     }
                    //     top_of_opearator = function_pop_operate_number(top_of_opearator);
                    //     break;
                }
            }
        }
        top_of_expression = top_of_expression->next;
    }
    //move opearator number element to opeartor stack
    while (top_of_number != NULL)
    {
        top_of_opearator = function_push_operate_number(top_of_opearator, top_of_number->element);
        top_of_number = top_of_number->next;
    }
    return top_of_opearator;
}