#include <iostream>
#define MAX 1000000000
using namespace std;

int t, n;
int files[500];
int sumFilesCost[500][500];
int mergeCost[500][500];

void get_sum_files_cost() {
	int sum = 0;
	for (int front = 0; front < n; front++) {
		for (int back = 0; back < n; back++) {
			if (front == back) {
				sumFilesCost[front][back] = files[front];
			}
			else {
				sumFilesCost[front][back] = sumFilesCost[front][back - 1] + files[back];
			}
		}
	}
}

void merge_file(int start, int end) {
	int min = MAX;

	for (int index = start; index < end; index++) {
		if (mergeCost[start][index] == 0) {
			merge_file(start, index);
		}
		if (mergeCost[index + 1][end] == 0) {
			merge_file(index + 1, end);
		}
		int sum = sumFilesCost[start][end] + mergeCost[start][index] + mergeCost[index + 1][end];

		if (min > sum) {
			min = sum;
		}
	}
	if (min == MAX) {
		min = 0;
	}
	mergeCost[start][end] = min;
}

void reset() {
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			sumFilesCost[row][col] = 0;
			mergeCost[row][col] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;


		for (int count = 0; count < n; count++) {
			cin >> files[count];
		}

		reset();
		get_sum_files_cost();

		merge_file(0, n - 1);
		cout << mergeCost[0][n - 1] << endl;

	}
}