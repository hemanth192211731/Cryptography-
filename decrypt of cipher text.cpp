#include <stdio.h>
#include <string.h>
void affine_decrypt(char *ciphertext, int a_inv, int b, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char c = ciphertext[i];
        if (c >= 'A' && c <= 'Z') { // Uppercase letter
            plaintext[i] = (a_inv * ((c - 'A') - b + 26)) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') { // Lowercase letter
            plaintext[i] = (a_inv * ((c - 'a') - b + 26)) % 26 + 'a';
        } else {
            plaintext[i] = c; 
        }
    }
    plaintext[i] = '\0'; 
}

int main() {
    char ciphertext[100], plaintext[100];
    int a_inv = 9; 
    int b = 15; 
    printf("Enter the ciphertext: ");
    scanf("%s", ciphertext);
    affine_decrypt(ciphertext, a_inv, b, plaintext);
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}

