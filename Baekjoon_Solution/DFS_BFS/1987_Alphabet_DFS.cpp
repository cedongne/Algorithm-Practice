#include <iostream>
#include <vector>
#include <queue>

std::pair<int, int> direction[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int rowSize, colSize;

bool str[26] = { 0, };
char map[22][22];
bool visit[22][22];

int maxLength = 0;

void dfs(int row, int col, int length) {
	for (auto dir : direction) {
		int nextRow = row + dir.first;
		int nextCol = col + dir.second;

		if (visit[nextRow][nextCol]) {
			continue;
		}
		if (!str[map[nextRow][nextCol] - 'A']) {
			str[map[nextRow][nextCol] - 'A'] = true;
			dfs(nextRow, nextCol, length + 1);
			str[map[nextRow][nextCol] - 'A'] = false;
		}
	}
	if (maxLength < length) {
		maxLength = length;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> rowSize >> colSize;

	for (int row = 0; row <= rowSize + 1; row++) {
		for (int col = 0; col <= colSize + 1; col++) {
			visit[row][col] = true;
		}
	}

	for (int row = 1; row <= rowSize; row++) {
		for (int col = 1; col <= colSize; col++) {
			std::cin >> map[row][col];
			visit[row][col] = false;
		}
	}
	str[map[1][1] - 'A'] = true;
	dfs(1, 1, 1);

	std::cout << maxLength << std::endl;
}