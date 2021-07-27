#include <stdio.h>
#include <stdlib.h>
struct haffmanNode
{
    struct haffmanNode *left_child;
    struct haffmanNode *right_child;
    struct haffmanNode *parent;
    int position;
    int weight;
    char data;
};
struct leafNode
{
    int weight;
    struct haffmanNode *p;
    struct leafNode *next;
};

//variables
struct leafNode *head_of_leafNode = NULL;
int size_of_character = 0;
struct leafNode **copy_of_leafNode_link; //free

//part_0 fundemental
void part_0_creat_leafNode_link(struct haffmanNode *tmp)
{
    struct leafNode *to_add_link;
    to_add_link = (struct leafNode *)malloc(sizeof(struct leafNode));
    to_add_link->p = tmp;
    to_add_link->weight = tmp->weight;
    if (head_of_leafNode == NULL)
    {
        to_add_link->next = NULL;
        head_of_leafNode = to_add_link;
    }
    else
    {
        to_add_link->next = head_of_leafNode;
        head_of_leafNode = to_add_link;
    }
}
void part_0_copy_leafNode_link(struct leafNode *head) //head node has data
{
    //allocate space for pointer of leafNode
    //pointer array
    copy_of_leafNode_link = (struct leafNode **)malloc(size_of_character * sizeof(struct leafNode *));
    for (int i = 0; i < size_of_character; i++)
    {
        *(copy_of_leafNode_link + i) = head;
        head = head->next;
    }
}
//part_1 creat haffmantree
void part_1_init_character()
{
    copy_of_leafNode_link = NULL;
    head_of_leafNode = NULL;
    int character_size;
    printf("input the size of the character,hint:10\n");
    scanf("%d", &character_size);
    size_of_character = character_size;
    getchar();
    printf("input character and weight\n");
    printf("EXAMLPE:a12b5e7f8i14k23s3t15y2z11\n");
    for (int i = 0; i < character_size; i++)
    {
        struct haffmanNode *tmp;
        tmp = (struct haffmanNode *)malloc(sizeof(struct haffmanNode));
        scanf("%c", &tmp->data);
        scanf("%d", &tmp->weight);
        part_0_creat_leafNode_link(tmp);
    }
    //copy leafNode link immediately when head node has a data
    part_0_copy_leafNode_link(head_of_leafNode);
    //add a head node without data
    struct leafNode *white_head_node;
    white_head_node = (struct leafNode *)malloc(sizeof(struct leafNode));
    white_head_node->next = head_of_leafNode;
    head_of_leafNode = white_head_node;
}
struct leafNode *part_1_find_min_weight(struct leafNode *white_head_node)
{
    struct leafNode *pre_of_min;
    struct leafNode *next_of_min;
    struct leafNode *min = white_head_node->next;
    int tmp_min = white_head_node->next->weight;
    struct leafNode *head = white_head_node->next;
    while (head != NULL)
    {
        if (head->weight < tmp_min)
        {
            tmp_min = head->weight; //find min weight
            min = head;             //find pointer of min weight
        }
        head = head->next;
    }
    //find pre && next of min
    while (white_head_node->next != NULL)
    {
        if (white_head_node->next == min)
        {
            pre_of_min = white_head_node;
            next_of_min = min->next;
        }
        white_head_node = white_head_node->next;
    }
    //cut the min out and link the leafNode_link back
    min->next = NULL;               //cut
    pre_of_min->next = next_of_min; //link
    return min;
}
void part_1_merge_two_min_node_and_link()
{
    //find min node,save it in tmp0
    struct leafNode *tmp0;
    tmp0 = part_1_find_min_weight(head_of_leafNode);
    //find min node,save it in tmp1
    struct leafNode *tmp1;
    tmp1 = part_1_find_min_weight(head_of_leafNode);

    //creat a new haffmanNode
    struct haffmanNode *haff_node_of_merge;
    haff_node_of_merge = (struct haffmanNode *)malloc(sizeof(struct haffmanNode));
    haff_node_of_merge->left_child = tmp0->p;
    haff_node_of_merge->right_child = tmp1->p;
    haff_node_of_merge->weight = tmp0->weight + tmp1->weight;
    haff_node_of_merge->parent = NULL;
    //set tmp1's and tmp2's parent&&position
    tmp0->p->parent = haff_node_of_merge;
    tmp0->p->position = 0;

    tmp1->p->parent = haff_node_of_merge;
    tmp1->p->position = 1;

    //creat a new leafNode
    struct leafNode *leaf_merge_node;
    leaf_merge_node = (struct leafNode *)malloc(sizeof(struct leafNode));
    leaf_merge_node->weight = tmp0->weight + tmp1->weight;
    leaf_merge_node->p = haff_node_of_merge;

    //link the leafNode into leafNode_link
    leaf_merge_node->next = head_of_leafNode->next;
    head_of_leafNode->next = leaf_merge_node;
}
void part_1_creat_haffman_tree()
{

    while (head_of_leafNode->next->next != NULL)
    {
        part_1_merge_two_min_node_and_link();
    }
}

//part_2 encode character
void part_2_haffman_encode()
{
    for (int i = 0; i < size_of_character; i++)
    {
        struct haffmanNode *tmp;
        tmp = (*(copy_of_leafNode_link + i))->p;
        printf("%c:", tmp->data);
        while (tmp->parent != NULL)
        {
            printf("%d", tmp->position);
            tmp = tmp->parent;
        }
        printf("\n");
    }
}

//test code
void test_output_leafNode(struct leafNode *head)
{
    head = head->next; //avoid segmentation fault
    while (head != NULL)
    {
        printf("the data is %c\n", head->p->data);
        printf("the weight is %d\n", head->weight);
        printf("--------------\n");
        head = head->next;
    }
}
void test_copy_leafNode(struct leafNode **array_first)
{
    for (int i = 0; i < size_of_character; i++)
    {
        printf("the data is %c\n", (*(array_first + i))->p->data);
        printf("the weight is %d\n", (*(array_first + i))->weight);
        printf("--------------\n");
    }
}
void test_find_min()
{
    struct leafNode *min;
    min = part_1_find_min_weight(head_of_leafNode);
    printf("the min weight is %d\n", min->weight);
    // test_output_leafNode(head_of_leafNode);//test:✅
}
int main()
{
    // test_output_leafNode(head_of_leafNode);    //test data input ,test:✅
    // test_copy_leafNode(copy_of_leafNode_link); //test copy leafNode ,test:✅
    //test_find_min()                             //test find min,test:✅

    int option;
    while (option != 5)
    {
        system("clear");
        printf("haffman encode\n");
        printf("you have four options:\n");
        printf("1.input character size\n");
        printf("2.input character and weight\n");
        printf("3.creat a haffman tree\n");
        printf("4.show the haffman code\n");
        printf("5.quit\n");
        printf("input your option:\n");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            system("clear");
            part_1_init_character();
            part_1_creat_haffman_tree();
            printf("press to continue\n");
            getchar();
            getchar();
            break;
        case 2:
            system("clear");
            printf("you need to run 1 first\n");
            getchar();
            break;
        case 3:
            system("clear");
            printf("you need to run 1 first\n");
            getchar();
            break;
        case 4:
            system("clear");
            part_2_haffman_encode();
            printf("press to continue\n");
            getchar();
            break;
        case 5:
            option = 5;
            break;
        }
    }

    return 0;
}