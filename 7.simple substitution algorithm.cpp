#include <stdio.h>
#include <string.h>

// Function to count character frequencies in the ciphertext
void countFrequencies(const char *ciphertext, int *freq) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 32 && ciphertext[i] <= 126) { // ASCII range for printable characters
            freq[(int)ciphertext[i]]++;
        }
    }
}

// Function to print the frequencies of characters
void printFrequencies(int *freq) {
    printf("Character frequencies in the ciphertext:\n");
    for (int i = 32; i <= 126; i++) { // Printable ASCII range
        if (freq[i] > 0) {
            printf("Character '%c': %d times\n", i, freq[i]);
        }
    }
}

int main() {
    char ciphertext[1000];  // Buffer to store user input
    int freq[127] = {0};    // Array to store frequencies of ASCII characters

    // Ask user for the ciphertext
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    // Count character frequencies
    countFrequencies(ciphertext, freq);

    // Print character frequencies
    printFrequencies(freq);

    return 0;
}


