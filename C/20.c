#include <stdio.h>

int main() {

}

int add(char *sumarr, char *numarr, int numSize) {
    char carry = 0;
    int i = 0;
    int sum;

    while(i < numSize || carry > 0) {
        sum = *(sumarr + i) + *(numarr + i) + carry;
        *sumarr = sum % sum;
        carry = sum / 10;
        i++;
    }

    return i;
}

