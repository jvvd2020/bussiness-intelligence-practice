struct link *list_add(struct link *end_of_receiver, struct link *adder)
{
    struct link *receiver_last_node;
    receiver_last_node = end_of_receiver;
    struct link *open;
    struct link *new_node_to_add;
    new_node_to_add = adder->next;
    while (new_node_to_add != NULL)
    {
        open = (struct link *)malloc(LEN);
        receiver_last_node->next = open;
        receiver_last_node->next->data = new_node_to_add->data;
        receiver_last_node = receiver_last_node->next; //move forward
        new_node_to_add = new_node_to_add->next;       //move forward
    }
    receiver_last_node->next = NULL;
    return receiver_last_node;
}