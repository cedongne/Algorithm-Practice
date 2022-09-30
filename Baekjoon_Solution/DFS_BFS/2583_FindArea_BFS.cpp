#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::pair<int, int> direction[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int r, c, n;
int map[102][102] = { 0, };

std::queue<std::pair<int, int>> q;
std::vector<int> area_list;

void draw_square(int x1, int y1, int x2, int y2) {
	for (int row = x1; row < x2; row++) {
		for (int col = y1; col < y2; col++) {
			map[row][col] = 1;
		}
	}
}

int bfs() {
	int count = 1;
	while (!q.empty()) {
		int curRow = q.front().first;
		int curCol = q.front().second;
		map[curRow][curCol] = 1;
		q.pop();

		for (auto dir : direction) {
			int nextRow = curRow + dir.first;
			int nextCol = curCol + dir.second;

			if (nextRow >= 0 && nextRow < r && nextCol >= 0 && nextCol < c) {
				if (map[nextRow][nextCol] == 0) {
					q.push({ nextRow, nextCol });
					map[nextRow][nextCol] = 1;
					count++;
				}
			}
		}
	}

	return count;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> r >> c >> n;

	while (n > 0) {
		int x1, y1, x2, y2;
		std::cin >> y1 >> x1 >> y2 >> x2;
		draw_square(x1, y1, x2, y2);
		n--;
	}

	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			if (map[row][col] == 0) {
				q.push({ row, col });
				area_list.push_back(bfs());
				map[row][col] = 1;
			}
		}
	}

	std::sort(area_list.begin(), area_list.end());
	std::cout << area_list.size() << std::endl;
	for (auto ele : area_list) {
		std::cout << ele << " ";
	}
}