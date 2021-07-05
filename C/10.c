#include <stdio.h>

int main() {
    long long sum = 2;

    for(long i = 3; i < 2000000; i += 2) {
        int j;
        for(j = 3; j * j <= i; j++) {
            if(i % j == 0) {
                break;
            }
        }

        if(j * j > i) {
            sum += i;
        }
    }

    printf("%lld\n", sum);
}