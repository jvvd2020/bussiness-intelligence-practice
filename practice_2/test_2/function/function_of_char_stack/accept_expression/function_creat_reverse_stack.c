//this function to reverse a stack
struct linkstack *function_creat_reverse_stack(struct linkstack *stack_top)
{
    struct linkstack *top = NULL; //this top is new stack's top
    while (stack_top != NULL)
    {
        top = function_push_char(top, stack_top->element);
        stack_top = stack_top->next;
    }
    return top;
}