#include <stdio.h>
#define LIMIT 1000000

void collatz(long long *);

// memoization not implemented because I am too lazy to write a map in C.

int main() {
    long long largestN = 0;
    int largest = 0;
    for(long i = (LIMIT / 2); i <= LIMIT; i++) {
        // we know for any number 0 <= n <= LIMIT / 2, there exists a number n * 2 for which the sequence will also be calculated. 
        // we know for any number n below  LIMIT / 2, a longer sequence exists, since the sequence for (n * 2) is guaranteed to be 
        // 1 greater than the sequence for (n). 
        // (This is because we know (n * 2) is immediately resolved to (n), thus making the sequence longer by one.)
        int c = 0;
        long long n = i;
        while(n != 1) {
            collatz(&n);
            c++;
        }

        if(c > largest) {
            largest = c;
            largestN = i;
        }
    }

    printf("%lld\n", largestN);
    putchar(EOF);
}

// questionable practice to use a pointer?
void collatz(long long *a) {
    if(*a % 2 == 0) {
        *a /= 2;
    } else {
        *a = 3 * *a + 1;
    }
}