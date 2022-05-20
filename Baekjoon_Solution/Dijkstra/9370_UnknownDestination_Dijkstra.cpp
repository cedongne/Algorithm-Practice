#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 2001
#define INF 2000000000

int cases;

int n, m, t;
int s, g, h;

std::vector<std::pair<int, int>> graph[MAX_SIZE];

std::vector<int> endPoints;

std::priority_queue<std::pair<int, int>> q;
std::priority_queue<int> candidateQ;

int distance[MAX_SIZE];
int directDistance[MAX_SIZE] = { 0, };
int wayPoint1Distance[MAX_SIZE] = { 0, };
int wayPoint2Distance[MAX_SIZE] = { 0, };

void dijkstra(int startNode) {
	distance[startNode] = 0;
	for (auto adj : graph[startNode]) {
		q.push({ -adj.first, adj.second });
		if (distance[adj.second] > adj.first) {
			distance[adj.second] = adj.first;
		}
	}

	while (!q.empty()) {
		int curDistance = -q.top().first;
		int curNodeNum = q.top().second;
		q.pop();

		if (curDistance == distance[curNodeNum]) {
			for (auto adj : graph[curNodeNum]) {
				if (distance[adj.second] > curDistance + adj.first) {
					distance[adj.second] = curDistance + adj.first;

					q.push({ -distance[adj.second], adj.second });
				}
			}
		}
	}
}

void vector_init() {
	for (int index = 1; index <= n; index++) {
		graph[index].clear();
	}
	endPoints.clear();
}

void dist_init() {
	for (int index = 1; index <= n; index++) {
		distance[index] = INF;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> cases;

	while (cases--) {
		vector_init();
		std::cin >> n >> m >> t;
		std::cin >> s >> g >> h;

		int node1, node2, weight;
		int essentialEdgeWeight = INF;
		for (int count = 0; count < m; count++) {
			std::cin >> node1 >> node2 >> weight;
			if ((node1 == g && node2 == h) || (node1 == h && node2 == g)) {
				essentialEdgeWeight = weight;
			}

			graph[node1].push_back({ weight, node2 });
			graph[node2].push_back({ weight, node1 });
		}

		for (int count = 0; count < t; count++) {
			int endPoint;
			std::cin >> endPoint;
			endPoints.push_back(endPoint);
		}

		dist_init();
		dijkstra(s);

		for (auto endPoint : endPoints) {
			directDistance[endPoint] = distance[endPoint];
		}

		int wayPoint1Dist = distance[g];
		int wayPoint2Dist = distance[h];

		dist_init();
		dijkstra(g);

		for (auto endPoint : endPoints) {
			wayPoint1Distance[endPoint] = distance[endPoint];
		}

		dist_init();
		dijkstra(h);

		for (auto endPoint : endPoints) {
			wayPoint2Distance[endPoint] = distance[endPoint];
		}

		for (auto endPoint : endPoints) {
			if ((directDistance[endPoint] == wayPoint1Dist + essentialEdgeWeight + wayPoint2Distance[endPoint]) || (directDistance[endPoint] == wayPoint2Dist + essentialEdgeWeight + wayPoint1Distance[endPoint])) {
				candidateQ.push(-endPoint);
			}
		}

		while (!candidateQ.empty()) {
			std::cout << -candidateQ.top() << " ";
			candidateQ.pop();
		}
		std::cout << "\n";
	}
}