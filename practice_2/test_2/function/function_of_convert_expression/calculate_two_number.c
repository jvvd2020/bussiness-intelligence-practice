double calculate_two_number(double num1,double num2,double opearator)
{
    int i;
    i = (int)opearator; 
    switch (i)
    {
    case -3:
    return num1+num2;
        break;
    case -4:
    return num1-num2;
        break;
    case -5:
    return num1*num2;
        break;
    case -6:
    return num1/num2;
        break;
    }
    return 0;
}