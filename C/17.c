#include <stdio.h>
#include <math.h>

int ncharcount(int);

// zero, one, two, three, four, five, six, seven, eight, nine
static char singles[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};
// [null], ten, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
static char tens[] = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};
// [null], eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
static char exceptions[] = {0, 6, 6, 8, 8, 7, 7, 9, 8, 8};
// hundred
static char hundred = 7;
// thousand
static char thousand = 8;
// and
static char and = 3;

int main() {
    int sum = 0;
    for(int i = 1; i <= 1000; i++) {
        sum += ncharcount(i);
    }

    printf("%d\n", sum);
}

int ncharcount(int n) {
    int sum = n;
    int place = 1;
    int digit;
    int lookahead;

    while((sum /= 10) > 0) place++;
    while(place > 0) {
        digit = (n / (int) pow(10, place - 1)) % 10;

        if(place > 1)
            lookahead = ((n / (int) pow(10, place - 2)) % 10);

        if(place == 4) {
            sum += thousand + singles[digit];
        } else if(place == 3 && digit > 0) {
            sum += hundred + singles[digit];
        } else if(place == 2 && digit > 0) {
            if(sum > 0)
                sum += and;
            if(digit == 1 && lookahead > 0) {
                sum += exceptions[lookahead];
                place--;
            } else {
                sum += tens[digit];
            }
        } else if(place == 2 && lookahead > 0 && sum > 0) {
            sum += and;
        } else if(place == 1 && digit > 0) {
            sum += singles[digit];
        }

        place--;
    }

    return sum;
}