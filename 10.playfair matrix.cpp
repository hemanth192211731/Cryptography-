#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void fillPlayfairMatrix(char matrix[SIZE][SIZE], const char *key);
void printMatrix(const char matrix[SIZE][SIZE]);
void prepareText(char *text);
void encryptPlayfair(const char *text, const char matrix[SIZE][SIZE], char *cipherText);
void decryptPlayfair(const char *cipherText, const char matrix[SIZE][SIZE], char *plainText);

int main() {
    char key[] = "MFHIK U NOPQ ZVWXY ELARG DSTBC"; 
    char matrix[SIZE][SIZE];
    char text[100], cipherText[100], decryptedText[100];
    fillPlayfairMatrix(matrix, key);
    printf("Playfair Matrix:\n");
    printMatrix(matrix);
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; 
    prepareText(text);
    encryptPlayfair(text, matrix, cipherText);
    cipherText[strlen(cipherText)] = '\0';
    printf("Encrypted Text: %s\n", cipherText);
    decryptPlayfair(cipherText, matrix, decryptedText);
    decryptedText[strlen(decryptedText)] = '\0';
    printf("Decrypted Text: %s\n", decryptedText);
    return 0;
}
void fillPlayfairMatrix(char matrix[SIZE][SIZE], const char *key) {
    int used[26] = {0};
    int row = 0, col = 0;
    for (int i = 0; key[i] && row < SIZE; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I'; 
        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            matrix[row][col++] = ch;
            used[ch - 'A'] = 1;
            if (col >= SIZE) {
                col = 0;
                row++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!used[i] && (char)(i + 'A') != 'J') {
            matrix[row][col++] = (char)(i + 'A');
            if (col >= SIZE) {
                col = 0;
                row++;
            }
        }
    }
}
void printMatrix(const char matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}
void prepareText(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        text[i] = toupper(text[i]);
        if (text[i] == 'J') text[i] = 'I'; 
    }
    for (int i = 0; i < len - 1; i++) {
        if (text[i] == text[i + 1]) {
            memmove(&text[i + 2], &text[i + 1], len - i);
            text[i + 1] = 'X';
            len++;
        }
    }
    if (len % 2 != 0) {
        text[len] = 'X';
        text[len + 1] = '\0';
    }
}
void encryptPlayfair(const char *text, const char matrix[SIZE][SIZE], char *cipherText) {
    int len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        for (row1 = 0; row1 < SIZE; row1++) {
            for (col1 = 0; col1 < SIZE; col1++) {
                if (matrix[row1][col1] == text[i]) break;
            }
            if (col1 < SIZE) break;
        }

        for (row2 = 0; row2 < SIZE; row2++) {
            for (col2 = 0; col2 < SIZE; col2++) {
                if (matrix[row2][col2] == text[i + 1]) break;
            }
            if (col2 < SIZE) break;
        }

        if (row1 == row2) {
            cipherText[i] = matrix[row1][(col1 + 1) % SIZE];
            cipherText[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            cipherText[i] = matrix[(row1 + 1) % SIZE][col1];
            cipherText[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            cipherText[i] = matrix[row1][col2];
            cipherText[i + 1] = matrix[row2][col1];
        }
    }
}
void decryptPlayfair(const char *cipherText, const char matrix[SIZE][SIZE], char *plainText) {
    int len = strlen(cipherText);
    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        for (row1 = 0; row1 < SIZE; row1++) {
            for (col1 = 0; col1 < SIZE; col1++) {
                if (matrix[row1][col1] == cipherText[i]) break;
            }
            if (col1 < SIZE) break;
        }

        for (row2 = 0; row2 < SIZE; row2++) {
            for (col2 = 0; col2 < SIZE; col2++) {
                if (matrix[row2][col2] == cipherText[i + 1]) break;
            }
            if (col2 < SIZE) break;
        }

        if (row1 == row2) {
            plainText[i] = matrix[row1][(col1 - 1 + SIZE) % SIZE];
            plainText[i + 1] = matrix[row2][(col2 - 1 + SIZE) % SIZE];
        } else if (col1 == col2) {
            plainText[i] = matrix[(row1 - 1 + SIZE) % SIZE][col1];
            plainText[i + 1] = matrix[(row2 - 1 + SIZE) % SIZE][col2];
        } else {
            plainText[i] = matrix[row1][col2];
            plainText[i + 1] = matrix[row2][col1];
        }
    }
}
