void sort(struct link *head)
{
    struct link *current, *fetch, *move, *pre, *save_fetch_next; //变量定义

    //前期的准备 双指针初始位置
    pre = head;            //空头节点定义为“前指针pre”
    current = head->next;  //第一个有数据节点定义为“current指针”
    fetch = current->next; //取出待排序链表第一个节点
    current->next = NULL; //切断链表完整性 构造已排序链表和未排序链表

    while (fetch != NULL) //待排序节点为空无节点可排序
    {
        save_fetch_next = fetch->next;
        fetch->next = NULL;      //从未排序链表中分离出来
        while (current != NULL) //已排序链表遍历到最后一个之前,排序的操作是重复的
        {
            if (fetch->data <= current->data) //当找到适合的位置的时候开始插入
            {
                pre->next = fetch;     //前指针指向待排序节点
                fetch->next = current; //待排序节点指向后一个节点   连接起来
                //双指针复位
                pre = head;
                current = head->next;
                break; //排序完毕跳出循环
            }
            else //没有找到合适的位置,将双指针后移
            {
                if (current->next != NULL) //双指针可以后移时才后移,
                {
                    pre = pre->next;
                    current = current->next;
                }
                else //不可后移时说明已经到了结尾
                {
                    current->next = fetch;
                    fetch->next = NULL;
                    //双指针复位
                    pre = head;
                    current = head->next;
                    break; //插入结束
                }
            }
        }
        //节点已经已经插入完毕取新元素
        fetch = save_fetch_next; //十分简单的一个句子
    }
    //函数结束
    
    
}
