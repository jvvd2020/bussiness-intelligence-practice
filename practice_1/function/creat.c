struct link *creat(struct link *head) //创建链表函数
{   
    struct link *p_present, *p_open;
    p_present = p_open = (struct link *)malloc(LEN); //分配内存空间
    if (p_present == NULL)                           //判断是否成功创建
    {
        printf("分配内存失败\n");
        printf("回车退出\n");
        getchar();
        getchar();
        exit(0);
    }
    head = p_present;
    while ((p_open->data=getchar()) != '\n') //输入为回车结束创建
    {
        p_present = p_open;                  //将操作对象移动至下一个节点
        p_open = (struct link *)malloc(LEN); //分配新的内存
        p_present->next = p_open;            //指向下一个节点
        if (p_open == NULL)                  //判断是否分配失败
        {
            printf("分配内存失败\n");
            return 0;
        }
    }
    p_present->next = NULL; //尾节点null结束创建
    struct link *tmp;       //创建空头节点
    tmp = (struct link *)malloc(LEN);
    tmp->next = head;
    return tmp;
}