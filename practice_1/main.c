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
    printf("------------\n创建数组a\n");
    creat_array(a);
    printf("------------\n创建数组b\n");
    creat_array(b);

    sort_array(a);
    sort_array(b);

    delete_repeat_array(a);
    delete_repeat_array(b);

    printf("数组a为:");
    output_array(a);
    printf("数组b为:");
    output_array(b);
    unionlist(a, b, union_array);
    sort_array(union_array);
    delete_repeat_array(union_array);
    printf("a,b并集为");
    output_array(union_array);

    intersectionlist(a, b, intersection_array);
    sort_array(intersection_array);
    delete_repeat_array(intersection_array);
    printf("a,b交集为");
    output_array(intersection_array);

    substractionlist(a, intersection_array, substraction_array);
    sort_array(substraction_array);
    delete_repeat_array(substraction_array);
    printf("a,b差集为");
    output_array(substraction_array);

    return 0;
}