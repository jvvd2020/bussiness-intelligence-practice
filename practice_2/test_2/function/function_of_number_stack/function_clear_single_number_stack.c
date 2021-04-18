struct single_number_count_stack *function_clear_single_number_stack(struct single_number_count_stack *top)
{
    struct single_number_count_stack *tmp = NULL;
    while (top != NULL)
    {
        tmp = top;
        top = top->next;
        free(tmp);
    }
    return NULL;
}