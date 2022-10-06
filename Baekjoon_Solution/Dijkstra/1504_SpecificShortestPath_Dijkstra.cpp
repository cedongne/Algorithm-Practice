#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000000

std::priority_queue<std::pair<int, int>> pq;
int map[801][801] = { 0, };

int N, E;
int essentialNode[2];

int distance[3][801];

void dijkstra(int startNode, int startTarget) {
	for (int index = 1; index <= N; index++) {
		if (map[startNode][index]) {
			pq.push({ -map[startNode][index], index });
			distance[startTarget][index] = map[startNode][index];
		}
	}
	distance[startTarget][startNode] = 0;

	while (!pq.empty()) {
		int curDistance = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (distance[startTarget][curNode] < curDistance) {
			continue;
		}

		for (int index = 1; index <= N; index++) {
			if (map[curNode][index] && distance[startTarget][index] > curDistance + map[curNode][index]) {
				distance[startTarget][index] = curDistance + map[curNode][index];
				pq.push({ -(distance[startTarget][index]), index });
			}
		}
	}
}

void init() {
	for (int count = 0; count < 3; count++) {
		for (int index = 1; index <= N; index++) {
			distance[count][index] = MAX;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> E;

	init();

	int node1, node2, weight;
	for (int count = 0; count < E; count++) {
		std::cin >> node1 >> node2 >> weight;
		map[node1][node2] = weight;
		map[node2][node1] = weight;
	}

	std::cin >> essentialNode[0] >> essentialNode[1];
	dijkstra(1, 0);
	dijkstra(essentialNode[0], 1);
	dijkstra(essentialNode[1], 2);

	int route1 = distance[0][essentialNode[0]] + distance[1][essentialNode[1]] + distance[2][N];
	int route2 = distance[0][essentialNode[1]] + distance[2][essentialNode[0]] + distance[1][N];

	int min = route1 < route2 ? route1 : route2;
	std::cout << (min < MAX ? min : -1) << std::endl;
}