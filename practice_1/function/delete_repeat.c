int delete_repeat(struct link *pt)
{
    // 前期准备
    struct link *current, *to_connect;
    current = pt->next;

    //循环结束标志
    while (current->next != NULL)
    {
        if (current->data == current->next->data) //删除部分
        {
            to_connect = current->next->next;
            free(current->next);
            current->next = to_connect;
        }
        else
        {
            current = current->next; //指针下移
        }
    }
    return 0;
}