# Details

Date : 2021-04-04 10:39:55

Directory /Users/jvvd/Documents/C_file

Total : 9 files,  234 codes, 11 comments, 31 blanks, all 276 lines

[summary](results.md)

## Files 集合的并、交和差运算
1. 问题描述 编制一个能演示执行集合的并、交和差运算的程序。 2. 基本要求 1.集合的元素限定为小写字母字符[‘a’...‘z’]。 2.演示程序以用户和计算机的对话方式执行。
3. 测试数据
1.Set1=”magazine”，Set2=”paper”,
’Set1 ᴜ Set2=”aegimnprz”, Set1 ∩ Set2=”ae”,Set1 -
Set2=”gimnz” 2.Set1=”operation”，Set2=”error data”,
’Set1 ᴜ Set2=”adeinoprt”, Set1 ∩ Set2=”aeort”,Set1 -
Set2=”inp”。 4. 实现提示
先以有序链表表示集合 5. 问题分析
在以有序链表表示集合的情况下，则涉及了链表的创建、插入、删除和排序 等操作，当集合变得有序后，求两个集合的交集、并集和差集就变得相对比较 简单了，也就是两个链表中的元素去比对，求共有的元素，两者的所有元素以 及一个链表中存在而另一个链表中不存在的元素。
6. 定义链表的数据结构 Typedef struct LNode
{
      ElemType data;
      Struct  LNode *next;
}LinkList;
7. 创建有序集合链表 (1)根据用户输入一个集合的多个元素后，为每个元素创建一个新的链表节 点，并插入到链表的尾部。
(2)将链表排序，使用直接插入法对链表排序。

  (3)删除链表中重复、不符合要求的数据。
8. 求集合的并集 (1)新建一个单链表集合C，将集合A中的元素全部加到单链表C中，然后遍历 链表集合B，如果该元素在集合A中不存在，就将该元素加入到集合C中，最后遍 历输出链表C中的元素，就是集合AB并集。 (2)新建一个单链表集合C，遍历集合A中的元素，如果该元素在集合B中也存 在，就将该元素加入到集合C中，最后遍历输出链表C中的元素，就是集合AB交 集。 (3)新建一个单链表集合C，遍历集合A中的元素，如果该元素在集合B中不存 在，就将该元素加入到集合C中，最后遍历输出链表C中的元素，就是集合AB差 集。
9. 集合的交、并和差运算程序的编写
(1)创建控制台工程
(2)定义结构体、函数和宏
文件: main.cpp list.cpp list.h 3.创建单链表
creatList(LinkList *&L, ElemType a[],int n) 4.对链表排序
sortList(LinkList *&Head)
5.求并集
unionList(LinkList *ha,LinkLIst *hb,LinkList *&hc) 6.求交集
intersectionList(LinkList *ha,LinkLIst *hb,LinkList *&hc) 7.求差集
subtractionList(LinkList *ha,LinkLIst *hb,LinkList *&hc)

| filename | language | code | comment | blank | total |
| :--- | :--- | ---: | ---: | ---: | ---: |
| [practice_1/function/creat.c](/practice_1/function/creat.c) | C | 30 | 0 | 0 | 30 |
| [practice_1/function/delete_repeat.c](/practice_1/function/delete_repeat.c) | C | 19 | 2 | 1 | 22 |
| [practice_1/function/intersection.c](/practice_1/function/intersection.c) | C | 24 | 0 | 1 | 25 |
| [practice_1/function/list_add.c](/practice_1/function/list_add.c) | C | 18 | 4 | 1 | 23 |
| [practice_1/function/output_list.c](/practice_1/function/output_list.c) | C | 10 | 0 | 1 | 11 |
| [practice_1/function/sort.c](/practice_1/function/sort.c) | C | 42 | 5 | 7 | 54 |
| [practice_1/function/substraction.c](/practice_1/function/substraction.c) | C | 29 | 0 | 3 | 32 |
| [practice_1/main.c](/practice_1/main.c) | C | 43 | 0 | 10 | 53 |
| [practice_1/main.h](/practice_1/main.h) | C++ | 19 | 0 | 7 | 26 |

[summary](results.md)