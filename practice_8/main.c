#include <stdio.h>
#include <stdlib.h>
struct Student
{
    char name[10];
    int score;
};
int number_of_student;
struct Student *pointer_of_Student_array;

void function_print_selected_info()
{
    printf("the info are as follows\n");
    for (int i = 0; i < number_of_student; i++)
    {
        if (i == 0)
        {
            printf("order\t|name\t|score\n");
        }

        printf("%d\t|%s\t|%d\n", i + 1, (pointer_of_Student_array + i)->name, (pointer_of_Student_array + i)->score);
    }
}
void fucntion_input_student_info()
{
    printf("input the number of student\n");
    scanf("%d", &number_of_student);
    pointer_of_Student_array = (struct Student *)malloc(number_of_student * sizeof(struct Student));
    printf("input the student info\n");
    for (int i = 0; i < number_of_student; i++)
    {
        printf("input the NO.%d student's name\n", i + 1);
        scanf("%s", (pointer_of_Student_array + i)->name);
        printf("input the score of NO.%d student\n", i + 1);
        scanf("%d", &(pointer_of_Student_array + i)->score);
    }
    function_print_selected_info();
}

void function_select_sort()
{
    for (int i = 0; i < number_of_student; i++)
    {
        for (int j = i + 1; j < number_of_student; j++)
        {
            if ((pointer_of_Student_array + i)->score < (pointer_of_Student_array + j)->score)
            {
                struct Student tmp = *(pointer_of_Student_array + i);
                *(pointer_of_Student_array + i) = *(pointer_of_Student_array + j);
                *(pointer_of_Student_array + j) = tmp;
            }
        }
    }
    function_print_selected_info();
}
void function_quick_sort(int low, int high)
{
    if (low < high)
    {
        int i = low;
        int j = high;
        struct Student tmp = *(pointer_of_Student_array + low);
        while (i < j)
        {
            while (i < j && (pointer_of_Student_array + j)->score >= tmp.score)
            {
                j--;
            }
            if (i < j)
            {
                *(pointer_of_Student_array + i) = *(pointer_of_Student_array + j);
            }
            while (i < j && (pointer_of_Student_array + i)->score <= tmp.score)
            {
                i++;
            }
            if (i < j)
            {
                *(pointer_of_Student_array + j) = *(pointer_of_Student_array + i);
            }
        }
        *(pointer_of_Student_array + i) = tmp;

        function_quick_sort(low, i - 1);
        function_quick_sort(i + 1, high);
    }
}
void function_insert_sort()
{
    struct Student tmp;
    for (int i = 1; i < number_of_student; i++)
    {
        tmp = *(pointer_of_Student_array + i);
        int j;
        for (j = i - 1; j >= 0 && tmp.score > (pointer_of_Student_array + j)->score; j--)
        {
            *(pointer_of_Student_array + j + 1) = *(pointer_of_Student_array + j);
        }
        *(pointer_of_Student_array + j + 1) = tmp;
    }
    function_print_selected_info();
}
void function_shell_sort()
{
    for (int gap = number_of_student / 2; gap > 0; gap = gap / 2) //cycle for gap control
    {
        for (int i = 0; i < gap; i++) //cycle for how many sub-sequence
        {
            for (int j = i + gap; j < number_of_student; j = j + gap) //cycle to select each sub-sequence
            {
                //insert start
                struct Student tmp = *(pointer_of_Student_array + j);
                int k;
                for (k = j - gap; k >= 0 && tmp.score > (pointer_of_Student_array + k)->score; k = k - gap)
                {
                    *(pointer_of_Student_array + k + gap) = *(pointer_of_Student_array + k);
                }
                *(pointer_of_Student_array + k + gap) = tmp;
            }
        }
    }
    function_print_selected_info();
}
int main()
{

    int option;
    while (option != 6)
    {
        system("clear");
        printf("SORT\n");
        printf("you have four options:\n");
        printf("1.input student info.\n");
        printf("2.insert sort\n");
        printf("3.quick sort\n");
        printf("4.select sort\n");
        printf("5.shell sort\n");
        printf("6.quit\n");
        printf("input your option:\n");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            fucntion_input_student_info();
            printf("press to continue\n");
            getchar();
            break;
        case 2:
            function_insert_sort();
            printf("press to continue\n");
            getchar();
            break;
        case 3:
            function_quick_sort(0, number_of_student - 1);
            function_print_selected_info();
            printf("press to continue\n");
            getchar();
            break;
        case 4:
            function_select_sort();
            printf("press to continue\n");
            getchar();
            break;
        case 5:
            function_shell_sort();
            printf("press to continue\n");
            getchar();
            break;
        case 6:
            printf("press to continue\n");
            option = 6;
            break;
        }
    }

    return 0;
}