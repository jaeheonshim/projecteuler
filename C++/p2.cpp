#include <iostream>

int main() {
    long sum{ 0 };
    int a = 2;
    int b = 1;

    while(a <= 4'000'000) {
        if(a % 2 == 0) sum += a;

        a = a + b; 
        b = a - b;
    }

    std::cout << sum;

    return 0;
}