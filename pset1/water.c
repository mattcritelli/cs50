#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Minutes: ");
    int minutes = get_int();
    printf("Bottles: %0.f \n", (minutes * 1.5) * 128 / 16);
}