void function_convert_middle_bracket_to_small_bracket(struct linkstack *top)
{
    char change;
    while (top != NULL)
    {
        change = top->element;
        switch (change)
        {
        case '[':
            top->element = '(';
            break;
        case ']':
            top->element = ')';
            break;
        default:
            break;
        }
        top = top->next;
    }
}