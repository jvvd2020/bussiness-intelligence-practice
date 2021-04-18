//this to pop a element from the char stack
struct linkstack *function_pop_char(struct linkstack *top)
{
    if (top == NULL)
    {
        return NULL;
    }

    struct linkstack *tmp;
    tmp = top;
    top = top->next;
    free(tmp);
    return top;
}