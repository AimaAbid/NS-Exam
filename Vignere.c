#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform Vigenère encryption
void vigenereEncrypt(char *plaintext, const char *key) {
    int keyLength = strlen(key);

    for (int i = 0, j = 0; i < strlen(plaintext); ++i) {
        char currentChar = plaintext[i];

        // Check if the current character is an alphabet letter
        if (isalpha(currentChar)) {
            char caseOffset = isupper(currentChar) ? 'A' : 'a';
            int shift = toupper(key[j % keyLength]) - 'A';

            // Encrypt the current character using the Vigenère cipher
            plaintext[i] = (currentChar - caseOffset + shift) % 26 + caseOffset;

            // Move to the next letter in the key
            ++j;
        }
    }
}

int main() {
    char plaintext[100];
    char key[100];

    // Input plaintext and key
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    printf("Enter the key: ");
    scanf("%s", key);

    // Validate key
    for (int i = 0; i < strlen(key); ++i) {
        if (!isalpha(key[i])) {
            printf("Invalid key!\n");
            return 1;
        }
    }

    // Encrypt the plaintext using the Vigenère cipher
    vigenereEncrypt(plaintext, key);

    // Display the encrypted text
    printf("\nEncrypted Text: %s\n", plaintext);

    return 0;
}
