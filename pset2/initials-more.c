#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void first_letters(string s);

int main(void)
{
    //printf("Please enter your name: \n");
    string name = get_string();
    //printf("Name entered: %s \n", name);
    first_letters(name);
}

void first_letters(string s)
{
    bool firstLetterFound = false;
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == ' ')
        {
            firstLetterFound = false;
        }
        else if(s[i] >= 'a' && s[i] <= 'z')
        {
            if(firstLetterFound == false)
            {
                printf("%c", toupper(s[i]));
                firstLetterFound = true;
            }
        }
        else
        {
            if(firstLetterFound == false)
            {
                printf("%c", s[i]);
                firstLetterFound = true;
            }
        }
    }
    printf("\n");
}
