#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAXCOL 1000

int rows;
int *data[MAXCOL];

void loadDataStdin();
int maxpath();

int main() {
    loadDataStdin();

    printf("%d\n", maxpath());
}

int maxpath() {
    for(int i = rows - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            data[i][j] += MAX(data[i + 1][j], data[i + 1][j + 1]);
        }
    }

    return data[0][0];
}

void loadDataStdin() {
    int row = 0, col = 0;
    int digit, rescnt, c;

    for(int i = 0; i < MAXCOL; i++) {
        data[i] = malloc(sizeof(int) * MAXCOL);
    }

    while(row < MAXCOL && (c = getchar()) != EOF) {
        if(isdigit(c)) {
            digit = (c - '0');
            while(isdigit(c = getchar())) {
                digit = digit * 10 + (c - '0');
            }

            data[row][col++] = digit;
        }
        if(c == '\n') {
            row++;
            col = 0;
            rows++;
        }
    }

    rows++;
}