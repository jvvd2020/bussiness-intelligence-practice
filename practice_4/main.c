#include <stdio.h>
#include <stdlib.h>
struct BinaryTree
{
    char data;
    struct BinaryTree *left_child;
    struct BinaryTree *right_child;
};
struct BinaryTree *tree_a = NULL;
// struct BinaryTree *function_node_init(struct BinaryTree *t)
// {
//     t->left_child = NULL;
//     t->right_child = NULL;
//     return t;
// }
int in_order_travel(struct BinaryTree *t)
{
    if (t)
    {
        in_order_travel(t->left_child);
        printf("%c", t->data);
        in_order_travel(t->right_child);
    }
    return 0;
}
int pre_order_travel(struct BinaryTree *t)
{
    if (t)
    {
        printf("%c", t->data);
        in_order_travel(t->left_child);
        in_order_travel(t->right_child);
    }
    return 0;
}
int last_order_travel(struct BinaryTree *t)
{
    if (t)
    {
        in_order_travel(t->left_child);
        in_order_travel(t->right_child);
        printf("%c", t->data);
    }
    return 0;
}
struct BinaryTree *creat_bintree(struct BinaryTree *t)
{
    // printf("input # means null tree\n");
    // printf("hint AB##CDF###EG##H##\n");
    char ch;
    ch = getchar();
    if (ch == '+')
    {
        in_order_travel(tree_a);
    }
    if (ch == '#')
    {

        return NULL;
    }
    else
    {
        t = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
        t->left_child = NULL; //init node
        t->right_child = NULL;
        t->data = ch;
        t->left_child = creat_bintree(t->left_child);
        t->right_child = creat_bintree(t->right_child);
        return t;
    }
}
int count(struct BinaryTree *t)
{
    if (t == NULL)
    {
        return 0;
    }
    else if (t->left_child == NULL && t->right_child == NULL)
    {
        return 1;
    }
    else
    {
        return count(t->left_child) + count(t->right_child);
    }
}
int main()

{

    int option;

    while (option != 6)
    {
        system("clear");
        printf("  you have four options:\n");
        printf("1.creat a bin tree\n");
        printf("2.pre\n");
        printf("3.in\n");
        printf("4.last\n");
        printf("5.count\n");
        printf("6.quit\n");
        printf("input your option:\n");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            system("clear");
            printf("creat a bin tree\n");
            tree_a = creat_bintree(tree_a);
            break;
        case 2:
            system("clear");
            pre_order_travel(tree_a);
            printf("\n");
            getchar();
            break;
        case 3:
            system("clear");
            in_order_travel(tree_a);
            printf("\n");
            getchar();
            break;
        case 4:
            system("clear");
            last_order_travel(tree_a);
            printf("\n");
            getchar();
            break;
        case 5:
            system("clear");
            printf("the number is %d\n", count(tree_a));
            getchar();
            break;
        case 6:
            option = 6;
            break;
        }
    }
    return 0;
}