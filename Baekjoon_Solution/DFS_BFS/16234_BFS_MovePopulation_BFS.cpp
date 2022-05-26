#include <iostream>
#include <queue>

int map[52][52];
int visit[52][52];
std::queue<std::pair<int, int>> q;
std::queue<std::pair<int, int>> association;

std::pair<int, int> direction[4] = { {1, 0}, {-1, 0}, {0, 1}, {0,-1} };

int N, L, R;

int totalPopulation;
int totalCountryNum;

int dayCount = 1;

bool isChange = false;

bool in_range(int num, int min, int max) {
	return (num >= min && num <= max);
}

int abs(int num1, int num2) {
	return (num1 > num2) ? num1 - num2 : num2 - num1;
}

void bfs() {
	while (!q.empty()) {
		int curCol = q.front().first;
		int curRow = q.front().second;
		q.pop();
		association.push({ curCol, curRow });

		totalPopulation += map[curCol][curRow];
		totalCountryNum++;

		for (auto dir : direction) {
			int nextCol = curCol + dir.first;
			int nextRow = curRow + dir.second;
			if (map[curCol][curRow] == map[nextCol][nextRow]) {
				continue;
			}
			if (visit[nextCol][nextRow] < dayCount && in_range(abs(map[curCol][curRow], map[nextCol][nextRow]), L, R)) {
				q.push({ nextCol, nextRow });
				association.push({ nextCol, nextRow });
				visit[nextCol][nextRow] = dayCount;
			}
		}
	}
}

void init() {
	for (int row = 0; row <= N + 1; row++) {
		for (int col = 0; col <= N + 1; col++) {
			map[row][col] = 0;
			visit[row][col] = 2001;
		}
	}
}

void distribute_population() {
	int everagePopulation = totalPopulation / totalCountryNum;
	if (association.size() > 1) {
		isChange = true;
	}
	while (!association.empty()) {
		map[association.front().first][association.front().second] = everagePopulation;
		association.pop();
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> L >> R;

	init();
	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= N; col++) {
			std::cin >> map[row][col];
			visit[row][col] = 0;
		}
	}

	while (true) {
		isChange = false;

		for (int row = 1; row <= N; row++) {
			for (int col = 1; col <= N; col++) {
				if (visit[row][col] != dayCount) {
					int right = abs(map[row][col], map[row][col + 1]);
					int down = abs(map[row][col], map[row + 1][col]);
					if ((right < L || right > R) && (down < L || down > R)) {
						continue;
					}
					q.push({ row, col });
					visit[row][col] = dayCount;

					bfs();

					distribute_population();
					totalPopulation = 0;
					totalCountryNum = 0;
				}
			}
		}
		if (isChange == false) {
			std::cout << dayCount - 1;
			return 0;
		}
		dayCount++;
	}
	return 0;
}