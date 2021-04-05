void substraction(struct link *head_a, struct link *head_intersection, struct link *substraction)
{
    struct link *head_a_node;
    struct link *head_intersection_node;
    struct link *head_substraction_node;
    head_a_node = head_a->next;
    head_intersection_node = head_intersection->next;
    head_substraction_node = substraction->next;
    while (head_a_node != NULL)
    {
        while (head_intersection_node != NULL)
        {
            if (head_a_node->data == head_intersection_node->data)
            {
                break;
            }
            head_intersection_node = head_intersection_node->next;
        }

        if (head_intersection_node == NULL) //全部遍历结束
        {
            head_substraction_node->data = head_a_node->data;
            head_substraction_node->next = (struct link *)malloc(LEN);
            head_substraction_node = head_substraction_node->next;
            head_substraction_node->next = NULL;
        }
        head_a_node = head_a_node->next;//链表a跳到下一个节点
        head_intersection_node = head_intersection->next;//交集链表复位
    }
  
}
