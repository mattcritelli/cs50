/**
 * THIS CODE PROVIDED BY CS50! INCLUDED TO SHOW ALL PIECES OF PROGRAM!
 * MY CODE IS IN "helpers.c"
 *
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */


#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // confirm that there are 2 or 3 command line args
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // stores 2nd arg as an integer
    int n = atoi(argv[1]);

    // if a 3rd cmd line arg is present, pass that into srand
    // otherwise, pass in time as seed
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // for loop iterating from 0 to n.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
