void intersection(struct link *list_a, struct link *list_b, struct link *list_intersection)//对已排序且删除重复元素的链表进行合并
{
    struct link *list_a_node, *list_b_node, *list_intersection_node;
    list_a_node = list_a->next;
    list_b_node = list_b->next;
    list_intersection_node = list_intersection->next;
    while (list_a_node != NULL)
    {
        while (list_b_node != NULL)
        {

            if (list_a_node->data == list_b_node->data)
            {
                list_intersection_node->data = list_b_node->data;
                list_intersection_node->next = (struct link *)malloc(LEN);
                list_intersection_node = list_intersection_node->next;
                list_intersection_node->next = NULL;
                break;
            }
                list_b_node = list_b_node->next;
        }
        list_a_node = list_a_node -> next;
        list_b_node = list_b->next;
    }
}