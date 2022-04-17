#include <iostream>
#include <queue>
#include <vector>

#define horizontal	1
#define diagonal	2
#define vertical	3

struct move {
	int row;
	int col;
	int direction;
};

std::queue<move> q;
std::pair<int, int> direction[3] = { {1, 0}, {1, 1}, {0, 1} };

int n;

int map[18][18];
int visit[18][18] = { 0, };

void bfs() {
	while (!q.empty()) {
		move cur = q.front();
		q.pop();
		if (cur.direction != vertical) {
			int nextRow = cur.row;
			int nextCol = cur.col + 1;
			if (map[nextRow][nextCol] == 0) {
				visit[nextRow][nextCol]++;
				q.push({ nextRow, nextCol, horizontal });
			}
		}
		int nextRow = cur.row + 1;
		int nextCol = cur.col + 1;
		if (map[nextRow][nextCol] == 0 && map[cur.row][nextCol] == 0 && map[nextRow][cur.col] == 0) {
			visit[nextRow][nextCol]++;
			q.push({ nextRow, nextCol, diagonal });
		}
		if (cur.direction != horizontal) {
			int nextRow = cur.row + 1;
			int nextCol = cur.col;
			if (map[nextRow][nextCol] == 0) {
				visit[nextRow][nextCol]++;
				q.push({ nextRow, nextCol, vertical });
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	for (int row = 0; row <= n + 1; row++) {
		for (int col = 0; col <= n + 1; col++) {
			map[row][col] = -1;
		}
	}

	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			std::cin >> map[row][col];
		}
	}

	q.push({ 1, 2, horizontal });
	visit[1][2] = 1;
	bfs();

	std::cout << visit[n][n];
}