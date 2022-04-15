#include <iostream>
#include <vector>
#define MAX 1000000000

int rowSize, colSize;
int map[502][502];
int visit[502][502];


int dfs(int row, int col) {
	if (visit[row][col] == -1) {
		return 0;
	}
	if (visit[row][col] > 0) {
		return visit[row][col];
	}

	if (row == rowSize && col == colSize) {
		return 1;
	}

	visit[row][col] = 0;

	int nextRow = row + 1;
	if (map[nextRow][col] && map[nextRow][col] < map[row][col]) {
		visit[row][col] += dfs(nextRow, col);
	}
	nextRow = row - 1;
	if (map[nextRow][col] && map[nextRow][col] < map[row][col]) {
		visit[row][col] += dfs(nextRow, col);
	}
	int nextCol = col + 1;
	if (map[row][nextCol] && map[row][nextCol] < map[row][col]) {
		visit[row][col] += dfs(row, nextCol);
	}
	nextCol = col - 1;
	if (map[row][nextCol] && map[row][nextCol] < map[row][col]) {
		visit[row][col] += dfs(row, nextCol);
	}
	if (visit[row][col] == 0) {
		visit[row][col] = -1;
		return 0;
	}
	else {
		return visit[row][col];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> rowSize >> colSize;

	for (int row = 1; row <= rowSize; row++) {
		for (int col = 1; col <= colSize; col++) {
			std::cin >> map[row][col];
		}
	}

	std::cout << dfs(1, 1);
}