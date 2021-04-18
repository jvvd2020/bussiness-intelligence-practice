//this function to output a stack
void function_link_stack_print(struct linkstack *top) 
{
    while (top != NULL)
    {
        printf("%c", top->element);
        top = top->next;
    }
    printf("\n");
}