#include <stdio.h>

int main() {
	int i, j, sum = 0;
	for(i = 1, j = 2; j < 4e6; j += i, i = j - i) 
		if(j % 2 == 0) sum += j;
	printf("%d\n", sum);
}
