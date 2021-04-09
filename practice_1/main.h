struct link //定义结构体
{
    char data;
    struct link *next;
};
#define LEN sizeof(struct link)

struct link *head_a;            //定义第一个链表头指针
struct link *head_b;            //定义第二个链表头指针
struct link *head_c;            //定义第合并链表头指针
struct link *head_intersection; //定义第交集链表头指针
struct link *head_substraction; //定义第差集链表头指针

struct link *test;

#include "./function/creat.c"
#include "./function/output_list.c"
#include "./function/sort.c"
#include "./function/delete_repeat.c"
#include "./function/list_add.c"
#include "./function/intersection.c"
#include "./function/substraction.c"

#include "./function2/creat_array.c"
#include "./function2/delete_repeat_array.c"
#include "./function2/output_array.c"
#include "./function2/sort_array.c"
#include "./function2/unionlist.c"
#include "./function2/intersectionlist.c"
#include "./function2/substractionlist.c"

char a[15], b[15], intersection_array[30], substraction_array[30], union_array[30];
