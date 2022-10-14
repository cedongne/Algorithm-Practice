#include <stdio.h>

int t;

int caseCount;
int mod;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &caseCount, &mod);
		int num1 = 1;
		int num2 = 1;
		int index = 2;
		while (num1 != 0) {
			int temp = num2;
			num2 = num1;
			num1 = (temp + num2) % mod;
			index++;
		}

		int count = 1;
		long long temp = num2;
		for (; temp != 1; count++) {
			temp = (temp * num2) % mod;
		}
		printf("%d %d\n", caseCount, index * count);
	}
}