struct numberstack *function_push_number(struct numberstack *top,double to_push)
{
    if (top == NULL)
    {
        top = (struct numberstack *)malloc(sizeof(struct numberstack));
        top->next = NULL;
        top->element = to_push;
        return top;
    }
    struct numberstack *tmp;
    tmp = top;
    top = (struct numberstack *)malloc(sizeof(struct numberstack));
    top->next = tmp;
    top->element = to_push;
    return top;
}