#include <stdio.h>

#define MAXLEN 100
#define TONUM(c) ((c) - '0')
#define TOA(i) ((i) + '0')

void reverse(char *s);
void add(char *, char *);
int getline(char *s, int maxline);
void printsum(char *s, int);

char sum[MAXLEN];

int main() {
    for(int i = 0; i < MAXLEN - 1; i++) {
        sum[i] = '0';
    }

    char temp[100];
    while(getline(temp, 100) > 0) {
        add(sum, temp);
    }

    printsum(sum, 10);
}

// add num to sum
void add(char *sump, char *nump) {
    char *sumpb = sump;
    reverse(sump);
    reverse(nump);
    int carry = 0;
    int sum;
    while(*nump != '\0') {
        sum = TONUM(*sump) + TONUM(*nump) + carry;
        carry = sum / 10;
        sum = sum % 10;
        *sump = TOA(sum);
        sump++;
        nump++;
    }
    while(carry > 0) {
        sum = TONUM(*sump) + carry;
        carry = sum / 10;
        sum = sum % 10;
        *sump++ = TOA(sum);
    }

    reverse(sumpb);
}

void reverse(char *s) {
    if(*s == '\0') return;
    char *t = s;
    while(*(t + 1)) t++;

    while(t > s) {
        char temp = *t;
        *t = *s;
        *s = temp;
        s++, t--;
    }
}

void printsum(char *s, int max) {
    while(*s == '0') s++;
    if(max > 0) {
        for(int i = 0; i < max; i++) {
            putchar(*s++);
        }
    } else {
        printf("%s\n", s);
    }
}

int getline(char *s, int maxline) {
    int i = 0, c;
    while(--maxline > 0 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        i++;
    }

    *s = '\0';
    return i;
}