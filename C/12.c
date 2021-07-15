#include <stdio.h>
#include <limits.h>

int countDivisors(int n);

int main() {
    long i;
    for(i = 1; countDivisors((i * (i + 1)) / 2) < 500; i++);
    printf("%ld\n", (i * (i + 1)) / 2);
}

int countDivisors(int n) {
    int c = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            c++;
        }
    }

    return c * 2;
}