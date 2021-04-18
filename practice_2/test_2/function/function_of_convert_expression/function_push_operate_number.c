struct numberstack *function_push_operate_number(struct numberstack *top,double element_to_push)
{
    if (top == NULL)
    {
        top = (struct numberstack *)malloc(sizeof(struct numberstack));
        top->next = NULL;
        top->element = element_to_push;
        return top;
    }
    struct numberstack *tmp;
    tmp = top;
    top = (struct numberstack *)malloc(sizeof(struct numberstack));
    top->next = tmp;
    top->element = element_to_push;
    return top;
}