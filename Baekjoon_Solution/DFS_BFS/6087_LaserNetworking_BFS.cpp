#include <iostream>
#include <queue>

std::pair<int, int> direction[4] = { {0, 1}, {0, -1}, {1, 0}, {-1,0} };

std::queue<std::pair<int, int>> q;
int w, h;

int goalRow, goalCol;

int map[102][102] = { 0, };
int visit[102][102] = { 0, };

void init() {
	for (int row = 0; row <= h + 1; row++) {
		for (int col = 0; col <= w + 1; col++) {
			map[row][col] = '*';
			visit[row][col] = 10001;
		}
	}
}

void bfs() {
	while (!q.empty()) {
		int curRow = q.front().first;
		int curCol = q.front().second;
		visit[curRow][curCol] += 1;
		q.pop();

		for (auto dir : direction) {
			int nextRow = curRow + dir.first;
			int nextCol = curCol + dir.second;

			int tempRow = nextRow;
			int tempCol = nextCol;
			while (map[tempRow][tempCol] != '*' && visit[tempRow][tempCol] >= visit[curRow][curCol]) {
				q.push({ tempRow, tempCol });
				visit[tempRow][tempCol] = visit[curRow][curCol];
				tempRow += dir.first;
				tempCol += dir.second;
			}
		}
		visit[curRow][curCol] -= 1;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> w >> h;

	init();

	char c;
	for (int row = 1; row <= h; row++) {
		for (int col = 1; col <= w; col++) {
			std::cin >> c;
			map[row][col] = c;
			if (c == 'C') {
				q.push({ row, col });
			}
		}
	}
	goalRow = q.front().first;
	goalCol = q.front().second;
	q.pop();

	visit[q.front().first][q.front().second] = -1;
	bfs();

	std::cout << visit[goalRow][goalCol];
}

/* input
5 10
****C
.....
.***.
.**..
.**.*
.**..
.***.
.**..
.**.*
....C

6 3
C*...*
.*.*.*
...*.C

6 3
C....*
.*.*.*
...*.C
*/