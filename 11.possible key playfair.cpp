#include <stdio.h>
#include <math.h>
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
int main() {
    unsigned long long factorial25 = factorial(25);
    unsigned long long totalPossibleKeys = 26 * factorial25;
    double log2Keys = log2(26) + log2(factorial25);
    printf("Total possible keys: %llu\n", totalPossibleKeys);
    printf("Approximate power of 2: 2^%.0f\n", log2Keys);
    return 0;
}

