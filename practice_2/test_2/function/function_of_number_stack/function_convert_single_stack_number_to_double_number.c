double function_convert_single_stack_number_to_double_number(struct single_number_count_stack *top)
{
    double result = 0;
    int bit_count = 0;
    while (top != NULL)
    {
        result += (double)((top->element) * pow(10, bit_count++));
        top = top->next;
    }
    return result;
}