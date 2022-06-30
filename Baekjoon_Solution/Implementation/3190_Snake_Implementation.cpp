#include <iostream>
#include <queue>
#define L 1
#define D 3

std::queue<std::pair<int, int>> snake;
int turn[10001] = { 0, };
std::pair<int, int> direction[4] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int map[102][102] = { 0, };

int n;

int headRow, headCol, headDir;

int playTime;

bool move() {
	headRow += direction[headDir].first;
	headCol += direction[headDir].second;

	if (map[headRow][headCol] == 1) {
		return true;
	}

	if (map[headRow][headCol] != 2) {

		map[snake.front().first][snake.front().second] = 0;
		snake.pop();
	}
	map[headRow][headCol] = 1;
	snake.push({ headRow, headCol });

	return false;
}

void init() {
	headRow = 1;
	headCol = 1;
	headDir = 3;

	map[headRow][headCol] = 1;
	snake.push({ headRow, headCol });

	playTime = 0;

	for (int index = 0; index <= n + 1; index++) {
		map[index][0] = 1;
	}
	for (int index = 0; index <= n + 1; index++) {
		map[index][n + 1] = 1;
	}
	for (int index = 0; index <= n + 1; index++) {
		map[0][index] = 1;
	}
	for (int index = 0; index <= n + 1; index++) {
		map[n + 1][index] = 1;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	init();

	int appleNum;
	std::cin >> appleNum;

	int appleRow, appleCol;
	for (int count = 0; count < appleNum; count++) {
		std::cin >> appleRow >> appleCol;

		map[appleRow][appleCol] = 2;
	}

	int turnCnt;
	std::cin >> turnCnt;

	int nextTime;
	char nextDir;

	bool gameOver = false;
	for (; turnCnt > 0; turnCnt--) {
		std::cin >> nextTime >> nextDir;
		if (nextDir == 'L') {
			turn[nextTime] = L;
		}
		else if (nextDir == 'D') {
			turn[nextTime] = D;
		}
	}

	while (!gameOver) {
		gameOver = move();

		if (turn[++playTime] != 0) {
			headDir = (headDir + turn[playTime]) % 4;
		}
	}

	std::cout << playTime;

	return 0;
}