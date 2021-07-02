#include <stdio.h>
#include <ctype.h>

#define DATASIZE 1000

void readIntData(int *);
unsigned long long multAdjacentN(int *data, int pos);

int main() {
	int intdata[DATASIZE];
	readIntData(intdata);

	unsigned long long largest = 0;

	for(int i = 0; i <= DATASIZE - 13; i++) {
		unsigned long long product = multAdjacentN(intdata, i);
		if(product > largest) {
			largest = product;
		}
	}
	printf("%llu\n", largest);
}

unsigned long long multAdjacentN(int *data, int pos) {
	int i = pos;
	unsigned long long product = 1;
	while((i - pos) < 13) {
		product *= data[i++];
	}

	return product;
}

void readIntData(int *intdata) {
	int c;
	while((c = getchar()) != EOF) {
		if(isdigit(c)) *intdata++ = (c - '0');
	}
}
