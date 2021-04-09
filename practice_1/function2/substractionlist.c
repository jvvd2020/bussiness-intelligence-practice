void substractionlist(char *a, char *intersection_array, char *substraction_array)
{
    int i, j, k = 0;
    for (i = 0; *(a + i) != '\0'; i++)
    {
        int flag = 1;
        for (j = 0; *(intersection_array + j) != '\0'; j++)
        {
            if (*(a + i) == *(intersection_array + j))
            {
                flag = 0;
                break;
            }
        }
        if (flag != 0)
        {
            *(substraction_array + k) = *(a + i);
            flag = 1;
            k++;
        }
    }
}