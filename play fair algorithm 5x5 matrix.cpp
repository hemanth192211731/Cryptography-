#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void create_matrix(char key[], char matrix[SIZE][SIZE]) {
    int flag[26] = {0};
    int k = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        char c = toupper(key[i]);
        if (c == 'J') c = 'I'; 
        if (!flag[c - 'A']) {
            matrix[k / SIZE][k % SIZE] = c;
            flag[c - 'A'] = 1;
            k++;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue; // Skip 'J'
        if (!flag[c - 'A']) {
            matrix[k / SIZE][k % SIZE] = c;
            flag[c - 'A'] = 1;
            k++;
        }
    }
}
void find_position(char matrix[SIZE][SIZE], char c, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encrypt(char *plaintext, char matrix[SIZE][SIZE], char *ciphertext) {
    int i = 0, row1, col1, row2, col2;

    while (plaintext[i] != '\0' && plaintext[i + 1] != '\0') {
        find_position(matrix, plaintext[i], &row1, &col1);
        find_position(matrix, plaintext[i + 1], &row2, &col2);

        if (row1 == row2) { // Same row
            ciphertext[i] = matrix[row1][(col1 + 1) % SIZE];
            ciphertext[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) { // Same column
            ciphertext[i] = matrix[(row1 + 1) % SIZE][col1];
            ciphertext[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else { // Rectangle swap
            ciphertext[i] = matrix[row1][col2];
            ciphertext[i + 1] = matrix[row2][col1];
        }

        i += 2;
    }

    ciphertext[i] = '\0';
}
void prepare_text(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        text[i] = toupper(text[i]);
        if (text[i] == 'J') text[i] = 'I'; // Treat 'J' as 'I'
    }
    for (int i = 0; i < len - 1; i += 2) {
        if (text[i] == text[i + 1]) {
            memmove(text + i + 1, text + i, len - i + 1);
            text[i + 1] = 'X';
            len++;
        }
    }

    if (len % 2 != 0) { 
        text[len] = 'X';
        text[len + 1] = '\0';
    }
}

int main() {
    char key[100], plaintext[100], ciphertext[100];
    char matrix[SIZE][SIZE];

    printf("Enter the keyword: ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    create_matrix(key, matrix);
    prepare_text(plaintext);
    encrypt(plaintext, matrix, ciphertext);

    printf("Encrypted ciphertext: %s\n", ciphertext);

    return 0;
}

