void sort_array(char *head)
{
    int i, j;
    char tmp;
    for (i = 0; *(head + i + 1) != '\0'; i++)
    {
        for (j = i + 1; *(head + j) != '\0'; j++)
        {
            if (*(head + j) < *(head + i))
            {
                tmp = *(head + i);
                *(head + i) = *(head + j);
                *(head + j) = tmp;
            }
        }
    }
}