#include <stdio.h>
#include <ctype.h>
void caesarCipher(char* text, int k) {
    char ch;
    int i = 0;
    k = k % 26;
    while (text[i] != '\0') {
        ch = text[i];
        if (isalpha(ch)) {
            if (isupper(ch)) {
                text[i] = ((ch - 'A' + k) % 26) + 'A';
            } else if (islower(ch)) {
                text[i] = ((ch - 'a' + k) % 26) + 'a';
            }
        }
        i++;
    }
}
int main() {
    char text[100];
    int k;
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter shift value (1-25): ");
    scanf("%d", &k);
    caesarCipher(text, k);
    printf("Encrypted text: %s", text);
    return 0;
}

