#include <stdio.h>
#include <string.h>
int mod_inverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; 
}
void affine_encrypt(char *plaintext, int a, int b, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char p = plaintext[i];
        if (p >= 'A' && p <= 'Z') { // Uppercase letter
            ciphertext[i] = ((a * (p - 'A') + b) % 26) + 'A';
        } else if (p >= 'a' && p <= 'z') { // Lowercase letter
            ciphertext[i] = ((a * (p - 'a') + b) % 26) + 'a';
        } else {
            ciphertext[i] = p; 
        }
    }
    ciphertext[i] = '\0';
}
void affine_decrypt(char *ciphertext, int a, int b, char *plaintext) {
    int i;
    int a_inv = mod_inverse(a, 26);
    if (a_inv == -1) {
        printf("Error: No modular inverse for a = %d under modulo 26. Decryption not possible.\n", a);
        return;
    }

    for (i = 0; ciphertext[i] != '\0'; i++) {
        char c = ciphertext[i];
        if (c >= 'A' && c <= 'Z') { // Uppercase letter
            plaintext[i] = (a_inv * ((c - 'A') - b + 26) % 26) + 'A';
        } else if (c >= 'a' && c <= 'z') { // Lowercase letter
            plaintext[i] = (a_inv * ((c - 'a') - b + 26) % 26) + 'a';
        } else {
            plaintext[i] = c; // Non-alphabet characters remain unchanged
        }
    }
    plaintext[i] = '\0'; // Null-terminate the plaintext
}

int main() {
    char plaintext[100], ciphertext[100];
    int a, b;

    // Get inputs from the user
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    printf("Enter the value of a (must be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);

    // Check if a is coprime with 26
    if (mod_inverse(a, 26) == -1) {
        printf("Error: The value of a is not coprime with 26. Please choose another value.\n");
        return 1;
    }

    // Encrypt the plaintext
    affine_encrypt(plaintext, a, b, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char decrypted_text[100];
    affine_decrypt(ciphertext, a, b, decrypted_text);
    printf("Decrypted plaintext: %s\n", decrypted_text);

    return 0;
}

