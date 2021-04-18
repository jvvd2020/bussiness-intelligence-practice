int function_check_expression_correction(struct linkstack *top) //ATTENTION:the stack havent free yet
{
    //creat a link stack to store these brackets
    struct linkstack *stack_of_brackets = NULL;//not free yet
    char check;
    while (top != NULL)
    {
        check = top->element;
        switch (check)
        {
        case '(':
            stack_of_brackets = function_push_char(stack_of_brackets, check);
            break;
        case '[':
            stack_of_brackets = function_push_char(stack_of_brackets, check);
            break;
        case ')':
            if (stack_of_brackets == NULL)
            {
                return 0;
            }
            if (stack_of_brackets->element != '(')
            {
                return 0;
            }
            else
            {
                stack_of_brackets = function_pop_char(stack_of_brackets);
                break;
            }
        case ']':
            if (stack_of_brackets == NULL)
            {
                return 0;
            }
            if (stack_of_brackets->element != '[')
            {
                return 0;
            }
            else
            {
                stack_of_brackets = function_pop_char(stack_of_brackets);
                break;
            }
            break;
        }
        top = top->next;
    }
    if (stack_of_brackets == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}