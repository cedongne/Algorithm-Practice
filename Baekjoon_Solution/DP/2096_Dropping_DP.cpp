#include <iostream>

int n;

int board[3];

int minScore[2][3] = { 0, };
int maxScore[2][3] = { 0, };

int min(int idx1, int idx2) {
	if (minScore[0][idx1] < minScore[0][idx2]) {
		return idx1;
	}
	else {
		return idx2;
	}
}

int max(int idx1, int idx2) {
	if (maxScore[0][idx1] > maxScore[0][idx2]) {
		return idx1;
	}
	else {
		return idx2;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	for (int count = 1; count <= n; count++) {
		std::cin >> board[0] >> board[1] >> board[2];
		minScore[1][0] = minScore[0][min(0, 1)] + board[0];
		maxScore[1][0] = maxScore[0][max(0, 1)] + board[0];
		minScore[1][1] = minScore[0][min(min(0, 1), 2)] + board[1];
		maxScore[1][1] = maxScore[0][max(max(0, 1), 2)] + board[1];
		minScore[1][2] = minScore[0][min(1, 2)] + board[2];
		maxScore[1][2] = maxScore[0][max(1, 2)] + board[2];

		minScore[0][0] = minScore[1][0];
		maxScore[0][0] = maxScore[1][0];
		minScore[0][1] = minScore[1][1];
		maxScore[0][1] = maxScore[1][1];
		minScore[0][2] = minScore[1][2];
		maxScore[0][2] = maxScore[1][2];
	}

	std::cout << maxScore[0][max(max(0, 1), 2)] << " " << minScore[0][min(min(0, 1), 2)];
}