void delete_repeat_array(char *head)
{
    int i;
    for (i = 0; *(head + i) != '\0';)
    {
        if (*(head + i) == *(head + i + 1))
        {
            int j;
            for (j = i; *(head + j) != '\0'; j++)
            {
                *(head + j) = *(head + j + 1);
            }
        }
        else
        {
            i++;
        }
    }
}