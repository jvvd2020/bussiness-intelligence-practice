struct single_number_count_stack *function_push_single_number_to_stack(struct single_number_count_stack *top, int single_number_to_push)
{
    if (top == NULL)
    {
        top = (struct single_number_count_stack *)malloc(sizeof(struct single_number_count_stack));
        top->next = NULL;
        top->element = single_number_to_push;
        return top;
    }
    struct single_number_count_stack *tmp;
    tmp = top;
    top = (struct single_number_count_stack *)malloc(sizeof(struct single_number_count_stack));
    top->next = tmp;
    top->element = single_number_to_push;
    return top;
}