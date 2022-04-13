#include <iostream>
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
long long factorial[31] = { 1, };

void get_result(int num1, int num2) {
	long long result = 1;
	long long num = 1;
	int tmpMax = MAX(num1, num2 - num1);
	int tmpMin = MIN(num1, num2 - num1);
	for (int count = num2; count > tmpMax; count--) {
		result *= count;
	}
	for (int count = 1; count <= tmpMin; count++) {
		num *= count;
	}
	std::cout << (result / num) << "\n";
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	int t;

	std::cin >> t;
	int num1, num2;
	for (int cases = 0; cases < t; cases++) {
		std::cin >> num1 >> num2;

		get_result(num1, num2);
	}
}