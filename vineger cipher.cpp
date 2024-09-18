#include <stdio.h>
#include <string.h>
#include <ctype.h>
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    for (int i = 0; i < keyLen; i++) {
        key[i] = toupper(key[i]);
    }

    for (int i = 0, j = 0; i < textLen; i++) {
        char letter = plaintext[i];
        if (isalpha(letter)) {
            char offset = isupper(letter) ? 'A' : 'a';  
            ciphertext[i] = ((letter - offset) + (key[j % keyLen] - 'A')) % 26 + offset;
            j++; 
        } else {
            ciphertext[i] = letter;  
        }
    }
    ciphertext[textLen] = '\0'; 
}

int main() {
    char plaintext[100], key[100], ciphertext[100];

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    printf("Enter the key: ");
    scanf("%s", key);

    encrypt(plaintext, key, ciphertext);

    printf("Encrypted ciphertext: %s\n", ciphertext);

    return 0;
}

