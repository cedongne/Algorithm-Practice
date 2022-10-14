#include <iostream>
#include <string>
#include <vector>

std::vector<int> numbers;

int main() {
	int result;

	int num;
	char oper;

	int plusMinus = 1;

	for (scanf("%d", &result); scanf("%c", &oper), oper != 10;) {
		scanf("%d", &num);
		if (oper == '-') {
			plusMinus = -1;
		}
		result += plusMinus * num;
	}
	printf("%d\n", result);
}