void output_list(struct link *head) //输出链表函数
{
    struct link *pt;
    pt = head->next;
    while (pt != NULL)
    {
     
        printf("%c", pt->data);
        pt = pt->next;
    }
}