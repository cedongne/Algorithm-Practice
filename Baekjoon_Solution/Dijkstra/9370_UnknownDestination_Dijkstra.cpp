#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 2001
#define INF 1000000001

struct NodeInfo {
	int distance;
	int nodeNum;
	bool beyond;

	bool operator < (const NodeInfo& info) const {
		return distance > info.distance;
	}
};

int caseNum;
int n, m, t;
int s, g, h;

std::vector<std::pair<int, int>> graph[MAX_SIZE];
std::pair<int, bool> path[MAX_SIZE];
std::priority_queue<NodeInfo> q;

std::priority_queue<int> possibleDests;

std::vector<int> destCandidates;

bool check_beyond_essential_bridge(int node1, int node2) {
	return (node1 == g && node2 == h) || (node1 == h && node2 == g);
}

void dijkstra(int startNode) {
	path[startNode] = { 0, 0 };
	for (auto adj : graph[startNode]) {
		bool beyond = check_beyond_essential_bridge(startNode, adj.second);
		q.push({ adj.first, adj.second, beyond });
		if (path[adj.second].first > adj.first) {
			path[adj.second] = { adj.first, beyond };
		}
	}

	while (!q.empty()) {
		int curDistance = q.top().distance;
		int curNodeNum = q.top().nodeNum;
		bool beyond = q.top().beyond;
		q.pop();

		if (path[curNodeNum].first == curDistance) {
			for (auto adj : graph[curNodeNum]) {
				if (path[adj.second].first >= curDistance + adj.first) {
					bool nextBeyond = beyond || check_beyond_essential_bridge(curNodeNum, adj.second);
					path[adj.second] = { curDistance + adj.first, nextBeyond || path[adj.second].second};
					q.push({ path[adj.second].first, adj.second, path[adj.second].second });
				}
			}
		}
	}
}

void init() {
	for (int index = 1; index <= n; index++) {
		graph[index].clear();
		path[index] = { INF, false };
	}
	destCandidates.clear();
	destCandidates.resize(t);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> caseNum;
	for (int caseCnt = 0; caseCnt < caseNum; caseCnt++) {
		std::cin >> n >> m >> t;
		std::cin >> s >> g >> h;

		init();

		int node1, node2, weight;
		for (int count = 0; count < m; count++) {
			std::cin >> node1 >> node2 >> weight;
			graph[node1].push_back({ weight, node2 });
			graph[node2].push_back({ weight, node1 });
		}

		for (int count = 0; count < t; count++) {
			std::cin >> destCandidates[count];
		}

		dijkstra(s);

		for (auto candidate : destCandidates) {
			if (path[candidate].second) {
				possibleDests.push(-candidate);
			}
		}
		while(!possibleDests.empty()) {
			std::cout << -possibleDests.top() << " ";
			possibleDests.pop();
		}
		std::cout << "\n";
	}
}