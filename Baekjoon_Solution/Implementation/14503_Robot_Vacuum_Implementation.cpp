#include <iostream>
#define MAX_SIZE 52

std::pair<int, int> direction[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int n, m;

int curRow, curCol;
int curDir;

int map[MAX_SIZE][MAX_SIZE];

int cleanCnt;

void init() {
	for (int row = 0; row <= n + 1; row++) {
		for (int col = 0; col <= m + 1; col++) {
			map[row][col] = 1;
		}
	}
	cleanCnt = 0;
}

void step_1() {
	if (map[curRow][curCol] == 0) {
		cleanCnt++;
	}
	map[curRow][curCol] = 2;
}

bool step_2() {
	// step_2a
	for (int rotateCnt = 0; rotateCnt < 4; rotateCnt++) {
		curDir = (curDir + 3) % 4;
		if (map[curRow + direction[curDir].first][curCol + direction[curDir].second] == 0) {
			curRow += direction[curDir].first;
			curCol += direction[curDir].second;

			return true;
		}
	}
	if (map[curRow - direction[curDir].first][curCol - direction[curDir].second] == 1) {
		return false;
	}
	else {
		curRow -= direction[curDir].first;
		curCol -= direction[curDir].second;

		return true;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> m;

	init();

	std::cin >> curRow >> curCol >> curDir;
	
	curRow++;
	curCol++;

	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= m; col++) {
			std::cin >> map[row][col];
		}
	}

	bool running = true;
	while (running) {
		step_1();
		running = step_2();
	}

	std::cout << cleanCnt;
}