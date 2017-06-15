#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encode(string s, int k);

int main(int argc, string argv[])
{
    if(argc < 2 || argc > 2)
    {
        printf("Error\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string p = get_string();
    encode(p, key);
    printf("\n");
    return 0;

}

void encode(string s, int k)
{
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if(isalpha(s[i]))
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
               if(s[i] + k > 122)
                {
                    printf("%c", (s[i] + k) % 122 + 96);
                    //printf("wrapped letter: %c ascii: %i || encoded: %c number: %i\n", s[i], s[i], (s[i] + k) % 122 + 96, (s[i] + k) % 122 + 96);
                }
                else
                {
                    printf("%c", s[i] + k);
                    //printf("NONwrapped letter: %c ascii: %i || encoded: %c number: %i\n", s[i], s[i], s[i] + k, s[i] + k);
                }
            }
            else
            {
                if(s[i] + k > 90)
                {
                    printf("%c", (s[i] + k) % 90 + 64);
                    //printf("wrapped letter: %c ascii: %i || encoded: %c number: %i\n", s[i], s[i], (s[i] + k) % 122 + 96, (s[i] + k) % 122 + 96);
                }
                else
                {
                    printf("%c", s[i] + k);
                    //printf("NONwrapped letter: %c ascii: %i || encoded: %c number: %i\n", s[i], s[i], s[i] + k, s[i] + k);
                }
            }

        }
        else
        {
            printf("%c", s[i]);
        }
    }
}