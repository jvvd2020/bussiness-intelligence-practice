void output_array(char *head)
{
    int i;
    for (i = 0; *(head + i) != '\0'; i++)
    {
        printf("%c", *(head + i));
    }
    putchar('\n');
}