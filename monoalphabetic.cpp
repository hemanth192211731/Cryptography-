#include <stdio.h>
#include <string.h>
void encrypt(char *plaintext, char *cipher_alphabet, char *ciphertext) {
    char plain_alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // Plaintext alphabet
    int i, j;

    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (ch >= 'A' && ch <= 'Z') {
            for (j = 0; j < 26; j++) {
                if (ch == plain_alphabet[j]) {
                    ciphertext[i] = cipher_alphabet[j];  
                    break;
                }
            }
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = ch - 'a' + 'A';  
            for (j = 0; j < 26; j++) {
                if (ch == plain_alphabet[j]) {
                    ciphertext[i] = cipher_alphabet[j] + ('a' - 'A');  
                    break;
                }
            }
        }
        
        else {
            ciphertext[i] = ch;
        }
    }

    ciphertext[i] = '\0';  
}
void decrypt(char *ciphertext, char *cipher_alphabet, char *plaintext) {
    char plain_alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    int i, j;

    for (i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (ch >= 'A' && ch <= 'Z') {
            for (j = 0; j < 26; j++) {
                if (ch == cipher_alphabet[j]) {
                    plaintext[i] = plain_alphabet[j];  
                    break;
                }
            }
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = ch - 'a' + 'A';  
            for (j = 0; j < 26; j++) {
                if (ch == cipher_alphabet[j]) {
                    plaintext[i] = plain_alphabet[j] + ('a' - 'A');  
                    break;
                }
            }
        }
        else {
            plaintext[i] = ch;
        }
    }

    plaintext[i] = '\0';  
}

int main() {
    char plaintext[100], ciphertext[100], decrypted_text[100];
    char cipher_alphabet[27]; 
    printf("Enter the 26-letter ciphertext alphabet (e.g., ZEBRASCDFGHIJKLMNOPQTUVWXY): ");
    scanf("%s", cipher_alphabet);
    if (strlen(cipher_alphabet) != 26) {
        printf("Error: The ciphertext alphabet must contain exactly 26 letters.\n");
        return 1;
    }
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    encrypt(plaintext, cipher_alphabet, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, cipher_alphabet, decrypted_text);
    printf("Decrypted plaintext: %s\n", decrypted_text);

    return 0;
}

