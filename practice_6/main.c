#include <stdio.h>
#include <stdlib.h>
int graph[7][7];
int point_DFSed[7];

void function_print_graph()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {

            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
void function_creat_graph()
{
    printf("input the start point(0-6):\n");
    int start_point;
    scanf("%d", &start_point);
    printf("input the end point(0-6):\n");
    getchar();
    int end_number;
    scanf("%d", &end_number);
    getchar();
    graph[start_point][end_number] = 1;
}
void funcion_DFS(int point)
{
    printf("%d", point);
    point_DFSed[point] = 1;
    for (int i = 0; i < 7; i++) //try every possible point
    {
        if (i == point)
        {
            continue;
        }
        if (point_DFSed[i] == 0 && graph[point][i] != 0)
        {
            point_DFSed[i] = 1;
            funcion_DFS(i);
        }
    }
}
void function_clear_DFSed()
{
    for (int i = 0; i < 7; i++)
    {
        point_DFSed[i] = 0;
    }
}
void function_BFS(int start_point)
{

    int stop_record = 0;
    int BFS_array[7];
    BFS_array[0] = start_point;
    point_DFSed[0] = 1;
    stop_record++;
    for (int i = 0; i < 7; i++)
    {
        if (graph[0][i] != 0)
        {
            BFS_array[stop_record] = i;
            point_DFSed[i] = 1;
            stop_record++;
        }
    }

    for (int i = 0; i < 7; i++) //traverse BFS array
    {

        for (int j = 0; j < 7; j++) //traverse point nearby BFS_array[i]
        {
            if (graph[BFS_array[i]][j] != 0 && point_DFSed[j] == 0)
            {
                BFS_array[stop_record] = j;
                if (stop_record == 6)
                {
                    for (int i = 0; i < 7; i++)
                    {
                        printf("%d", BFS_array[i]);
                    }
                    return;
                }

                stop_record++;
            }
        }
    }
}
void function_auto()
{
    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[0][3] = 1;
    graph[3][0] = 1;

    graph[1][4] = 1;
    graph[4][1] = 1;

    graph[1][5] = 1;
    graph[5][1] = 1;

    graph[1][6] = 1;
    graph[6][1] = 1;

    graph[2][6] = 1;
    graph[6][2] = 1;

    graph[4][5] = 1;
    graph[5][4] = 1;
}
int main()
{
    int option;
    while (option != 4)
    {
        system("clear");
        printf("BFS and DFS\n");
        printf("you have four options:\n");
        printf("1.creat a graph\n");
        printf("2.DFS\n");
        printf("3.BFS\n");
        printf("4.quit\n");
        printf("input your option:\n");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            printf("creat a 7*7 graph\n");
            //为方便起见使用自动创建图函数
            function_auto(); //若要手动创建请将改行注释,并启用下面一行
            // function_creat_graph();
            printf("press to continue\n");
            getchar();
            break;

        case 2:
            printf("enter a number to start 0-6\n");
            int a;
            scanf("%d", &a);
            getchar();
            function_clear_DFSed();
            funcion_DFS(a);
            printf("\npress to continue\n");
            getchar();
            break;
        case 3:
            printf("enter a number to start 0-6\n");
            int b;
            scanf("%d", &b);
            getchar();
            function_clear_DFSed();
            function_BFS(b);
            printf("\npress to continue\n");
            getchar();
            break;
        case 4:
            option = 4;
            break;
        }
    }

    return 0;
}