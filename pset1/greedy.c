#include <stdio.h>
#include <cs50.h>
#include <math.h>

int convert_input(float dollar_format);
int make_change(int total_amount);
float user_input();

int main(void)
{
    float change = user_input();
    int amount = convert_input(change);
    int total_coins = make_change(amount);
    printf("%i\n", total_coins);
}

float user_input(void)
{
    bool valid = false;
    float change_owed;
    do
    {
        printf("O hai! How much change is owed? \n");
        change_owed = get_float();
        if(change_owed >= 0)
        {
            valid = true;
        }
    }
    while(valid == false);
    return change_owed;
}

int convert_input(float dollar_format)
{
    int formatted = round(dollar_format * 100);
    return formatted;
}

int make_change(int total_amount)
{
    int num_coins = 0;
    do
    {
        if(total_amount >= 25)
        {
           num_coins++;
           total_amount -= 25;
        }
    }
    while(total_amount >= 25);
    do
    {
        if(total_amount >= 10)
        {
           num_coins++;
           total_amount -= 10;
        }
    }
    while(total_amount >= 10);
    do
    {
        if(total_amount >= 5)
        {
           num_coins++;
           total_amount -= 5;
        }
    }
    while(total_amount >= 5);
    do
    {
        if(total_amount >= 1)
        {
           num_coins++;
           total_amount -= 1;
        }
    }
    while(total_amount >= 1);
    return num_coins;
}