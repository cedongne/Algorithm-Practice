#include <iostream>
#include <vector>
#include <queue>
#define MAX(a, b) ((a > b) ? a : b)

int t, n, k;
int buildings[1001];
int inDegree[1001];
std::vector<int> graph[1001];
std::queue<int> q;

int targetBuilding;
int spendingTime[1001];

void init() {
    for (int index = 0; index <= n; index++) {
        inDegree[index] = 0;
        graph[index].clear();
    }
    while (!q.empty()) {
        q.pop();
    }
}

void trace_prev() {
    for (int count = 1; count <= n; count++) {
        if (inDegree[count] == 0) {
            q.push(count);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (cur == targetBuilding) {

            break;
        }
        for (auto adj : graph[cur]) {
            if (spendingTime[adj] < spendingTime[cur] + buildings[adj]) {
                spendingTime[adj] = spendingTime[cur] + buildings[adj];
            }
            if ((--inDegree[adj]) == 0) {
                q.push(adj);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> t;
    for (int cases = 0; cases < t; cases++) {
        std::cin >> n >> k;

        init();

        for (int count = 1; count <= n; count++) {
            std::cin >> buildings[count];
            spendingTime[count] = buildings[count];
        }

        int firstBuild, secondBuild;
        for (int count = 1; count <= k; count++) {
            std::cin >> firstBuild >> secondBuild;
            graph[firstBuild].push_back(secondBuild);
            inDegree[secondBuild]++;
        }

        std::cin >> targetBuilding;

        trace_prev();

        std::cout << spendingTime[targetBuilding] << std::endl;
    }
}