#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; 
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod; 
    }
    return result;
}
int isPrime(int p, int iterations) {
    if (p <= 1) return 0; 
    if (p <= 3) return 1; 
    if (p % 2 == 0 || p % 3 == 0) return 0; 
    
    for (int i = 0; i < iterations; i++) {
        int a = 2 + rand() % (p - 3);
        if (modExp(a, p - 1, p) != 1) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    srand(time(0)); 

    int number = 31; 
    int iterations = 5;
    
    if (isPrime(number, iterations)) {
        printf("%d is likely a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}

