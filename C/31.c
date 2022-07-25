#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PARTS 4

int coins[] = {1, 5, 10, 25};

int combinations(int amount, int depth);

int main() {
    int denomination;
    clock_t start, end;

    while(scanf("%d", &denomination) > 0) {
        start = clock();
        int c = combinations(denomination, 25);
        end = clock();

        printf("%d\n", c);
        printf("Time: %ld\n", end - start);
    }
}

int combinations(int amount, int coin) {
    if(amount == 0) return 1;

    int sum = 0;
    for(int i = 0; i < PARTS; i++) {
        if(coins[i] > coin) break;

        if(amount - coins[i] >= 0) {
            int result = combinations(amount - coins[i], coins[i]);
            sum += result;
        }
    }

    return sum;
}