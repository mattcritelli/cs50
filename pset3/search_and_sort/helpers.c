/**
* helpers.c
*
* Helper functions for Problem Set 3.
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include "helpers.h"

//void print_statement(int value, int start, int middle, int end, int values[]);

/**
* Returns true if value is in array of n values, else false.
* Iterative binary search algorithm.
*/
bool search(int value, int values[], int n)
{
    if(value < values[0] || value > values[n-1])
    {
        return false;
    }
    else
    {
        int start = 0;
        int middle = floor(n/2);
        int end = n-1;
        do
        {
            //print_statement(value, start, middle, end, values);
            if(value == values[middle])
            {
                return true;
            }
            else if(value < values[middle])
            {
                end = middle-1;
                middle = (start + end)/2;
            }
            else if(value > values[middle])
            {
                start = middle + 1;
                middle = (start + end)/2;
            }
        }
        while(start <= end);
    }
    return false;
}

/**
* Sorts array of n values using bubble sort algorithm
*/
void sort(int values[], int n)
{
    int count = -1;
    do
    {
        count = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(values[i] > values[i+1])
            {
                int smaller = values[i+1];
                int larger = values[i];
                values[i] = smaller;
                values[i+1] = larger;
                count++;
            }
        }
    }
    while(count != 0);
    return;
}

// debug print statements
// void print_statement(int value, int start, int middle, int end, int values[])
// {
//     printf("value: %i\n", value);
//     printf("start_idx: %i -- middle_idx: %i -- end_idx: %i\n", start, middle, end);
//     printf("start: %i -- middle: %i -- end: %i\n", values[start], values[middle], values[end]);
//     printf("---------------------------------------------\n");
// }
