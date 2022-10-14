#include <iostream>
using namespace std;

int n;
long long b;

long result[5][5] = { 0, };
long matrix[5][5] = { 0, };

void multiply_matrix(long mat1[5][5], long mat2[5][5]) {
	long temp[5][5] = { 0, };
	for (int row1 = 0; row1 < n; row1++) {
		for (int col2 = 0; col2 < n; col2++) {
			for (int row2 = 0, col1 = 0; row2 < n; row2++, col1++) {
				temp[row1][col2] += mat1[row1][col1] * mat2[row2][col2];
				temp[row1][col2] %= 1000;
			}
		}
	}
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			mat1[row][col] = temp[row][col];
		}
	}
}

void init() {
	for (int row = 0; row < n; row++) {
		result[row][row] = 1;
		matrix[row][row] = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> b;

	init();

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cin >> matrix[row][col];
		}
	}

	while (b > 0) {
		if (b % 2 == 1) {
			multiply_matrix(result, matrix);
		}
		multiply_matrix(matrix, matrix);
		b /= 2;
	}

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cout << result[row][col] << " ";
		}
		cout << endl;
	}
}