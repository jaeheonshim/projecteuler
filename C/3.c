#include <stdio.h>

int isprime(int);

int main() {
	long long num = 600851475143;
	long long largest = 0;
	for(long long i = 3; i * i < num; i += 2) {
		if(num % i == 0 && isprime(i)) largest = i;
	}

	printf("%d\n", largest);
}

int isprime(int n) {
	if(n % 2 == 0) return 0;
	for(int i = 3; i * i < n; i += 2) {
		if(n % i == 0) return 0;
	}
	return 1;
}
