// apparently there is a O(1) solution but I am lazy and bad at math so this is all you get.
//
#include <stdio.h>

#define SUMALL(n) ((n * (n - 1)) / 2)

long sum(long);

int main() {
	long sumSquares = 0;
	long squaredSum = SUMALL(100);
	for(int i = 1; i <= 100; i++) {
		sumSquares += i * i;
	}

	printf("%ld\n", (squaredSum * squaredSum) - sumSquares);
}

long sum(long t) {
	return (t * (t + 1)) / 2;
}
