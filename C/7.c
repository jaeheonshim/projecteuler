#include <stdio.h>

int isprime(int);

int main() {
	int i, j;
	for(i = 0, j = 3; i < 10000 - 1;) {
		j += 2;
		if(isprime(j)) {
			i++;
		}
	}

	printf("%d\n", j);
}


int isprime(int n) {
	if(n % 2 == 0) return 0;
	for(int i = 3; i * i <= n; i += 2) {
		if(n % i == 0) return 0;
	}

	return 1;
}
