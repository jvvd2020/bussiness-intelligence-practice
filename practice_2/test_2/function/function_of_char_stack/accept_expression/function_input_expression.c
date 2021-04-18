struct linkstack *function_input_expression(struct linkstack *top)
{
    char a;
    printf("input the expression\n");
    while ((a = getchar()) != '\n')
    {
        top = function_push_char(top, a);
    }
    return top;
}