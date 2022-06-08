#include <iostream>
#include <queue>
#define R	0
#define I	1
#define D	2

std::pair<int, int> direction[3] = { {0, 1}, {1, 1}, {1, 0} };
int map[18][18] = { 0, };

int n;

int wayCnt = 0;

void dfs(int row, int col, int dir) {
	if (row == n && col == n) {
		wayCnt++;
	}
	for (int nextDir = 0; nextDir < 3; nextDir++) {
		if ((nextDir == R && dir == D) || (nextDir == D && dir == R)) {
			continue;
		}
		int nextRow = row + direction[nextDir].first;
		int nextCol = col + direction[nextDir].second;
		if (nextRow == n + 1 || nextCol == n + 1 || map[nextRow][nextCol] == 1) {
			continue;
		}
		if (nextDir == I && map[row][nextCol] == 0 && map[nextRow][col] == 0) {
			dfs(nextRow, nextCol, I);
		}
		if (nextDir == R && map[nextRow][nextCol] == 0) {
			dfs(nextRow, nextCol, R);
		}
		if (nextDir == D && map[nextRow][nextCol] == 0) {
			dfs(nextRow, nextCol, D);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			std::cin >> map[row][col];
		}
	}
	dfs(1, 2, R);

	std::cout << wayCnt;
}