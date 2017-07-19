#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encode_letter(char c , int k);
void encryption(string plaintext, string cipher);
int find_key(char letter);

/* Takes command line args and checks that 2 args are presentif 2 args
are present, it confirms that the 2nd arg (keyword) is only comprised
of alphabetic characters
*/

int main(int argc, string argv[])
{
  if(argc != 2)
  {
    printf("Error\n");
    return 1;
  }
  else
  {
    for(int i = 0, j = strlen(argv[1]); i < j; i++)
    {
      if(!isalpha(argv[1][i]))
      {
        printf("Error\n");
        return 1;
      }
    }
  }
  string keyword = argv[1];
  // Prompts user for text to be encrypted
  printf("plaintext: ");
  string plaintext = get_string();
  // Notifies user of ciphertext result
  printf("ciphertext: ");
  //Passes plaintext and keyword from ARGV into encryption function
  encryption(plaintext, keyword);
  return 0;
}

void encryption(string plaintext, string keyword)
{
  // Initializes counter that will iterate through keyword
  int count = 0;

  //Initializes for loop to iterate through plaintext
  for(int x = 0, y = strlen(plaintext); x < y; x++)
  {
    /* Checks to see if each char is alphabetic. If it is alphabetic
    then it will be encoded.  If it is a number/special characters
    it jump to else statement and character will be passed through as is */
    if(isalpha(plaintext[x]))
    {
      /* If the count is equal to the last index of the keyword,
      then the counter will need to be reset to 0 after encrypting.
      This will make sure that it continuously loops through keyword until
      all plaintext is encrypted. */
      if(count == (strlen(keyword)-1))
      {
        int key = find_key(keyword[count]);
        encode_letter(plaintext[x], key);
        count = 0;
      }
      /* If the counter is not on the last keyword index, then the
      plaintext character will be encoded and the counter will be
      incremented by 1. */
      else
      {
        int key = find_key(keyword[count]);
        encode_letter(plaintext[x], key);
        count++;
      }
    }
    else
    {
      printf("%c", plaintext[x]);
    }
  }
  printf("\n");
}
/* This function will find the correct key in either the lower or uppercase
alphabetic sequence and return key for the encode letter function. */
int find_key(char letter)
{
  string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
  string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for(int i = 0, j = strlen(lower_alphabet); i < j; i++)
  {
    if(letter == lower_alphabet[i] || letter == upper_alphabet[i])
    {
      return i;
    }
  }
  return 0;
}

/* This function takes a character to be encoded and a key which represents
the number of positions forward to change letter */
void encode_letter(char c, int k)
{
  if(isalpha(c))
  {
    /* Modifies lowercase letters, if modified letter number is higher
    than 'z', this will find the remaining number to move and loop back
    around and add to 'a' */

    if(c >= 'a' && c <= 'z')
    {
      if(c + k > 122)
      {
        printf("%c", (c + k) % 122 + 96);
      }
      else
      {
        printf("%c", c + k);
      }
    }
    /* This modifies uppercase letters. Similar to the loop above, if
    modified letter number is higher than 'Z', this will find the remaining
    number to move and loop back around and add to 'A' */
    else
    {
      if(c + k > 90)
      {
        printf("%c", (c + k) % 90 + 64);
      }
      else
      {
        printf("%c", c + k);
      }
    }
  }
}
