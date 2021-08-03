#include <stdio.h>

int add(int t[], int n[], int);

int main() {
    int len = 1;
    int init[1000] = {2};

    for(int i = 0; i < 999; i++) {
        len = add(init, init, len);
    }

    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += init[i];
    }

    printf("%d\n", sum);
}

/**
 * Add n to t
 */
int add(int t[], int n[], int nlen) {
    int carry = 0, i, sum;
    for(i = 0; i < nlen || carry > 0; i++) {
        sum = t[i] + n[i] + carry;
        t[i] = sum % 10;
        carry = sum / 10;
    }
    return i;
}