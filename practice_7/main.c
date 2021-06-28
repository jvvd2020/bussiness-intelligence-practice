#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct StudentInfo
{
    char name;
    int age;
    int grade;
    char major;
};
struct StudentInfo list[5];
void function_input_student_info()
{
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("input student name:\n");
    //     scanf("%s",list[i].name);
    //     printf("input student age:\n");
    //     scanf("%d",&list[i].age);
    //     printf("input student grade:\n");
    //     scanf("%d",&list[i].grade);
    //     printf("input student major:\n");
    //     scanf("%s",list[i].major);
    // }
    list[0].name = 'a';
    list[0].age = 12;
    list[0].age = 6;
    list[0].major = 'M';

    list[1].name = 'b';
    list[1].age = 12;
    list[1].age = 6;
    list[1].major = 'C';

    list[2].name = 'c';
    list[2].age = 12;
    list[2].age = 6;
    list[2].major = 'E';

    list[3].name = 'd';
    list[3].age = 12;
    list[3].age = 6;
    list[3].major = 'C';

    list[4].name = 'e';
    list[4].age = 12;
    list[4].age = 6;
    list[4].major = 'C';
}
void function_output_student_info()
{
    printf("|name\t|age\t|grade\t|major\t|\n");
    for (int i = 0; i < 5; i++)
    {
        printf("|%c\t|%d\t|%d\t|%c\t|\n", list[i].name, list[i].age, list[i].grade, list[i].major);
    }
}
void function_line_search()
{
    printf("input the name of the student\n");
    char tmp = getchar();
    getchar();
    for (int i = 0; i < 5; i++)
    {
        if (list[i].name == tmp)
        {
            printf("|name\t|age\t|grade\t|major\t|\n");
            printf("|%c\t|%d\t|%d\t|%c\t|\n", list[i].name, list[i].age, list[i].grade, list[i].major);
            return;
        }
    }
    printf("the student does not exist\n");
    return;
}
void function_bin_search()
{
    struct StudentInfo tmp;
    int low = 0;
    int high = 5;
    int mid;
    char key;
    printf("input the student name:\n");
    key = getchar();
    getchar();
    for (int i = 0; i < 5; i++)

    {
        for (int j = i + 1; j < 5; j++)
        {
            if (list[i].name > list[j].name)
            {
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == list[mid].name)
        {
            printf("|name\t|age\t|grade\t|major\t|\n");
            printf("|%c\t|%d\t|%d\t|%c\t|\n", list[mid].name, list[mid].age, list[mid].grade, list[mid].major);
            return;
        }
        else if (key < list[mid].name)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("the student does not exist\n");
}

int main()

{

    int option;
    while (option != 6)
    {
        system("clear");
        printf("bin search and order search\n");
        printf("you have six options:\n");
        printf("1.show student number\n");
        printf("2.enter student info\n");
        printf("3.output student info\n");
        printf("4.select by order\n");
        printf("5.select by bin\n");
        printf("6.quit\n");
        printf("input your option:\n");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            printf("student number is 5\n");
            printf("press to continue\n");
            getchar();
            break;
        case 2:
            function_input_student_info();
            printf("simulate manully input student info,please wait\n");
            printf("|name\t|age\t|grade\t|major\t|\n");
            for (int i = 0; i < 5; i++)
            {
                sleep(1);
                printf("|%c\t|%d\t|%d\t|%c\t|\n", list[i].name, list[i].age, list[i].grade, list[i].major);
            }
            printf("press to continue\n");
            getchar();
            break;
        case 3:
            function_output_student_info();
            getchar();
            break;
        case 4:
            function_line_search();
            getchar();
            break;
        case 5:
            function_bin_search();
            getchar();
            break;
        case 6:
            option = 6;
            break;
        }
    }
}