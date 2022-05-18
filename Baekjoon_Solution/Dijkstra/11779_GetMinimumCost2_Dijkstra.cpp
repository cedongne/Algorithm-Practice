#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define MAX_SIZE 1001
#define INF 2000000001

int n, m;
int startNode, endNode;

std::priority_queue<std::pair<int, int>> q;
std::vector<std::pair<long long, int>> graph[MAX_SIZE];

std::pair<long long, int> path[MAX_SIZE];

void dijkstra(int startNode) {
    path[startNode].first = 0;
    for (auto adj : graph[startNode]) {
        q.push({ -adj.first, adj.second });
        if (path[adj.second].first > adj.first) {
            path[adj.second] = { adj.first, startNode };
        }
    }

    while (!q.empty()) {
        long long curDistance = -q.top().first;
        int curNodeNum = q.top().second;
        q.pop();

        if (path[curNodeNum].first >= curDistance) {
            for (auto adj : graph[curNodeNum]) {
                if (path[adj.second].first > curDistance + adj.first) {
                    path[adj.second] = { curDistance + adj.first, curNodeNum };

                    q.push({ -path[adj.second].first, adj.second });
                }
            }
        }
    }
}

void init() {
    for (int index = 1; index <= n; index++) {
        path[index] = { INF, 0 };
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n >> m;

    int node1, node2, weight;
    for (int count = 0; count < m; count++) {
        std::cin >> node1 >> node2 >> weight;
        graph[node1].push_back({ weight, node2 });
    }

    std::cin >> startNode >> endNode;

    init();
    dijkstra(startNode);

    std::vector<int> route;
    for (int trace = endNode; trace != 0; trace = path[trace].second) {
        route.push_back(trace);
    }

    std::cout << path[endNode].first << "\n" << route.size() << "\n";

    for (int index = route.size() - 1; index >= 0; index--) {
        std::cout << route[index] << " ";
    }
}