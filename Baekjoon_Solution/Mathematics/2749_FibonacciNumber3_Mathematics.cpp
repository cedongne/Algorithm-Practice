#include <iostream>
#include <math.h>

int mod = 1000000;
/*
====== Pisano Period ======

- k(m) ≤ m^2 - 1
- k(2^n) = 3×2^(n-1)
- k(5^n) = 4×5^n
- k(2×5^n) = 6n
- n > 2, k(10^n) = 15×10^(n-1)
*/
int period = 15 * pow(10, 5);

long long n;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	n %= period;

	int num1 = 1;
	int num2 = 1;

	int count = 3;
	while (count++ <= n) {
		int temp = num2;
		num2 = num1;
		num1 = (temp + num2) % mod;
	}

	std::cout << num1 << std::endl;
}