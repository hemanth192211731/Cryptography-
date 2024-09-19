#include <stdio.h>
#include <string.h>
#include <ctype.h>
void generateCipherAlphabet(const char *keyword, char *cipher) {
    int used[26] = {0};  
    int index = 0;
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            cipher[index++] = ch;
            used[ch - 'A'] = 1;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            cipher[index++] = ch;
        }
    }
    cipher[index] = '\0'; 
}
void encrypt(const char *plaintext, const char *cipher, char *encrypted) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = toupper(plaintext[i]);
        if (ch >= 'A' && ch <= 'Z') {
            encrypted[i] = cipher[ch - 'A'];
        } else {
            encrypted[i] = plaintext[i];  
        }
    }
    encrypted[strlen(plaintext)] = '\0'; 
}
void decrypt(const char *ciphertext, const char *cipher, char *decrypted) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = toupper(ciphertext[i]);
        if (ch >= 'A' && ch <= 'Z') {
            for (int j = 0; j < 26; j++) {
                if (cipher[j] == ch) {
                    decrypted[i] = 'A' + j;
                    break;
                }
            }
        } else {
            decrypted[i] = ciphertext[i];  
        }
    }
    decrypted[strlen(ciphertext)] = '\0';  
}
int main() {
    char keyword[100];
    char plaintext[1000];
    char ciphertext[1000];
    char cipherAlphabet[27];  
    char encrypted[1000];
    char decrypted[1000];
    printf("Enter the keyword: ");
    scanf("%s", keyword);
    generateCipherAlphabet(keyword, cipherAlphabet);
    printf("Generated cipher alphabet: %s\n", cipherAlphabet);
    printf("Enter the plaintext to encrypt: ");
    scanf(" %[^\n]", plaintext);
    encrypt(plaintext, cipherAlphabet, encrypted);
    printf("Encrypted text: %s\n", encrypted);
    decrypt(encrypted, cipherAlphabet, decrypted);
    printf("Decrypted text: %s\n", decrypted);
    return 0;
}

