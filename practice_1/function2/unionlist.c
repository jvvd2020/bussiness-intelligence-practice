void unionlist(char *a, char *b, char *union_array)
{
    int i, j;
    for (i = 0; *(a + i) != '\0'; i++)
    {
        *(union_array + i) = *(a + i);
    }
    for (j = 0; *(b + j) != '\0'; j++, i++)
    {
        *(union_array + i) = *(b + j);
    }
}