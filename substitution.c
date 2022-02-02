#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // checks whether a single key is entered
    if (argc != 2)
    {
        printf("./substitution KEY\n");
        return 1;
    }

    int argv_len = strlen(argv[1]);

    // checks whether the key is 26 characters long
    if (argv_len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //checks whether the key has only alphabetical character
    for (int i = 0; i < argv_len; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetical characters.\n");
            return 1;
        }

        // checks whether key has no repeated characters
        for (int j = i + 1; j < argv_len; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // prompts user to enter plaintext
    string text = get_string("plaintext: ");

    printf("ciphertext: ");

    int text_len = strlen(text);

    // prints ciphertext
    for (int i = 0; i < text_len; i++)
    {
        // converts cyphertext character to capital if text character is capital
        if (isupper(text[i]))
        {
            printf("%c", toupper(argv[1][text[i] - 65]));
        }

        // converts cyphertext character to lowercase if text character is lowercase
        else if (islower(text[i]))
        {
            printf("%c", tolower(argv[1][text[i] - 97]));
        }

        // prints cyphertext character as is if text character equal to cyphertext character
        else
        {
            printf("%c", text[i]);
        }

    }

    printf("\n");
}