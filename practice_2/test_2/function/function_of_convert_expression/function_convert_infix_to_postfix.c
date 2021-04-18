struct numberstack *function_convert_infix_to_postfix(struct numberstack *top_of_expression, struct numberstack *top_of_number, struct numberstack *top_of_opearator)
{
    while (top_of_expression != NULL)
    {
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
                int i;
                i = (int)top_of_expression->element;
                switch (i)
                {
                case -1:
                    top_of_opearator = function_push_operate_number(top_of_opearator, top_of_expression->element);
                    break;
                case -2:
                    while (top_of_opearator->element != -1)
                    {
                        double new;
                        new = calculate_two_number(top_of_number->next->element, top_of_number->element, top_of_opearator->element);
                        top_of_number = function_pop_operate_number(top_of_number);
                        top_of_number = function_pop_operate_number(top_of_number);
                        top_of_opearator = function_pop_operate_number(top_of_opearator);
                        top_of_number = function_push_operate_number(top_of_number, new);
                    }
                    top_of_opearator = function_pop_operate_number(top_of_opearator);
                    break;
                case -3:
                case -4:
                    if (top_of_number->element == -3 || top_of_number->element == -4 || top_of_number->element == -1)
                    {
                        top_of_opearator = function_push_operate_number(top_of_opearator, top_of_opearator->element);
                    }
                    else
                    {
                        double new;
                        new = calculate_two_number(top_of_number->next->element, top_of_number->element, top_of_opearator->element);
                        top_of_number = function_pop_operate_number(top_of_number);
                        top_of_number = function_pop_operate_number(top_of_number);
                        top_of_opearator = function_pop_operate_number(top_of_opearator);
                        top_of_number = function_push_operate_number(top_of_number, new);
                        top_of_opearator = function_push_operate_number(top_of_opearator,top_of_expression->element);
                    }
                    break;
                case -5:
                case -6:
                    top_of_opearator = function_push_operate_number(top_of_opearator, top_of_expression->element);
                    break;
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