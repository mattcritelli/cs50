/**
 * ALL CODE EXCEPT FOR PRINT ARRAY DEBUG METHOD PROVIDED BY CS50!
 * INCLUDED TO SHOW ALL PIECES OF PROGRAM!
 * MY CODE IS IN "helpers.c"
 *
 * Prompts user for as many as MAX values until EOF is reached,
 * then proceeds to search that "haystack" of values for given needle.
 *
 * Usage: ./find needle
 *
 * where needle is the value to find in a haystack of values
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

// maximum amount of hay
const int MAX = 65536;

void print_array(int array[], int n);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./find needle\n");
        return -1;
    }

    // remember needle
    int needle = atoi(argv[1]);

    // fill haystack
    int size;
    int haystack[MAX];
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
        printf("\nhaystack[%i] = ", size);
        int straw = get_int();
        if (straw == INT_MAX)
        {
            break;
        }

        // add hay to stack
        haystack[size] = straw;
    }
    printf("\n");

    // sort the haystack
    print_array(haystack, size);
    sort(haystack, size);
    print_array(haystack, size);


    // try to find needle in haystack
    if (search(needle, haystack, size))
    {
        printf("\nFound needle in haystack!\n\n");
        return 0;
    }
    else
    {
        printf("\nDidn't find needle in haystack.\n\n");
        return 1;
    }
}

// print array function used for debugging

// void print_array(int array[], int n)
// {
//     printf("[");
//     for(int i = 0; i < n; i++)
//     {
//         if(i != n-1)
//         {
//             printf("%i", array[i]);
//             printf(",");
//         }
//         else
//         {
//             printf("%i", array[i]);
//         }

//     }
//     printf("]\n");
// }
