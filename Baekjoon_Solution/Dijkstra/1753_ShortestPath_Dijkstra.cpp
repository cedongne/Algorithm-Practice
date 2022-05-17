#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 20001
#define INF 1000000000

std::vector<std::pair<int, int>> graph[MAX_SIZE];
int dist[MAX_SIZE];

std::priority_queue<std::pair<int, int>> pq;

int v, e;

void dijkstra(int startNode) {
	for (auto adj : graph[startNode]) {
		if (dist[adj.second] > adj.first) {
			dist[adj.second] = adj.first;
		}
		pq.push({ -adj.first, adj.second });
	}

	dist[startNode] = 0;

	while (!pq.empty()) {
		int distance = -pq.top().first;
		int nodeNum = pq.top().second;
		pq.pop();

		if (distance > dist[nodeNum]) {
			continue;
		}

		for (auto adj : graph[nodeNum]) {
			if (adj.first + distance < dist[adj.second]) {
				dist[adj.second] = adj.first + distance;
				pq.push({ -dist[adj.second], adj.second });
			}
		}
	}
}

void init() {
	for (int count = 1; count <= v; count++) {
		dist[count] = INF;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> v >> e;

	init();

	int startNode;
	int vert1, vert2, weight;

	std::cin >> startNode;
	
	for (int count = 0; count < e; count++) {
		std::cin >> vert1 >> vert2 >> weight;
		graph[vert1].push_back({ weight, vert2 });
	}

	dijkstra(startNode);

	for (int count = 1; count <= v; count++) {
		if (dist[count] == INF) {
			std::cout << "INF\n";
		}
		else {
			std::cout << dist[count] << "\n";
		}
	}
}