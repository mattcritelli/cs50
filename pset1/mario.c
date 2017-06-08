#include <cs50.h>
#include <stdio.h>

int pyramid_height(void);
void print_line(int spaces, int hashes);
void print_hashes(int num_blocks);
void print_gap(void);
void print_spaces(int num_spaces);

int main(void)
{
    int height = pyramid_height();
    int line_offset = height-1;
    for(int count = 0; count < height; count++)
    {
        print_line(line_offset, count);
        line_offset--;
        printf("\n");
    }
}

int pyramid_height(void)
{
    int num;
    do
    {
        printf("Height: ");
        num = get_int();
    }
    while(num < 0 || num > 23);
    return num;
}


void print_line(int spaces, int hashes)
{
    print_spaces(spaces);
    print_hashes(hashes);
    print_gap();
    print_hashes(hashes);
}

void print_spaces(int num_spaces)
{
    while(num_spaces > 0)
    {
        printf(" ");
        num_spaces--;
    }

}

void print_hashes(int num_blocks)
{
    int count = 0;
    while(count <= num_blocks)
    {
        printf("#");
        count++;
    }
}

void print_gap(void)
{
    printf("  ");
}