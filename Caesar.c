#include <stdio.h>
#include <string.h>

int main()
{
    char pt[100];
    char ct[100];
    int key = 3;
    printf("Enter the plain text:");
    gets(pt);
    printf("Original Text:");
    puts(pt);
    for (int i = 0; i < strlen(pt); i++)
    {

        if (pt[i] >= 65 && pt[i] <= 90)
        {
            ct[i] = (pt[i] + key - 'A') % 26 + 'A';
        }

        if (pt[i] >= 97 && pt[i] <= 122)
        {
            ct[i] = (pt[i] + key - 'a') % 26 + 'a';
        }
    }
    printf("Encrypted text:");
    for (int i = 0; i < strlen(pt); i++)
    {
        printf("%c", ct[i]);
    }

    //Decryption
     for (int i = 0; i < strlen(ct); i++)
    {

        if (ct[i] >= 65 && ct[i] <= 90)
        {
            pt[i] = (ct[i] - key - 'A') % 26 + 'A';
        }

        if (ct[i] >= 97 && ct[i] <= 122)
        {
            pt[i] = (ct[i] - key - 'a') % 26 + 'a';
        }
    }
    printf("\nDecrypted text: ");
    for (int i = 0; i < strlen(pt); i++)
    {
        printf("%c", pt[i]);
    }
    return 0;
}