#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//age attribute
#define TEEN 1
#define MIDDLE 2
#define OLD 3

//income attribute
#define LOW 1
// #define MIDDLE 2; same as age
#define HIGH 3

//student attribute
//buy_or_not
#define YES 1
#define NO 2

//reputation attribute
#define GOOD 1
#define COMMON 2

struct Dataset
{
    //unleaf node = 2
    //leaf node = 3
    int node_kind;

    // not_buy = 0
    //buy = 1
    int classify; //for output the dataset info

    int datasource[1025]; //dont use [0]

    //attribut switch can be used for entropy calculation
    //after calculation,it can be reseted as the patten for sub dataset succeeding
    int age;
    int income;
    int student;
    int reputation;

    // attribute_set
    struct Dataset *age_teen;
    struct Dataset *age_middle;
    struct Dataset *age_old;

    struct Dataset *income_low;
    struct Dataset *income_middle;
    struct Dataset *income_high;

    struct Dataset *student_yes;
    struct Dataset *student_not;

    struct Dataset *reputation_common;
    struct Dataset *reputation_good;

    //pointer for chindren
    struct Dataset *child[4]; //dont use [0]
    struct Dataset *parent;

    int parameter;
};

struct Sample //total 1024
{
    int age;
    int income;
    int student;
    int reputation;
    int buy_or_not;
} sample[1025]; //1024+1 dont use '0' from 1-1024

struct Dataset *root;
void function_test_attribute_assignment();
void function_test_calculate_attribute_entropy(struct Dataset *node);

void function_init_data()
{
    int i = 1;
    int count = 0;
    for (; i <= 64; i++)
    {
        sample[i].age = TEEN;
        sample[i].income = HIGH;
        sample[i].student = NO;
        sample[i].reputation = COMMON;
        sample[i].buy_or_not = NO;
    }
    count = i;
    for (; i <= count + 64 - 1; i++)
    {
        sample[i].age = TEEN;
        sample[i].income = HIGH;
        sample[i].student = NO;
        sample[i].reputation = GOOD;
        sample[i].buy_or_not = NO;
    }
    count = i;
    for (; i <= count + 128 - 1; i++)
    {
        sample[i].age = MIDDLE;
        sample[i].income = HIGH;
        sample[i].student = NO;
        sample[i].reputation = COMMON;
        sample[i].buy_or_not = YES;
    }
    count = i;
    for (; i <= count + 60 - 1; i++)
    {
        sample[i].age = OLD;
        sample[i].income = MIDDLE;
        sample[i].student = NO;
        sample[i].reputation = COMMON;
        sample[i].buy_or_not = YES;
    }
    count = i;
    for (; i <= count + 64 - 1; i++)
    {
        sample[i].age = OLD;
        sample[i].income = LOW;
        sample[i].student = YES;
        sample[i].reputation = COMMON;
        sample[i].buy_or_not = YES;
    }
    count = i;
    for (; i <= count + 64 - 1; i++)
    {
        sample[i].age = OLD;
        sample[i].income = LOW;
        sample[i].student = YES;
        sample[i].reputation = GOOD;
        sample[i].buy_or_not = NO;
    }
    count = i;
    for (; i <= count + 64 - 1; i++)
    {
        sample[i].age = MIDDLE;
        sample[i].income = LOW;
        sample[i].student = YES;
        sample[i].reputation = GOOD;
        sample[i].buy_or_not = YES;
    }
    count = i;
    for (; i <= count + 128 - 1; i++)
    {
        sample[i].age = TEEN;
        sample[i].income = MIDDLE;
        sample[i].student = NO;
        sample[i].reputation = COMMON;
        sample[i].buy_or_not = NO;
    }
    count = i;
    for (; i <= count + 64 - 1; i++)
    {
        sample[i].age = TEEN;
        sample[i].income = LOW;
        sample[i].student = YES;
        sample[i].reputation = COMMON;
        sample[i].buy_or_not = YES;
    }
    count = i;
    for (; i <= count + 132 - 1; i++)
    {
        sample[i].age = OLD;
        sample[i].income = MIDDLE;
        sample[i].student = YES;
        sample[i].reputation = COMMON;
        sample[i].buy_or_not = YES;
    }
    count = i;
    for (; i <= count + 64 - 1; i++)
    {
        sample[i].age = TEEN;
        sample[i].income = MIDDLE;
        sample[i].student = YES;
        sample[i].reputation = GOOD;
        sample[i].buy_or_not = YES;
    }
    count = i;
    for (; i <= count + 32 - 1; i++)
    {
        sample[i].age = MIDDLE;
        sample[i].income = MIDDLE;
        sample[i].student = NO;
        sample[i].reputation = GOOD;
        sample[i].buy_or_not = YES;
    }
    count = i;
    for (; i <= count + 32 - 1; i++)
    {
        sample[i].age = MIDDLE;
        sample[i].income = HIGH;
        sample[i].student = YES;
        sample[i].reputation = COMMON;
        sample[i].buy_or_not = YES;
    }
    count = i;
    for (; i <= count + 63 - 1; i++)
    {
        sample[i].age = OLD;
        sample[i].income = MIDDLE;
        sample[i].student = NO;
        sample[i].reputation = GOOD;
        sample[i].buy_or_not = NO;
    }
    sample[i].age = OLD;
    sample[i].income = MIDDLE;
    sample[i].student = NO;
    sample[i].reputation = GOOD;
    sample[i].buy_or_not = YES;
}
float function_entropy(struct Dataset *node)
{
    float numerator = 0;
    float denominator = 0;
    for (int i = 1; i <= 1024; i++)
    {
        if (node->datasource[i] == 1)
        {
            denominator++;
            if (sample[i].buy_or_not == YES)
            {
                numerator++;
            }
        }
    }
    printf("\nnumerator is %.1f\n", numerator);
    printf("denominator is %.1f\n\n", denominator);
    if (numerator >= 0.5 * denominator)
    {
        node->parameter = 1;
    }
    else
    {
        node->parameter = 0;
    }
    if (numerator == denominator || numerator == 0)
    {
        return 0;
    }

    return (-(numerator / denominator) * log2(numerator / denominator) - (1 - numerator / denominator) * log2(1 - numerator / denominator));
}
//this function is used to assign Dataset struture's members which are the pointers points other Dataset structure.
//Dataset structure is uesed to partition a group by attribute
void function_assignment_attribute_subset(struct Dataset *node) //mark1
{
    if (node->age == 1) //if the age attribute exists
    {
        node->age_teen = (struct Dataset *)calloc(1, sizeof(struct Dataset));
        if (node->age_teen == NULL)
        {
            printf("memory accocation failed in age_teen\n");
            exit(0);
        }
        node->age_middle = (struct Dataset *)calloc(1, sizeof(struct Dataset));
        if (node->age_middle == NULL)
        {
            printf("memory accocation failed in age_middle\n");
            exit(0);
        }
        node->age_old = (struct Dataset *)calloc(1, sizeof(struct Dataset));
        if (node->age_old == NULL)
        {
            printf("memory accocation failed in age_old\n");
            exit(0);
        }
        for (int i = 1; i <= 1024; i++)
        {
            if (node->datasource[i] == 1) //if the sample exists in dataset,select attribute in the group of corresponding dataset
            {
                if (sample[i].age == TEEN)
                {
                    node->age_teen->datasource[i] = 1;
                }
                if (sample[i].age == MIDDLE)
                {

                    node->age_middle->datasource[i] = 1;
                }
                if (sample[i].age == OLD)
                {
                    node->age_old->datasource[i] = 1;
                }
            }
        }
    }

    if (node->income == 1)
    {
        node->income_low = (struct Dataset *)calloc(1, sizeof(struct Dataset));
        if (node->income_low == NULL)
        {
            printf("memory allocation failed\n");
            exit(0);
        }
        node->income_middle = (struct Dataset *)calloc(1, sizeof(struct Dataset));
        if (node->income_middle == NULL)
        {
            printf("memory allocation failed\n");
            exit(0);
        }
        node->income_high = (struct Dataset *)calloc(1, sizeof(struct Dataset));
        if (node->income_high == NULL)
        {
            printf("memory allocation failed\n");
            exit(0);
        }
        for (int i = 1; i <= 1024; i++)
        {
            if (node->datasource[i] == 1)
            {
                if (sample[i].income == LOW)
                {

                    node->income_low->datasource[i] = 1;
                }
                if (sample[i].income == MIDDLE)
                {

                    node->income_middle->datasource[i] = 1;
                }
                if (sample[i].income == HIGH)
                {

                    node->income_high->datasource[i] = 1;
                }
            }
        }
    }

    if (node->student == 1)
    {
        node->student_yes = (struct Dataset *)calloc(1, sizeof(struct Dataset));
        if (node->student_yes == NULL)
        {
            printf("memory allocation failed in student yes \n");
            exit(0);
        }
        node->student_not = (struct Dataset *)calloc(1, sizeof(struct Dataset));
        if (node->student_not == NULL)
        {
            printf("memory allocation failed in student no\n");
            exit(0);
        }
        for (int i = 1; i <= 1024; i++)
        {
            if (node->datasource[i] == 1)
            {

                if (sample[i].student == YES)
                {
                    node->student_yes->datasource[i] = 1;
                }
                if (sample[i].student == NO)
                {
                    node->student_not->datasource[i] = 1;
                }
            }
        }
    }

    if (node->reputation == 1)
    {
        node->reputation_common = (struct Dataset *)calloc(1, sizeof(struct Dataset));
        if (node->reputation_common == NULL)
        {
            printf("memory allocation failed in reputation common\n");
            exit(0);
        }
        node->reputation_good = (struct Dataset *)calloc(1, sizeof(struct Dataset));
        if (node->reputation_good == NULL)
        {
            printf("memory allocation failed in reputation high\n");
            exit(0);
        }
        for (int i = 1; i <= 1024; i++)
        {
            if (node->datasource[i] == 1)
            {
                if (sample[i].reputation == COMMON)
                {

                    node->reputation_common->datasource[i] = 1;
                }
                if (sample[i].reputation == GOOD)
                {

                    node->reputation_good->datasource[i] = 1;
                }
            }
        }
    }
}

int function_calculate_arrtibute_entropy_return_right_entropy_attribute(struct Dataset *node)
{

    float entropy_AGE = -1;

    float entropy_INCOME = -1;

    float entropy_STUDENT = -1;

    float entropy_REPUTATION = -1;

    float total_samples = 0; //denominator of E(attributes)
    for (int i = 1; i <= 1024; i++)
    {
        if (1 == node->datasource[i])
        {
            total_samples++;
        }
    }
    //age part
    if (1 == node->age) //if age attribute exists,calculate its entropy
    {
        float count_teen = 0;
        float count_middle = 0;
        float count_old = 0;
        //'for' is for assignment
        for (int i = 1; i <= 1024; i++)
        {
            if (1 == node->age_teen->datasource[i]) //select the atrribute with the VALUE of TEEN
            {
                count_teen++;
            }
            if (1 == node->age_middle->datasource[i]) //select the atrribute with the VALUE of MIDDLE
            {
                count_middle++;
            }
            if (1 == node->age_old->datasource[i]) //select the atrribute with the VALUE of OLD
            {
                count_old++;
            }
        }

        float entropy_age_teen = 0;
        float entropy_age_middle = 0;
        float entropy_age_old = 0;
        //calculate entropy of each group of age
        entropy_age_teen = function_entropy(node->age_teen);
        entropy_age_middle = function_entropy(node->age_middle);
        entropy_age_old = function_entropy(node->age_old);
        entropy_AGE = (count_teen * entropy_age_teen + count_middle * entropy_age_middle + count_old * entropy_age_old) / total_samples;
    }
    // income part
    if (1 == node->income)
    {
        float count_low = 0;
        float count_middle = 0;
        float count_high = 0;
        //'for' is for assignment
        for (int i = 1; i <= 1024; i++)
        {
            if (1 == node->income_low->datasource[i])
            {
                count_low++;
            }
            if (1 == node->income_middle->datasource[i])
            {
                count_middle++;
            }
            if (1 == node->income_high->datasource[i])
            {
                count_high++;
            }
        }

        float entropy_income_low = 0;
        float entropy_income_middle = 0;
        float entropy_income_high = 0;
        //calculate entropy of each group of income
        entropy_income_low = function_entropy(node->income_low);
        entropy_income_middle = function_entropy(node->income_middle);
        entropy_income_high = function_entropy(node->income_high);
        entropy_INCOME = (count_low * entropy_income_low + count_middle * entropy_income_middle + count_high * entropy_income_high) / total_samples;
    }
    //student part
    if (1 == node->student)
    {
        float count_yes = 0;
        float count_not = 0;
        //'for' is for assignment
        for (int i = 1; i <= 1024; i++)
        {
            if (1 == node->student_yes->datasource[i])
            {
                count_yes++;
            }
            if (1 == node->student_not->datasource[i])
            {
                count_not++;
            }
        }

        float entropy_student_yes = 0;
        float entropy_student_not = 0;
        //calculate entropy of each group of student
        entropy_student_yes = function_entropy(node->student_yes);
        entropy_student_not = function_entropy(node->student_not);
        entropy_STUDENT = (count_yes * entropy_student_yes + count_not * entropy_student_not) / total_samples;
    }
    //reputation part
    if (1 == node->reputation)
    {
        float count_common = 0;
        float count_good = 0;
        //'for' is for assignment
        for (int i = 1; i <= 1024; i++)
        {
            if (1 == node->reputation_common->datasource[i])
            {
                count_common++;
            }
            if (1 == node->reputation_good->datasource[i])
            {
                count_good++;
            }
        }

        float entropy_reputation_common = 0;
        float entropy_reputation_good = 0;
        //calculate entropy of each group of reputation
        entropy_reputation_common = function_entropy(node->reputation_common);
        entropy_reputation_good = function_entropy(node->reputation_good);
        entropy_REPUTATION = (count_common * entropy_reputation_common + count_good * entropy_reputation_good) / total_samples;
    }

    //find a min but greater than 0
    if (fabs(entropy_AGE + 1) < 1e-6)
    {
        entropy_AGE = 999;
    }
    if (fabs(entropy_INCOME + 1) < 1e-6)
    {
        entropy_INCOME = 999;
    }
    if (fabs(entropy_STUDENT + 1) < 1e-6)
    {
        entropy_STUDENT = 999;
    }
    if (fabs(entropy_REPUTATION + 1) < 1e-6)
    {
        entropy_REPUTATION = 999;
    }
    printf("\n");
    printf("AGE entropy: %.2f\n", entropy_AGE);
    printf("INCOME entropy: %.2f\n", entropy_INCOME);
    printf("STUDENT entropy: %.2f\n", entropy_STUDENT);
    printf("REPUTATION entropy: %.2f\n", entropy_REPUTATION);
    if (entropy_AGE <= entropy_INCOME && entropy_AGE <= entropy_REPUTATION && entropy_AGE <= entropy_STUDENT)
    {
        return 1;
    }
    if (entropy_INCOME <= entropy_AGE && entropy_INCOME <= entropy_STUDENT && entropy_INCOME <= entropy_REPUTATION)
    {
        return 2;
    }
    if (entropy_STUDENT <= entropy_AGE && entropy_STUDENT <= entropy_INCOME && entropy_STUDENT <= entropy_REPUTATION)
    {
        return 3;
    }
    if (entropy_REPUTATION <= entropy_AGE && entropy_REPUTATION <= entropy_INCOME && entropy_REPUTATION <= entropy_STUDENT)
    {
        return 4;
    }
    return 0;
}

// int function_attribute_division(struct Dataset *node)
// {
//     if (node->age == 1)
//     {
//         for (int i = 1; i <= 1204; i++)
//         {
//             if (sample[node->datasource[i]].age )
//             {
//                 /* code */
//             }
//         }
//     }
// }

void function_set_parent_attribute_switch(struct Dataset *node, int split_number)
{
    if (split_number == 1) //split as age attribute
    {
        node->age = 0;

        ////assign sub dataset'attribute with parent's attribute switch,casuse parent's switch is no use now
        //

        //use attribute set to split the data set
    }
    if (split_number == 2)
    {
        node->income = 0;
    }
    if (split_number == 3)
    {
        node->student = 0;
    }
    if (split_number == 4)
    {
        node->reputation = 0;
    }
}

void function_assign_child_attribute_switch(struct Dataset *node)
{
    node->age = node->parent->age;
    node->income = node->parent->income;
    node->student = node->parent->student;
    node->reputation = node->parent->reputation;
}

int function_split_dataset(struct Dataset *node)
{
    //recursion end part
    //case 3:no attribute
    if (node->age == 0 && node->income == 0 && node->student == 0 && node->reputation == 0)
    {
        node->node_kind = 3;
        node->classify = node->parent->parameter;
        return 0;
    }

    //case 1:same buy attibute
    int count_for_buy = 0;
    int count_for_not_buy = 0;
    for (int i = 1; i <= 1024; i++)
    {
        if (1 == node->datasource[i])
        {
            if (sample[i].buy_or_not == 1)
            {
                count_for_buy++;
            }
            else
            {
                count_for_not_buy++;
            }
        }
    }
    if (count_for_buy == 0 && count_for_not_buy != 0)
    {
        node->node_kind = 3;
        node->classify = 0;
        return 0;
    }
    if (count_for_not_buy == 0 && count_for_buy != 0)
    {
        node->node_kind = 3;
        node->classify = 1;
        return 0;
    }

    //case 2:no data in dataset
    if (count_for_buy == 0 && count_for_not_buy == 0)
    {
        node->node_kind = 3;
        node->classify = node->parent->parameter;
        return 0;
    }

    //self-assignment part
    node->node_kind = 2;
    //to assign the parameter
    if (function_entropy(node) == 0) //it is impossible to show the 0 entropy here
    {
        printf("\nbig dataset entropy = 0\n");
        node->classify = node->parent->parameter;
        return 0;
    }

    ////assign atrribute set for right entropy calculation
    function_assignment_attribute_subset(node);
    printf("\n");
    printf("attribute assignment test\n");
    function_test_attribute_assignment(node);
    printf("\n");

    //creat child part
    //calculate entropy to get the base of atrribute to split dataset
    int split_number;
    split_number = function_calculate_arrtibute_entropy_return_right_entropy_attribute(node);
    if (split_number == 0)
    {
        printf("split_number error\n");
        exit(0);
    }

    printf("\n");
    printf("the split attribute is %d\n", split_number);
    //split recursion
    ////set attribute switch as child switch pattern
    printf("\nthe parent attribute switch\n");
    printf("the age : %d\n", node->age);
    printf("the income : %d\n", node->income);
    printf("the student : %d\n", node->student);
    printf("the reputation : %d\n", node->reputation);
    function_set_parent_attribute_switch(node, split_number);
    printf("\nthe child attribute switch\n");
    printf("the age : %d\n", node->age);
    printf("the income : %d\n", node->income);
    printf("the student : %d\n", node->student);
    printf("the reputation : %d\n", node->reputation);

    ////according to split_number to define pointer for sub dataset
    if (split_number == 1) //age attribute
    {
        for (int j = 1; j <= 3; j++)
        {
            node->child[j] = (struct Dataset *)calloc(1, sizeof(struct Dataset));
            if (node->child[j] == NULL)
            {
                printf("memory allocation failed in age %d\n", j);
                exit(0);
            }
            else
            {
                node->child[j]->parent = node;
            }
            if (j == 1)
            {
                for (int i = 1; i <= 1024; i++) //assign child datasource
                {
                    if (node->age_teen->datasource[i] == 1)
                    {
                        node->child[j]->datasource[i] = 1;
                    }
                }
            }
            if (j == 2)
            {
                for (int i = 1; i <= 1024; i++) //assign child datasource
                {
                    if (node->age_middle->datasource[i] == 1)
                    {
                        node->child[j]->datasource[i] = 1;
                    }
                }
            }
            if (j == 3)
            {
                for (int i = 1; i <= 1024; i++) //assign child datasource
                {
                    if (node->age_old->datasource[i] == 1)
                    {
                        node->child[j]->datasource[i] = 1;
                    }
                }
            }

            //assign child attribute switch
            function_assign_child_attribute_switch(node->child[j]);
            function_split_dataset(node->child[j]);
        }
    }
    if (split_number == 2)
    {
        for (int j = 1; j <= 3; j++)
        {
            node->child[j] = (struct Dataset *)calloc(1, sizeof(struct Dataset));
            if (node->child[j] == NULL)
            {
                printf("memory allocation failed in income %d\n", j);
                exit(0);
            }
            else
            {
                node->child[j]->parent = node;
            }
            if (j == 1)
            {
                for (int i = 1; i <= 1024; i++) //assign child datasource
                {
                    if (node->income_low->datasource[i] == 1)
                    {
                        node->child[j]->datasource[i] = 1;
                    }
                }
            }
            if (j == 2)
            {
                for (int i = 1; i <= 1024; i++) //assign child datasource
                {
                    if (node->income_middle->datasource[i] == 1)
                    {
                        node->child[j]->datasource[i] = 1;
                    }
                }
            }
            if (j == 3)
            {
                for (int i = 1; i <= 1024; i++) //assign child datasource
                {
                    if (node->income_high->datasource[i] == 1)
                    {
                        node->child[j]->datasource[i] = 1;
                    }
                }
            }

            //assign child attribute switch
            function_assign_child_attribute_switch(node->child[j]);
            function_split_dataset(node->child[j]);
        }
    }
    if (split_number == 3)
    {
        for (int j = 1; j <= 2; j++)
        {
            node->child[j] = (struct Dataset *)calloc(1, sizeof(struct Dataset));
            if (node->child[j] == NULL)
            {
                printf("memory allocation failed in student %d\n", j);
                exit(0);
            }
            else
            {
                node->child[j]->parent = node;
            }
            if (j == 1)
            {
                for (int i = 1; i <= 1024; i++) //assign child datasource
                {
                    if (node->student_yes->datasource[i] == 1)
                    {
                        node->child[j]->datasource[i] = 1;
                    }
                }
            }
            if (j == 2)
            {
                for (int i = 1; i <= 1024; i++) //assign child datasource
                {
                    if (node->student_not->datasource[i] == 1)
                    {
                        node->child[j]->datasource[i] = 1;
                    }
                }
            }

            //assign child attribute switch
            function_assign_child_attribute_switch(node->child[j]);
            function_split_dataset(node->child[j]);
        }
    }
    if (split_number == 4)
    {
        for (int j = 1; j <= 2; j++)
        {
            node->child[j] = (struct Dataset *)calloc(1, sizeof(struct Dataset));
            if (node->child[j] == NULL)
            {
                printf("memory allocation failed in reputation %d\n", j);
                exit(0);
            }
            else
            {
                node->child[j]->parent = node;
            }
            if (j == 1)
            {
                for (int i = 1; i <= 1024; i++) //assign child datasource
                {
                    if (node->reputation_common->datasource[i] == 1)
                    {
                        node->child[j]->datasource[i] = 1;
                    }
                }
            }
            if (j == 2)
            {
                for (int i = 1; i <= 1024; i++) //assign child datasource
                {
                    if (node->reputation_good->datasource[i] == 1)
                    {
                        node->child[j]->datasource[i] = 1;
                    }
                }
            }

            //assign child attribute switch
            function_assign_child_attribute_switch(node->child[j]);
            function_split_dataset(node->child[j]);
        }
    }

    ////set dataset(for each split attribute,make a recursion)
    ////set node type(if leaf node, set classify type)

    ////
    return 0;
}

int function_show_tree(struct Dataset *node, int layer)
{
    printf("the %d layer\n", layer);
    if (node->node_kind == 3)
    {
        printf("this is leaf node\n");
        printf("its classify is %d\n", node->classify);
        return 0;
    }
    printf("%d %d %d %d\n", node->age, node->income, node->student, node->reputation);
    for (int i = 1; i <= 3; i++)
    {
        if (node->child[i] != NULL)
        {
            function_show_tree(node->child[i], layer + 1);
        }
    }
    return 0;
}

int main()
{
    function_init_data();
    //check for init
    // function_test_attribute_assignment(root);
    root = (struct Dataset *)calloc(1, sizeof(struct Dataset));
    if (root == NULL)
    {
        printf("root memory failed\n");
        exit(0);
    }

    for (int i = 1; i <= 1024; i++)
    {
        root->datasource[i] = 1;
    }
    //assign attribute switch
    root->age = 1;
    root->income = 1;
    root->student = 1;
    root->reputation = 1;

    // function_assignment_attribute_subset(root);
    // function_test_attribute_assignment(root);
    printf("\n");
    function_split_dataset(root);
    system("clear");
    function_show_tree(root, 1);
    return 0;
}
void function_test_attribute_assignment(struct Dataset *node)
{
    //for age
    int count_age_teen = 0;
    int count_age_middle = 0;
    int count_age_old = 0;
    //for income
    int count_income_low = 0;
    int count_income_middle = 0;
    int count_income_high = 0;
    //for student
    int count_student_yes = 0;
    int count_student_not = 0;
    //for reputation
    int count_reputation_common = 0;
    int count_reputation_good = 0;
    for (int i = 1; i <= 1024; i++)
    {
        //age part
        if (node->age == 1)
        {
            if (node->age_teen->datasource[i] == 1)
            {
                count_age_teen++;
            }
            if (node->age_middle->datasource[i] == 1)
            {
                count_age_middle++;
            }
            if (node->age_old->datasource[i] == 1)
            {
                count_age_old++;
            }
        }

        //income part
        if (node->income == 1)
        {
            if (node->income_low->datasource[i] == 1)
            {
                count_income_low++;
            }
            if (node->income_middle->datasource[i] == 1)
            {
                count_income_middle++;
            }
            if (node->income_high->datasource[i] == 1)
            {
                count_income_high++;
            }
        }

        //student part
        if (node->student == 1)
        {
            if (node->student_yes->datasource[i] == 1)
            {
                count_student_yes++;
            }
            if (node->student_not->datasource[i] == 1)
            {
                count_student_not++;
            }
        }

        //reputation part
        if (node->reputation == 1)
        {
            if (node->reputation_common->datasource[i] == 1)
            {
                count_reputation_common++;
            }
            if (node->reputation_good->datasource[i] == 1)
            {
                count_reputation_good++;
            }
        }
    }
    printf("age part:\n");
    printf("age teen %d\n", count_age_teen);
    printf("age middle %d\n", count_age_middle);
    printf("age old %d\n", count_age_old);

    printf("\n");
    printf("income part:\n");
    printf("income low %d\n", count_income_low);
    printf("income middle %d\n", count_income_middle);
    printf("income high %d\n", count_income_high);

    printf("\n");
    printf("student part:\n");
    printf("student yes %d\n", count_student_yes);
    printf("student not %d\n", count_student_not);

    printf("\n");
    printf("reputation part:\n");
    printf("reputation common %d\n", count_reputation_common);
    printf("reputation good %d\n", count_reputation_good);

    //for age old
    // int sample_count = 0;
    // for (int i = 1; i <= 1024; i++)
    // {
    //     if (sample[i].age == OLD)
    //     {
    //         sample_count++;
    //     }
    // }
    // printf("%d\n", sample_count);
}

void function_test_calculate_attribute_entropy(struct Dataset *node)
{
    int attribute_num = 0;
    attribute_num = function_calculate_arrtibute_entropy_return_right_entropy_attribute(node);
    printf("the max atttribute number is %d\n", attribute_num);

    // printf("the entropy of middle is %.2f\n", function_entropy(root.age_middle));
}