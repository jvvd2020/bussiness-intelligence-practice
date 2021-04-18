char Precede(SElemType t1,SElemType t2)
{
    SElemType f;
    switch (t2)
    {
    case '+':
    case '-':
        if (t1 == '(' || t1 == '#')
            f = '<';
        else
            f = '>';
        break;
    case ' * ':
    case '/':
        if(t1 == ' * ' || t1 == ' /' || t1 == ')')
            f = '>';
        else f = '<';
        break;
    case '(':
        if (t1 == ')')
        {
            printf(" 括 号 不 匹 配 \n ");
            exit(OVERFLOW);
        }
        else
            f = '<';
        break;
    case ')':
        switch (t1)
        {
        case '(':
            f = '=';
            break;
        case '#':
            printf(" 缺乏左括号\n");
            exit(OVERFLOW);
        default:
            f = '>';
        }
        break;
    case '#':
        switch (t1)
        {
        case '#':
            f = '=';
            break;
        case '(':
            t1, SElemType
                    printf(" 缺乏右括号\n");
t2) //判断两符号的优先关系
exit(OVERFLOW);
        default:
            f = '>';
        }
    }
    return f; }
