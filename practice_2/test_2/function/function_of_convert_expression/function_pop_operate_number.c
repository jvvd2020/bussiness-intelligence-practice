struct numberstack *function_pop_operate_number(struct numberstack *top)
{

    if (top == NULL)
    {
        return NULL;
    }

    struct numberstack *tmp;
    tmp = top;
    top = top->next;
    free(tmp);
    
    return top;
}