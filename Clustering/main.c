#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
struct Clustering
{
    float calyx_length;
    float calyx_width;
    float petal_length;
    float petal_width;

    float check_calyx_length;
    float check_calyx_width;
    float check_petal_length;
    float check_petal_width;

    int instance[151];
};
struct Clustering Setosa;
struct Clustering Versicolour;
struct Clustering Virginica;

struct Instance
{
    float calyx_length;
    float calyx_width;
    float petal_length;
    float petal_width;
} flower[151];
float fucntion_ED_calculatation(struct Instance *flower, struct Clustering *cluster)
{
    float distance;

    float a = pow(flower->calyx_length - cluster->calyx_length, 2);
    float b = pow(flower->calyx_width - cluster->calyx_width, 2);
    float c = pow(flower->petal_length - cluster->petal_length, 2);
    float d = pow(flower->petal_width - cluster->petal_width, 2);

    distance = pow(a + b + c + d, 0.5);

    return distance;
}
int min(float Setosa, float Versicolour, float Virginica)
{
    if (Setosa <= Versicolour && Setosa <= Virginica)
    {
        return 1;
    }
    else if (Versicolour <= Setosa && Versicolour <= Virginica)
    {
        return 2;
    }
    else if (Virginica <= Setosa && Virginica <= Versicolour)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
void function_reset_check_value()
{
    Setosa.check_calyx_length = Setosa.calyx_length;
    Setosa.check_calyx_width = Setosa.calyx_width;
    Setosa.check_petal_length = Setosa.petal_length;
    Setosa.check_petal_width = Setosa.petal_width;

    Versicolour.check_calyx_length = Versicolour.calyx_length;
    Versicolour.check_calyx_width = Versicolour.calyx_width;
    Versicolour.check_petal_length = Versicolour.petal_length;
    Versicolour.check_petal_width = Versicolour.petal_width;

    Virginica.check_calyx_length = Virginica.calyx_length;
    Virginica.check_calyx_width = Virginica.calyx_width;
    Virginica.check_petal_length = Virginica.petal_length;
    Virginica.check_petal_width = Virginica.petal_width;
}
void function_assign_instance()
{

    for (int i = 1; i <= 150; i++) //clear the original data
    {
        Setosa.instance[i] = 0;
        Versicolour.instance[i] = 0;
        Virginica.instance[i] = 0;
    }
    for (int i = 1; i <= 150; i++) //calculate the distance then allocate each instance to corresponding Cluster
    {
        int allocation = 0;
        float distance_to_Setosa;
        float distance_to_Versicolour;
        float distance_to_Virginica;
        distance_to_Setosa = fucntion_ED_calculatation(flower + i, &Setosa);
        distance_to_Versicolour = fucntion_ED_calculatation(flower + i, &Versicolour);
        distance_to_Virginica = fucntion_ED_calculatation(flower + i, &Virginica);
        // printf("======\n");
        // printf("%f\n", distance_to_Setosa);
        // printf("%f\n", distance_to_Versicolour);
        // printf("%f\n", distance_to_Virginica);
        // printf("======\n");

        allocation = min(distance_to_Setosa, distance_to_Versicolour, distance_to_Virginica);
        if (allocation == 1)
        {
            Setosa.instance[i] = 1;
        }
        else if (allocation == 2)
        {
            Versicolour.instance[i] = 1;
        }
        else if (allocation == 3)
        {
            Virginica.instance[i] = 1;
        }
        else
        {
            // printf("allocation failed in round %d\n", i);
            // printf("%f\n", distance_to_Setosa);
            // printf("%f\n", distance_to_Versicolour);
            // printf("%f\n", distance_to_Virginica);

            // float a = pow((flower + 1)->calyx_length - Setosa.calyx_length, 2);
            // float b = pow((flower + 1)->calyx_width - Setosa.calyx_width, 2);
            // float c = pow((flower + 1)->petal_length - Setosa.petal_length, 2);
            // float d = pow((flower + 1)->petal_width - Setosa.petal_width, 2);

            // printf("calyx = %f\n", (flower + 1)->calyx_length);
            // printf("Setosa_calyx = %f\n", Setosa.calyx_length);

            // printf("a = %f\n", a);
            // printf("the a+b+c+d = %f\n", a + b + c + d);

            // exit(0);
        }
    }
}
void function_update_Cluster_attribute(struct Clustering *Clustering)
{
    int count = 0;
    float total_calyx_length = 0;
    float total_calyx_width = 0;
    float total_petal_length = 0;
    float total_petal_width = 0;
    for (int i = 1; i <= 150; i++)
    {

        if (Clustering->instance[i] == 1)
        {
            count++;
            total_calyx_length += flower[i].calyx_length;
            total_calyx_width += flower[i].calyx_width;
            total_petal_length += flower[i].petal_length;
            total_petal_width += flower[i].petal_width;
        }
    }
    if (count != 0)
    {
        Clustering->calyx_length = total_calyx_length / count;
        Clustering->calyx_width = total_calyx_width / count;
        Clustering->petal_length = total_petal_length / count;
        Clustering->petal_width = total_petal_width / count;
    }
}
int function_Cluster_arrtibutes_same_check()
{
    if (
        fabs(Setosa.check_calyx_length - Setosa.calyx_length) < 1e-6 &&
        fabs(Setosa.check_calyx_width - Setosa.calyx_width) < 1e-6 &&
        fabs(Setosa.check_petal_length - Setosa.petal_length) < 1e-6 &&
        fabs(Setosa.check_petal_width - Setosa.petal_width) < 1e-6 &&

        fabs(Versicolour.check_calyx_length - Versicolour.calyx_length) < 1e-6 &&
        fabs(Versicolour.check_calyx_width - Versicolour.calyx_width) < 1e-6 &&
        fabs(Versicolour.check_petal_length - Versicolour.petal_length) < 1e-6 &&
        fabs(Versicolour.check_petal_width - Versicolour.petal_width) < 1e-6 &&

        fabs(Virginica.check_calyx_length - Virginica.calyx_length) < 1e-6 &&
        fabs(Virginica.check_calyx_width - Virginica.calyx_width) < 1e-6 &&
        fabs(Virginica.check_petal_length - Virginica.petal_length) < 1e-6 &&
        fabs(Virginica.check_petal_width - Virginica.petal_width) < 1e-6)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int rand_i = 0;
int rand_j = 0;
int rand_k = 0;
void fucntion_initialize_start_Cluster()
{
    srand((unsigned)time(NULL));
    while (rand_i == rand_j || rand_i == rand_k || rand_j == rand_k)
    {
        rand_i = rand() % 150 + 1;
        rand_j = rand() % 150 + 1;
        rand_k = rand() % 150 + 1;
    }

    Setosa.calyx_length = flower[rand_i].calyx_length;
    Setosa.calyx_width = flower[rand_i].calyx_width;
    Setosa.petal_length = flower[rand_i].petal_length;
    Setosa.petal_width = flower[rand_i].petal_width;

    Versicolour.calyx_length = flower[rand_j].calyx_length;
    Versicolour.calyx_width = flower[rand_j].calyx_width;
    Versicolour.petal_length = flower[rand_j].petal_length;
    Versicolour.petal_width = flower[rand_j].petal_width;

    Virginica.calyx_length = flower[rand_k].calyx_length;
    Virginica.calyx_width = flower[rand_k].calyx_width;
    Virginica.petal_length = flower[rand_k].petal_length;
    Virginica.petal_width = flower[rand_k].petal_width;

    //violence mode
    // float violence11 = 0;
    // float violence12 = 0;
    // float violence13 = 0;
    // float violence14 = 0;
    // for (int i = 1; i <= 50; i++)
    // {
    //     violence11 += flower[i].calyx_length;
    //     violence12 += flower[i].calyx_width;
    //     violence13 += flower[i].petal_length;
    //     violence14 += flower[i].petal_width;
    // }
    // violence11 = violence11 / 50.0;
    // violence12 = violence12 / 50.0;
    // violence13 = violence13 / 50.0;
    // violence14 = violence14 / 50.0;

    // Setosa.calyx_length = violence11;
    // Setosa.calyx_width = violence12;
    // Setosa.petal_length = violence13;
    // Setosa.petal_width = violence14;

    // float violence21 = 0;
    // float violence22 = 0;
    // float violence23 = 0;
    // float violence24 = 0;
    // for (int i = 51; i <= 100; i++)
    // {
    //     violence21 += flower[i].calyx_length;
    //     violence22 += flower[i].calyx_width;
    //     violence23 += flower[i].petal_length;
    //     violence24 += flower[i].petal_width;
    // }
    // violence21 = violence21 / 50.0;
    // violence22 = violence22 / 50.0;
    // violence23 = violence23 / 50.0;
    // violence24 = violence24 / 50.0;

    // Versicolour.calyx_length = violence21;
    // Versicolour.calyx_width = violence22;
    // Versicolour.petal_length = violence23;
    // Versicolour.petal_width = violence24;

    // float violence31 = 0;
    // float violence32 = 0;
    // float violence33 = 0;
    // float violence34 = 0;
    // for (int i = 101; i <= 150; i++)
    // {
    //     violence31 += flower[i].calyx_length;
    //     violence32 += flower[i].calyx_width;
    //     violence33 += flower[i].petal_length;
    //     violence34 += flower[i].petal_width;
    // }
    // violence31 = violence31 / 50.0;
    // violence32 = violence32 / 50.0;
    // violence33 = violence33 / 50.0;
    // violence34 = violence34 / 50.0;

    // Virginica.calyx_length = violence31;
    // Virginica.calyx_width = violence32;
    // Virginica.petal_length = violence33;
    // Virginica.petal_width = violence34;
}
void function_accuracy_rate_and_recall_rate() //judge three cluster belonging to which group
{
    float SS = 0;
    float VeS = 0;
    float ViS = 0;
    float SVe = 0;
    float VeVe = 0;
    float ViVe = 0;
    float SVi = 0;
    float VeVi = 0;
    float ViVi = 0;
    for (int i = 1; i <= 50; i++)
    {
        if (1 == Setosa.instance[i])
        {
            SS++;
        }
        if (1 == Versicolour.instance[i])
        {
            VeS++;
        }
        if (1 == Virginica.instance[i])
        {
            ViS++;
        }
    }
    for (int i = 51; i <= 100; i++)
    {
        if (1 == Setosa.instance[i])
        {
            SVe++;
        }
        if (1 == Versicolour.instance[i])
        {
            VeVe++;
        }
        if (1 == Virginica.instance[i])
        {
            ViVe++;
        }
    }
    for (int i = 101; i <= 150; i++)
    {
        if (1 == Setosa.instance[i])
        {
            SVi++;
        }
        if (1 == Versicolour.instance[i])
        {
            VeVi++;
        }
        if (1 == Virginica.instance[i])
        {
            ViVi++;
        }
    }

    float array[7];
    array[1] = SS + VeVe + ViVi;
    array[2] = SS + ViVe + VeVi;
    array[3] = VeS + SVe + ViVi;
    array[4] = VeS + ViVe + SVi;
    array[5] = ViS + SVe + VeVi;
    array[6] = ViS + VeVe + SVi;

    float max = array[1];
    int max_number = 1;
    for (int i = 1; i <= 6; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            max_number = i;
        }
    }
    float count_for_S = 0;
    float count_for_Ve = 0;
    float count_for_Vi = 0;
    for (int i = 1; i <= 150; i++)
    {
        if (Setosa.instance[i] == 1)
        {
            count_for_S++;
        }
        if (Versicolour.instance[i] == 1)
        {
            count_for_Ve++;
        }
        if (Virginica.instance[i] == 1)
        {
            count_for_Vi++;
        }
    }

    if (1 == max_number)
    {
        printf("the sequence is S Ve Vi\n");
        printf("the accuracy rate:%.2f\n", (SS + VeVe + ViVi) / 150);
        printf("the recall rate:%.2f\n", (SS / count_for_S + VeVe / count_for_Ve + ViVi / count_for_Vi) / 3);
    }
    if (2 == max_number)
    {
        printf("the sequence is S Vi Ve\n");
        printf("the accuracy rate:%.2f\n", (SS + ViVe + VeVi) / 150);
        printf("the recall rate:%.2f\n", (SS / count_for_S + ViVe / count_for_Vi + VeVi / count_for_Ve) / 3);
    }
    if (3 == max_number)
    {
        printf("the sequence is Ve S Vi\n");
        printf("the accuracy rate:%.2f\n", (VeS + SVe + ViVi) / 150);
        printf("the recall rate:%.2f\n", (VeS / count_for_Ve + SVe / count_for_S + ViVi / count_for_Vi) / 3);
    }
    if (4 == max_number)
    {
        printf("the sequence is Ve Vi S\n");
        printf("the accuracy rate:%.2f\n", (VeS + ViVe + SVi) / 150);
        printf("the recall rate:%.2f\n", (VeS / count_for_Ve + ViVe / count_for_Vi + SVi / count_for_S) / 3);
    }
    if (5 == max_number)
    {
        printf("the sequence is Vi S Ve\n");
        printf("the accuracy rate:%.2f\n", (ViS + SVe + VeVi) / 150);
        printf("the recall rate:%.2f\n", (ViS / count_for_Vi + SVe / count_for_S + VeVi / count_for_Ve) / 3);
    }
    if (6 == max_number)
    {
        printf("the sequence is Vi Ve S\n");
        printf("the accuracy rate:%.2f\n", (ViS + VeVe + SVi) / 150);
        printf("the recall rate:%.2f\n", (ViS / count_for_Vi + VeVe / count_for_Ve + SVi / count_for_S) / 3);
    }
}
int main()
{
    FILE *fp;
    fp = fopen("data", "r");
    if (NULL == fp)
    {
        printf("file open failed\n");
    }
    int tmp;
    for (int i = 1; i <= 150; i++) //get data from file
    {
        if (fscanf(fp, "%d%f%f%f%f", &tmp, &flower[i].calyx_length, &flower[i].calyx_width, &flower[i].petal_length, &flower[i].petal_width) == EOF)
        {
            printf("fsacnf function failed\n");
        }
    }
    fclose(fp);

    fucntion_initialize_start_Cluster(); //initialize data
    int count = 1;
    while (function_Cluster_arrtibutes_same_check())
    {

        function_assign_instance();
        function_reset_check_value();
        function_update_Cluster_attribute(&Setosa);
        function_update_Cluster_attribute(&Versicolour);
        function_update_Cluster_attribute(&Virginica);
        printf("\nround %d\n", count);
        printf("----------\n");
        printf("CLASS 1:\n");
        for (int i = 1; i <= 150; i++)
        {
            if (Setosa.instance[i] == 1)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
        printf("\n");
        printf("CLASS 2:\n");
        for (int i = 1; i <= 150; i++)
        {
            if (Versicolour.instance[i] == 1)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
        printf("\n");
        printf("CLASS 3:\n");
        for (int i = 1; i <= 150; i++)
        {
            if (Virginica.instance[i] == 1)
            {
                printf("%d ", i);
            }
        }

        // printf("\n====================\n");
        count++;
    }
    printf("\n");
    printf("CLASS 1 %f\n", Setosa.calyx_length);
    printf("CLASS 1 %f\n", Setosa.calyx_width);
    printf("CLASS 1 %f\n", Setosa.petal_length);
    printf("CLASS 1 %f\n", Setosa.petal_width);
    printf("\n");
    printf("CLASS 2 %f\n", Versicolour.calyx_length);
    printf("CLASS 2 %f\n", Versicolour.calyx_width);
    printf("CLASS 2 %f\n", Versicolour.petal_length);
    printf("CLASS 2 %f\n", Versicolour.petal_width);
    printf("\n");
    printf("CLASS 3 %f\n", Virginica.calyx_length);
    printf("CLASS 3 %f\n", Virginica.calyx_width);
    printf("CLASS 3 %f\n", Virginica.petal_length);
    printf("CLASS 3 %f\n", Virginica.petal_width);
    printf("ATTRIBUTES\n");
    printf("CLASS 1:\n");

    for (int i = 1; i <= 150; i++)
    {
        if (Setosa.instance[i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("\n");
    printf("CLASS 2:\n");
    for (int i = 1; i <= 150; i++)
    {
        if (Versicolour.instance[i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("\n");
    printf("CLASS 3:\n");
    for (int i = 1; i <= 150; i++)
    {
        if (Virginica.instance[i] == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n\n");
    function_accuracy_rate_and_recall_rate();
    printf("i = %d\n", rand_i);
    printf("j = %d\n", rand_j);
    printf("k = %d\n", rand_k);
    return 0;
}