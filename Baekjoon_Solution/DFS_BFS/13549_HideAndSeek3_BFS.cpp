#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

int source, dest;

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
bool visit[MAX] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> source >> dest;

	pq.push({ 0, source });
	visit[source] = true;

	while (!pq.empty()) {
		int curCount = pq.top().first;
		int curPos = pq.top().second;
		pq.pop();
		
		if (curPos == dest) {
			std::cout << curCount << std::endl;
			break;
		}

		if (curPos * 2 < MAX && !visit[curPos * 2]) {
			pq.push({ curCount, curPos * 2 });
			visit[curPos * 2] = true;
		}
		if (curPos + 1 < MAX && !visit[curPos + 1]) {
			pq.push({ curCount + 1, curPos + 1 });
			visit[curPos + 1] = true;
		}
		if (curPos - 1 >= 0 && !visit[curPos - 1]) {
			pq.push({ curCount + 1, curPos - 1 });
			visit[curPos - 1] = true;
		}
	}
}