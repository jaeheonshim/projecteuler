#include <stdio.h>

void factorize(int);
int isprime(int);

static int lFactors[20] = {};

int main() {
	for(int i = 1; i <= 20; i++) {
		factorize(i);
	}

	long product = 1;
	for(int i = 0; i < 20; i++) {
		if(lFactors[i] > 0) {
			for(int j = 0; j < lFactors[i]; j++) {
				product *= i;
			}
		}
	}

	printf("%ld\n", product);
}

void factorize(int n) {
	int arrSize = n + 1;
	int pFactors[arrSize];
	for(int i = 0; i < arrSize; i++) {
		pFactors[i] = 0;
	}

	int nextPrime = 2;
	while(!isprime(n)) {
		while(n % nextPrime == 0) {
			pFactors[nextPrime]++;
			n /= nextPrime;
		}
		for(nextPrime = nextPrime + 1; !isprime(nextPrime); nextPrime += 1);
	}
	pFactors[n]++;

	for(int i = 0; i < arrSize; i++) {
		if(pFactors[i] > lFactors[i]) {
			lFactors[i] = pFactors[i];
		}
	}
}

int isprime(int n) {
	if(n % 2 == 0) return 0;
	for(int i = 3; i * i <= n; i += 2) {
		if(n % i == 0) return 0;
	}

	return 1;
}
