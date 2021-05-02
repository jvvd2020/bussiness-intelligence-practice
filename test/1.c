/*并集:新建一个单链表集合C，将集合A中的元素全部加到单链表C中，然后遍历链表集合B，
如果该元素在集合A中不存在，就将该元素加入到集合C中，最后遍历输出链表C中的元素，
就是集合AB并集。
 交集:新建一个单链表集合C，遍历集合A中的元素，如果该元素在集合B中也存在，
就将该元素加入到集合C中，最后遍历输出链表C中的元素，就是集合AB交集。
 差集:新建一个单链表集合C，遍历集合A中的元素，如果该元素在集合B中不存在，
就将该元素加入到集合C中，最后遍历输出链表C中的元素，就是集合AB差集
*/
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(LNode)
typedef struct LNode
{
    char data;
    struct LNode *next;
} LNode;              //声明节点的数据类型
LNode *list1, *list2; //声明两个表头

LNode *creatList_TailInsert(LNode *list) //尾插法创建链表
{
    int e;
    LNode *S, *R, *L; // 声明个节点 S是插入的新节点 L指向头节点 R指向尾节点
    L = (LNode *)malloc(LEN); 
    R=L;            //新建的空表 只有一个节点 既L=R L=R 出现了指针错误 5
    
    while (e != 9999)
    
    {
        scanf("%d", &e);
        S = (LNode *)malloc(LEN);
        S->data = e;
        R->next = S; //在R后插入节点S
        R = S;       //插入后保持R仍是尾节点
    }
    R->next = NULL; //链表结束 R指向NULL
    return L;       //命名链表可以用链表的头指针
}

void link_order(LNode *)
{
    LNode *pb, *pf, *head;     //pf指向 前直节点 pb指向后置节点 temp存储数据域的一个值 方便交换
    char temp;
    if(head==NULL||head->next==NULL)     //只有一个节点和 空链表不需要排序           
    {
        printf("Do without order\n");
   
    }
    while(pf->next!=NULL)
    {
        if (pf->data>=pb->data)
        {
            temp=pf->data;
            pf->data=pb->data;
            pb->data=temp;         
        }
        pf=pf->next;
        pb=pb->next;
    }
   printf("The sorting is done\n");
}

void print(LNode *list)
{
     LNode *p ;
     p=list;
    if(list==NULL)
         printf("ERROR!\n");
    while (p!=NULL)
        {
           printf("%d",p->data);
         p=p->next;
        }
 }

int main()
{   printf("Create the first linked list\n");
    creatList_TailInsert(list1);
    printf("Create the second linked list\n");
    creatList_TailInsert(list2);
    printf("Create Complete\n");
    link_order(list1);
    link_order(list2);
    print(list1);
    print(list2);
