double function_convert_opeartor_to_minus(char opeartor)
{
    switch (opeartor)
    {
    case '(': // make '(' = -1
        return -1;
        break;
    case ')': // make ')' = -2
        return -2;
        break;
    case '+': // make '+' = -3
        return -3;
        break;
    case '-': // make '-' = -4
        return -4;
        break;
    case '*': // make '*' = -5
        return -5;
        break;
    case '/': // make '/' = -6
        return -6;
        break;
    }
    return 0;
}