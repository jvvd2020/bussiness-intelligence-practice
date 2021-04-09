void creat_array(char *head)
{
    int i;
    char c;
    while ((c = getchar()) != '\n')
    {
        *(head++) = c;
    }
}