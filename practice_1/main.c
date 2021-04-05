#include <stdio.h>
#include <stdlib.h>
#include "main.h" //定义全局变量 头指针 创建链表过程中所需指针

int main()
{
    printf("创建第一个链表\n");
    head_a = creat(head_a); // 创建第一个链表Í
    sort(head_a);
    delete_repeat(head_a);
    printf("---------\n");

    printf("创建第二个链表\n");
    head_b = creat(head_b); //创建第二个链表
    sort(head_b);
    delete_repeat(head_b);
    printf("---------\n");

    printf("创建并集链表\n");
    head_c = creat(head_c);
    printf("---------\n");

    printf("创建交集链表\n");
    head_intersection = creat(head_intersection);
    printf("---------\n");

    printf("创建差集链表\n");
    head_substraction = creat(head_substraction);
    printf("---------\n");

    printf("链表a为:");
    output_list(head_a);
    printf("\n链表b为:");
    output_list(head_b);

    list_add(list_add(head_c,head_a),head_b);//并集
    sort(head_c);
    delete_repeat(head_c);    
    printf("\n并集为:");
    output_list(head_c);


    intersection(head_a, head_b, head_intersection); //交集
    printf("\n交集为:");
    output_list(head_intersection);
    
    substraction(head_a, head_intersection, head_substraction);
    printf("\n差集为:");
    sort(head_substraction);
    output_list(head_substraction);
    printf("\n");
    return 0;
}