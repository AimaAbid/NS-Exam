#include <stdio.h>
#include <string.h>

void generateTable(char key[], char keyTable[5][5])
{
    int len = strlen(key);
    for (int i = 0; i < len; i++)
    {
        key[i] = toupper(key[i]);
    }
    for (int i = 0; i < len; i++)
    {
        if (key[i] == 'J')
        {
            key[i] = 'I';
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            keyTable[i][j] = 0;
        }
    }

    char taken[26] = {0};
    int k = 0;
    int flag = 0;
    for (k = 0; k < len; k++)
    {

        if (taken[key[k] - 'A'] == 0)
        {
            keyTable[flag / 5][flag % 5] = key[k];
            taken[key[k] - 'A'] = 1;

            flag++;
        }
    }

    char alphabet = 'A';
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyTable[i][j] == 0)
            {
                while (taken[alphabet - 'A'] == 1 || (alphabet == 'J' && taken['I' - 'A'] == 1))
                {
                    ++alphabet;
                }
                keyTable[i][j] = alphabet;
                taken[alphabet - 'A'] = 1;
                ++alphabet;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", keyTable[i][j]);
        }
        printf("\n");
    }
}

void findPosition(char keyTable[5][5], char ch, int *row, int *col)
{
    if (ch == 'J')
    {
        ch = 'I';
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyTable[i][j] == ch)
            {
                *row = i;
                *col = j;
            }
        }
    }
}

void encrypt(char pt[], char keyTable[5][5])
{
    int len = strlen(pt);
    for (int i = 0; i < len; i++)
    {
        pt[i] = toupper(pt[i]);
    }
    if (len % 2 != 0)
    {
        pt[len] = 'X';
        pt[len + 1] = '\0';
        len++;
    }
    for (int i = 0; i < len; i = i + 2)
    {
        int r1, c1, r2, c2;
        findPosition(keyTable, pt[i], &r1, &c1);
        findPosition(keyTable, pt[i + 1], &r2, &c2);

        if (r1 == r2)
        {
            printf("%c%c ", keyTable[r1][(c1 + 1) % 5], keyTable[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2)
        {
            printf("%c%c ", keyTable[(r1 + 1) % 5][c1], keyTable[(r2 + 1) % 5][c2]);
        }
        else
        {
            printf("%c%c ", keyTable[r1][c2], keyTable[r2][c1]);
        }
    }
}

int main()
{

    char key[26];
    char pt[26];
    char keyTable[5][5];
    printf("Enter the plain text");
    scanf("%s", pt);
    printf("Enter the key");
    scanf("%s", key);
    generateTable(key, keyTable);
    encrypt(pt, keyTable);
}