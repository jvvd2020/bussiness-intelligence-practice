#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double GDP[40] = {3645, 4063, 4546, 4892, 5323,
                  5963, 7208, 9016, 10275, 12059,
                  15043, 16992, 18668, 21782, 26924,
                  35334, 48198, 60794, 71177, 78973,
                  84402, 89677, 99215, 109655, 120333,
                  135823, 159878, 183217, 216314, 257306,
                  314045, 340903, 401513, 484124, 540367,
                  595244, 643974, 689052, 740061, 820754};//import raw data
double ln_GDP[40];//GDP data for exponential function
//import variable for model
double x_;
double y_;
double ln_y_;
double a_;
double ln_a_;
double b_;
double ln_b_;
double l_xx;
double l_yy;
double ln_l_yy;
double l_xy;
double ln_l_xy;
double R;
double ln_R;
double sigma;
double delta;
//calculate the average of x
double function_x_()
{
    double total = 0;
    for (int i = 1978; i <= 2017; i++)
    {
        total += i;
    }
    total = total / 40.0;
    return total;
}
//calculate the average of y
double fucntion_y_(double *GDP)
{
    double total = 0;
    for (int i = 0; i < 40; i++)
    {
        total += GDP[i];
    }
    total = total / 40.0;
    return total;
}
//calculate the value of l_xx
double function_l_xx()
{
    double total = 0;
    double intermediate = 0;
    for (int i = 1978; i <= 2017; i++)
    {
        intermediate = pow(i - x_, 2.0);
        total += intermediate;
    }
    return total;
}
//calculate the calue of l_xy
double fucntion_l_xy(double y_, double *GDP)
{
    double total = 0;
    double intermediate = 0;
    for (int i = 0, j = 1978; i < 40; i++, j++)
    {
        intermediate = (j - x_) * (GDP[i] - y_);
        total += intermediate;
    }
    return total;
}
//calculate the calue of l_yy
double fucntion_l_yy(double y_, double *GDP)
{
    double total = 0;
    double intermediate = 0;
    for (int i = 0; i < 40; i++)
    {
        intermediate = pow(GDP[i] - y_, 2);
        total += intermediate;
    }
    return total;
}
//calculate the calue of sigama
double function_sigma()
{
    return pow(((fucntion_l_yy(y_, GDP) - b_ * fucntion_l_xy(y_, GDP)) / 38), 0.5);
}
//calculate the calue of delta
double function_delta(int x0)
{
    double delta = 0;
    double t_half_alpha = 2.024;
    delta = t_half_alpha * sigma * pow((1 + 1 / 38.0 + pow((x0 - x_), 2) / function_l_xx()), 0.5);
    return delta;
}
//fill the ln_GDP array
double function_ln_GDP()
{
    for (int i = 0; i < 40; i++)
    {
        ln_GDP[i] = log(GDP[i]);
    }
    return 0;
}
int main()
{
    system("clear"); //initialize data
    function_ln_GDP();

    x_ = function_x_();

    y_ = fucntion_y_(GDP);
    ln_y_ = fucntion_y_(ln_GDP);

    ln_l_yy = fucntion_l_yy(ln_y_, ln_GDP);
    ln_l_xy = fucntion_l_xy(ln_y_, ln_GDP);

    b_ = fucntion_l_xy(y_, GDP) / function_l_xx();
    ln_b_ = fucntion_l_xy(ln_y_, ln_GDP) / function_l_xx();

    a_ = y_ - (b_ * x_);
    ln_a_ = ln_y_ - ln_b_ * x_;

    R = fucntion_l_xy(y_, GDP) / pow((function_l_xx() * fucntion_l_yy(y_, GDP)), 0.5);
    ln_R = fucntion_l_xy(ln_y_, ln_GDP) / pow((function_l_xx() * fucntion_l_yy(ln_y_, ln_GDP)), 0.5);

    sigma = function_sigma();
    //initialization done
    //main menu
    int option;
    while (option != 6)
    {
        system("clear");
        printf("MENU\n");
        printf("options:\n");
        printf("1.check the R of linear regression\n");
        printf("2.manully check the result of linear regression prediction\n");
        printf("3.check the R of exponential function\n");
        printf("4.manully check the exponential function prediction\n");
        printf("5.compare the accuracy of linear with the accuracy of exponential\n");
        printf("6.quit\n");
        printf("input option:\n");
        scanf("%d", &option);
        getchar();
        int x1;
        int x2;
        double SSE_of_linear = 0;
        double SSE_of_exponential = 0;
        switch (option)
        {
        case 1:
            printf("R = %f>0.304\n", R);
            printf("significance test done\n\n");
            printf("the formula is:\n");
            printf("y = %f + %fx\n", a_, b_);
            printf("press to continue\n");
            getchar();
            break;
        case 2:
            printf("enter the year to preview\n");
            scanf("%d", &x1);
            printf("the result is %f\n", a_ + b_ * x1);
            printf("under the 0.95 probility,\nthe prediction range is\n(%f,%f)\n\n", a_ + b_ * x1 - function_delta(x1), a_ + b_ * x1 + function_delta(x1));
            printf("press to continue\n");
            getchar();
            getchar();
            break;
        case 3:
            printf("ln_R = %f>0.304\n", ln_R);
            printf("significance test done\n\n");
            printf("the formular is:\n");
            printf("lny = %f + %fx\n", ln_a_, ln_b_);
            printf("press to continue\n");
            getchar();
            break;
        case 4:
            printf("enter the year to preview\n");
            scanf("%d", &x2);
            printf("the result is %f\n", exp(ln_a_ + ln_b_ * x2));
            printf("press to continue\n");
            getchar();
            getchar();
            break;
        case 5:
            for (int i = 0; i < 40; i++)
            {
                SSE_of_linear += pow((a_ + b_ * (1978 + i)) - GDP[i], 2.0);
                SSE_of_exponential += pow(exp(ln_a_ + ln_b_ * (1978 + i)) - GDP[i], 2.0);
            }
            printf("the rateSSE of linear regression is %.2f\n", SSE_of_linear / (SSE_of_exponential + SSE_of_linear));
            printf("the rateSSE of exponential regression is %.2f\n", SSE_of_exponential / (SSE_of_exponential + SSE_of_linear));
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
