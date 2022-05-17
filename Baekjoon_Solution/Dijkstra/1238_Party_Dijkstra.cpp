#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 1001
#define INF 1000000000

int n, m, x;
std::vector<std::pair<int, int>> goGraph[MAX_SIZE];
std::vector<std::pair<int, int>> backGraph[MAX_SIZE];

std::priority_queue<std::pair<int, int>> q;

int goDistance[MAX_SIZE];
int backDistance[MAX_SIZE];

void dijkstra(int startNode, std::vector<std::pair<int, int>>* graph, int* distance) {
	for (auto adj : graph[startNode]) {
		q.push({ -adj.first, adj.second });
		if (distance[adj.second] > adj.first) {
			distance[adj.second] = adj.first;
		}
	}

	while (!q.empty()) {
		int curNode = q.top().second;
		int curDistance = -q.top().first;
		q.pop();

		if (distance[curNode] >= curDistance) {
			for (auto adj : graph[curNode]) {
				if (distance[adj.second] > curDistance + adj.first) {
					distance[adj.second] = curDistance + adj.first;

					q.push({ -distance[adj.second], adj.second });
				}
			}
		}
	}
}

void init() {
	for (int index = 1; index <= n; index++) {
		goDistance[index] = INF;
		backDistance[index] = INF;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> m >> x;
	
	init();

	int node1, node2, weight;
	for (int count = 0; count < m; count++)
	{
		std::cin >> node1 >> node2 >> weight;
		goGraph[node2].push_back({ weight, node1 });
		backGraph[node1].push_back({ weight, node2 });
	}

	dijkstra(x, goGraph, goDistance);
	dijkstra(x, backGraph, backDistance);

	goDistance[x] = 0;
	backDistance[x] = 0;

	int max = 0;
	for (int index = 1; index <= n; index++) {
		if (max < goDistance[index] + backDistance[index]) {
			max = goDistance[index] + backDistance[index];
		}
	}

	std::cout << max;
}