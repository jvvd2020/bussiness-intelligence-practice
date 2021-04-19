double function_postfix_expression_calculation(struct numberstack *top)
{
    struct numberstack *first_num = NULL;
    struct numberstack *second_num = NULL;
    struct numberstack *first_node_of_opearator = NULL;
    //find the first node of opearator
    first_node_of_opearator = top;
    while (first_node_of_opearator != NULL)
    {
        if (first_node_of_opearator->element < 0)
        {
            break;
        }
        else
        {
            first_node_of_opearator = first_node_of_opearator->next;
        }
    }

    while (first_node_of_opearator != NULL)
    {

        first_num = top;
        if (first_num->next != NULL)
        {
            while (first_num->next->next != first_node_of_opearator)
            {
                first_num = first_num->next;
            }
            second_num = first_num->next;
        }
        else
        {
            return first_num->element;
        }

        double result;
        result = calculate_two_number(first_num->element, second_num->element, first_node_of_opearator->element);
        first_num->element = result;
        first_num->next = first_node_of_opearator->next;
        free(second_num);
        struct numberstack *tmp;
        tmp = first_node_of_opearator;
        first_node_of_opearator = first_node_of_opearator->next;
        free(tmp);
    }
    return first_num->element;
}