void intersectionlist(char *a, char *b, char *intersection_array)
{
    int i, j, k = 0;
    for (i = 0; *(a + i) != '\0'; i++)
    {
        for (j = 0; *(b + j) != '\0'; j++)
        {
            if (*(a + i) == *(b + j))
            {
                *(intersection_array + k) = *(a + i);
                k++;
            }
        }
    }
}