#include <iostream>
#include <queue>

struct coordinate {
	int row;
	int col;
	bool RGSame;
};

std::pair<int, int> direction[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

char paint[102][102] = { 0, };
bool visit[102][102][2] = { 0, };
std::queue<coordinate> q;

int n;

int RGDiffAreaCnt = 0, RGSameAreaCnt = 0;

void bfs() {
	while (!q.empty()) {
		int curRow = q.front().row;
		int curCol = q.front().col;
		bool curRGSame = q.front().RGSame;
		q.pop();

		for (auto dir : direction) {
			int nextRow = curRow + dir.first;
			int nextCol = curCol + dir.second;
			if (visit[nextRow][nextCol][curRGSame]) {
				continue;
			}
			if (paint[curRow][curCol] == paint[nextRow][nextCol]) {
				q.push({ nextRow, nextCol, curRGSame });
				visit[nextRow][nextCol][curRGSame] = true;
			}
			if (curRGSame && paint[curRow][curCol] + paint[nextRow][nextCol] == 153) {
				q.push({ nextRow, nextCol, curRGSame });
				visit[nextRow][nextCol][curRGSame] = true;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	bool RGDiffCounting = false, RGSameCounting = false;

	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			std::cin >> paint[row][col];
		}
	}

	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			if (!visit[row][col][0]) {
				q.push({ row, col, false });
				visit[row][col][0] = true;
				RGDiffCounting = true;
			}
			if (!visit[row][col][1]) {
				q.push({ row, col, true });
				visit[row][col][1] = true;
				RGSameCounting = true;
			}
			bfs();
			if (RGDiffCounting) {
				RGDiffAreaCnt++;
				RGDiffCounting = false;
			}
			if (RGSameCounting) {
				RGSameAreaCnt++;
				RGSameCounting = false;
			}
		}
	}

	std::cout << RGDiffAreaCnt << " " << RGSameAreaCnt;
}