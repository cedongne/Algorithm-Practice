#include <iostream>
#include <queue>
#define MAX 1000000000

int rowSize, colSize;
int map[502][502];
int visit[502][502] = { 0, };

std::queue<std::pair<int, int>> q;

int route = 0;

void bfs() {
	while (!q.empty()) {
		std::pair<int, int> cur = q.front();
		q.pop();
        int nextRow = cur.first + 1;
        int nextCol = cur.second;
		if (map[nextRow][nextCol] < map[cur.first][cur.second]) {
			q.push({ nextRow, nextCol });
			visit[nextRow][nextCol]++;
		}
        nextRow = cur.first - 1;
        nextCol = cur.second;
		if (map[nextRow][nextCol] < map[cur.first][cur.second]) {
			q.push({ nextRow, nextCol });
			visit[nextRow][nextCol]++;
		}
        nextRow = cur.first;
        nextCol = cur.second + 1;
		if (map[nextRow][nextCol] < map[cur.first][cur.second]) {
			q.push({ nextRow, nextCol });
			visit[nextRow][nextCol]++;
		}
        nextRow = cur.first;
        nextCol = cur.second - 1;
		if (map[nextRow][nextCol] < map[cur.first][cur.second]) {
			q.push({ nextRow, nextCol });
			visit[nextRow][nextCol]++;
		}
	}

	std::cout << visit[rowSize][colSize];
}

void dfs(int row, int col) {
	if (row == rowSize&& col == colSize) {
		route++;
		return;
	}

	if (map[row + 1][col] < map[row][col]) {
		dfs(row + 1, col);
	}
	if (map[row - 1][col] < map[row][col]) {
		dfs(row - 1, col);
	}
	if (map[row][col + 1] < map[row][col]) {
		dfs(row, col + 1);
	}
	if (map[row][col - 1] < map[row][col]) {
		dfs(row, col - 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> rowSize >> colSize;

	for (int row = 0; row <= rowSize + 1; row++) {
		for (int col = 0; col <= colSize + 1; col++) {
			map[row][col] = MAX;
		}
	}

	for (int row = 1; row <= rowSize; row++) {
		for (int col = 1; col <= colSize; col++) {
			std::cin >> map[row][col];
		}
	}

//	q.push({ 1, 1 });
//	bfs();
	dfs(1, 1);
	std::cout << route;
}