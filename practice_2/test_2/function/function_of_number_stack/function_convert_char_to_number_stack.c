struct numberstack *function_convert_char_to_number_stack(struct numberstack *number_stack_top, struct linkstack *char_stack_top)
{
    struct single_number_count_stack *top_of_single_number_stack=NULL;
    while (char_stack_top != NULL)
    {
        if (char_stack_top->element >= '0' && char_stack_top->element <= '9') //if element is number
        {
            top_of_single_number_stack = function_push_single_number_to_stack(top_of_single_number_stack, (int)(char_stack_top->element - 48));
        }
        else
        {
            if (top_of_single_number_stack != NULL) //first need to deal with single numbers then to deal with opearators
            {
                //first convert single number to real number
                number_stack_top = function_push_number(number_stack_top, function_convert_single_stack_number_to_double_number(top_of_single_number_stack));
                //then clear the single number stack
                top_of_single_number_stack = function_clear_single_number_stack(top_of_single_number_stack);
                //convert the opearator to minus then push it to number stack
                number_stack_top = function_push_number(number_stack_top, function_convert_opeartor_to_minus(char_stack_top->element));
            }
            else
            {
                number_stack_top = function_push_number(number_stack_top, function_convert_opeartor_to_minus(char_stack_top->element));
            }
        }
        char_stack_top = char_stack_top->next;
    }

    if (top_of_single_number_stack != NULL)
    {
        number_stack_top = function_push_number(number_stack_top, function_convert_single_stack_number_to_double_number(top_of_single_number_stack));
        top_of_single_number_stack = function_clear_single_number_stack(top_of_single_number_stack);
    }

    return number_stack_top;
}