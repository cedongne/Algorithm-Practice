#include <iostream>
#include <queue>
#define MAX 10000

std::pair<int, int> direction[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

std::queue<std::pair<int, int>> q;

int map[23][23];
int visit[23][23] = { 0, };
int dist[23][23] = { 0, };

int n;
int moveCnt;
int sharkSize;
int feadCnt;

int totalDist;

std::pair<int, int> nextPoint;
int minDist;

void init() {
	for (int row = 0; row <= n + 1; row++) {
		for (int col = 0; col <= n + 1; col++) {
			map[row][col] = MAX;
		}
	}

	sharkSize = 2;
	feadCnt = 0;
	moveCnt = 1;

	totalDist = 0;
	minDist = MAX;

	nextPoint = { MAX, MAX };
}

void bfs() {
	while (!q.empty()) {
		int curRow = q.front().first;
		int curCol = q.front().second;
		q.pop();

		if (minDist == dist[curRow][curCol]) {
			feadCnt++;
			moveCnt++;
			map[nextPoint.first][nextPoint.second] = 0;

			if (feadCnt == sharkSize) {
				feadCnt = 0;
				sharkSize++;
			}
			while (!q.empty()) {
				q.pop();
			}

			totalDist += dist[nextPoint.first][nextPoint.second];
			minDist = MAX;
			dist[nextPoint.first][nextPoint.second] = 0;

			q.push({ nextPoint.first, nextPoint.second });
			visit[nextPoint.first][nextPoint.second] = moveCnt;
			nextPoint = { MAX, MAX };
			continue;

		}

		for (auto dir : direction) {
			int nextRow = curRow + dir.first;
			int nextCol = curCol + dir.second;

			dist[nextRow][nextCol] = dist[curRow][curCol] + 1;

			if (visit[nextRow][nextCol] < moveCnt && map[nextRow][nextCol] <= sharkSize) {
				if (map[nextRow][nextCol] > 0 && map[nextRow][nextCol] < sharkSize) {
					minDist = dist[nextRow][nextCol];
					if (nextPoint.first == nextRow) {
						if (nextPoint.second > nextCol) {
							nextPoint.second = nextCol;
						}
					}
					else if (nextPoint.first > nextRow) {
						nextPoint = { nextRow, nextCol };
					}

				}
				q.push({ nextRow, nextCol });
				visit[nextRow][nextCol] = moveCnt;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	init();

	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			std::cin >> map[row][col];

			if (map[row][col] == 9) {
				q.push({ row, col });
				map[row][col] = 0;
				visit[row][col] = moveCnt;
			}
		}
	}

	bfs();

	std::cout << totalDist;
}