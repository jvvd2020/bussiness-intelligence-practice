//use this function to accept expression
struct linkstack *function_push_char(struct linkstack *top, char element_to_push) 
{

    //if stack empty then init
    if (top == NULL)
    {
        top = (struct linkstack *)malloc(sizeof(struct linkstack));
        top->next = NULL;
        top->element = element_to_push;
        return top;
    }
    struct linkstack *tmp;
    tmp = top;
    top = (struct linkstack *)malloc(sizeof(struct linkstack));
    top->next = tmp;
    top->element = element_to_push;
    return top;
}