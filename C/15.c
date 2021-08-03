#include <stdio.h>
#include <math.h>

unsigned long long solve(int width);
// O(n^2) solution
int main() {
    printf("%llu\n", solve(20));
}

unsigned long long solve(int width) {
    unsigned long long solved[width + 1][width + 1];
    for(int i = 0; i < width + 1; i++) {
        for(int j = 0; j < width + 1; j++) {
            solved[i][j] = 0;
        }
    }

    for(int i = 0; i < width + 1; i++) {
        solved[i][0] = 1;
        solved[0][i] = 1;
    }

    for(int m = 1; m < width + 1; m++) {
        for(int n = 1; n < width + 1; n++) {
            solved[m][n] = solved[m][n - 1] + solved[m - 1][n];
        }
    }

    return solved[width][width];
}