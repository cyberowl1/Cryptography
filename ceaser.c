#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])

{
//checking for command line argument
//And converting string to integer.
    int key;
    if (argc != 2)
    {
        printf("Missing Command line argument\n");
    }
    else
    {
        key = atoi(argv[1]);
    }

    char *plain;
//Getting plain text from user.
    plain = get_string("plain text:");
    int x = strlen(plain);
 
//converting it to cipher    
    for (int i = 0; i <= x; i++)
    {
//lowercase checking
        if (islower(plain[i]))
        {    
       
           plain[i] = (((plain[i] + key) - 97) % 26) + 97;
        }
//uppercase checking
        else if (isupper(plain[i]))
        {   
       
             plain[i] = (((plain[i] + key) - 65) % 26) + 65;
      }
    else 
      {
          plain[i] = plain[i];
       }
    }
//printing cipher text
   printf("cipher : %s", plain);
   
//   Decrypt 
 
}
    
