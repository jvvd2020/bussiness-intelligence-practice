void function_input_a_decimal()
{
    scanf("%d", &n);
    whether_input_a_decimal = 1;
}
void function_input_a_base()
{
    scanf("%d", &m);
    whether_input_a_base = 1;
}
struct Sequential *stack_init()
{
    struct Sequential *s;
    s = (struct Sequential *)malloc(sizeof(struct Sequential));
    if (s == NULL)
    {
        printf("memory allocate failed\n");
        return NULL;
    }
    s->top = -1;
    return s;
}
void push(struct Sequential *s, int x)
{
    if (s->top >= 9)
    {
        printf("stack overflow\n");
        exit(0);
    }
    s->top++;
    s->stack[s->top] = x;
}
int function_convert()
{
    if (whether_input_a_base == 0 || whether_input_a_decimal == 0)
    {
        if (whether_input_a_base == 0)
        {
            printf("------------------------\n");
            printf("you have to input a base\n");
            printf("------------------------\n");
        }
        if (whether_input_a_decimal == 0)
        {
            printf("---------------------------\n");
            printf("you have to input a decimal\n");
            printf("---------------------------\n");
        }
        return 0;
    }
    struct Sequential *stack_pointer;
    stack_pointer = stack_init();
    int tmp_for_n = n;
    while (n)
    {
        push(stack_pointer, (n % m));
        n /= m;
    }
    n = tmp_for_n;
    printf("----------------------------\n");
    printf("the result is:");
    while (stack_pointer->top >= 0)
    {
        printf("%d", stack_pointer->stack[stack_pointer->top]);
        stack_pointer->top--;
    }
    printf("\n----------------------------\n");
    free(stack_pointer);
    stack_pointer = NULL;
    printf("\n");
    printf("\n");
    return 0;
}