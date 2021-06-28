#include <stdio.h>

int ispalindrome(int);

int main() {
	int largest = 0;

	for(int i = 999; i > 0; i--) {
		for(int j = i; j > 0; j--) {
			if(i * j > largest && ispalindrome(i * j)) {
				largest = i * j;
			}
		}
	}

	printf("%d\n", largest);
}

int ispalindrome(int n) {
	int reversed = 0;
	int nc = n;
	while(nc > 0) {
		reversed = reversed * 10 + nc % 10;
		nc /= 10;
	}

	return reversed == n;
}
