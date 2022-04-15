#include <iostream>
#include <vector>
#include <queue>

std::vector<int> map[1001];
bool visit[1001] = { 0, };
int n, m;

std::queue<int> q;

int componentCnt = 0;

void bfs() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto adj : map[cur]) {
			if (!visit[adj]) {
				q.push(adj);
				visit[adj] = true;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> m;

	int vtx1, vtx2;
	for (int edges = 0; edges < m; edges++) {
		std::cin >> vtx1 >> vtx2;
		map[vtx1].push_back(vtx2);
		map[vtx2].push_back(vtx1);
	}

	for (int index = 1; index <= n; index++) {
		if (visit[index] == 0) {
			q.push(index);
			visit[index] = true;
			bfs();
			componentCnt++;
		}
	}

	std::cout << componentCnt;
}